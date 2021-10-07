import 'dart:async';

import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:firebase_messaging/firebase_messaging.dart';
import 'package:flutter/services.dart';
import 'package:flutter_chat_app/models/MessagesModel.dart';
import 'package:flutter_chat_app/models/TokenModel.dart';
import 'package:flutter_chat_app/models/UserModel.dart';

class FirestoreService {
  final CollectionReference _usersCollectionReference =
      Firestore.instance.collection('users');
  final CollectionReference _messagesCollectionReference =
      Firestore.instance.collection('messages');
  final FirebaseMessaging _fcm = FirebaseMessaging();

  final StreamController<List<MessagesModel>> _chatMessagesController =
      StreamController<List<MessagesModel>>.broadcast();

  Future createUser(UserModel user) async {
    try {
      await _usersCollectionReference.document(user.id).setData(user.toJson());
    } catch (e) {
      // TODO: Find or create a way to repeat error handling without so much repeated code
      if (e is PlatformException) {
        return e.message;
      }

      return e.toString();
    }
  }

  Future getUser(String uid) async {
    try {
      var userData = await _usersCollectionReference.document(uid).get();

      return UserModel.fromData(userData.data);
    } catch (e) {
      // TODO: Find or create a way to repeat error handling without so much repeated code
      if (e is PlatformException) {
        return e.message;
      }

      return e.toString();
    }
  }

  Future getAllUsersOnce(String currentUserUID) async {
    try {
      var usersDocumentSnapshot =
          await _usersCollectionReference.getDocuments();
      String fcmToken = await _fcm.getToken();

      final tokenRef = _usersCollectionReference
          .document(currentUserUID)
          .collection('tokens')
          .document(fcmToken);
      await tokenRef.setData(
        TokenModel(token: fcmToken, createdAt: FieldValue.serverTimestamp())
            .toJson(),
      );
      if (usersDocumentSnapshot.documents.isNotEmpty) {
        return usersDocumentSnapshot.documents
            .map((snapshot) => UserModel.fromMap(snapshot.data))
            .where((mappedItem) => mappedItem.id != currentUserUID)
            .toList();
      }
    } catch (e) {
      // TODO: Find or create a way to repeat error handling without so much repeated code
      if (e is PlatformException) {
        return e.message;
      }

      return e.toString();
    }
  }

  Future createMessage(MessagesModel message) async {
    try {
      await _messagesCollectionReference.document().setData(message.toJson());
    } catch (e) {
      // TODO: Find or create a way to repeat error handling without so much repeated code
      if (e is PlatformException) {
        return e.message;
      }

      return e.toString();
    }
  }

  Stream listenToMessagesRealTime(String friendId, String currentUserId) {
    // Register the handler for when the posts data changes
    _requestMessages(friendId, currentUserId);
    return _chatMessagesController.stream;
  }

  void _requestMessages(String friendId, String currentUserId) {
    var messagesQuerySnapshot =
        _messagesCollectionReference.orderBy('createdAt', descending: true);

    messagesQuerySnapshot.snapshots().listen((messageSnapshot) {
      if (messageSnapshot.documents.isNotEmpty) {
        var messages = messageSnapshot.documents
            .map((snapshot) => MessagesModel.fromMap(snapshot.data))
            .where((element) =>
                (element.receiverId == friendId &&
                    element.senderId == currentUserId) ||
                (element.receiverId == currentUserId &&
                    element.senderId == friendId))
            .toList();

        _chatMessagesController.add(messages);
      }
    });
  }
}
