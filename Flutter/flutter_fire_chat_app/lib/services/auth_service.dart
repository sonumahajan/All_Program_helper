import 'package:firebase_auth/firebase_auth.dart';
import 'package:flutter/foundation.dart';
import 'package:flutter_chat_app/app/locator.dart';
import 'package:flutter_chat_app/models/UserModel.dart';
import 'package:flutter_chat_app/services/firestore_service.dart';

class AuthService {
  final FirebaseAuth _firebaseAuth = FirebaseAuth.instance;
  final FirestoreService _firestoreService = locator<FirestoreService>();

  UserModel _currentUser;
  UserModel get currentUser => _currentUser;

  Future loginWithEmail({
    @required String email,
    @required String password,
  }) async {
    try {
      var authResult = await _firebaseAuth.signInWithEmailAndPassword(
        email: email,
        password: password,
      );
      await _populateCurrentUser(authResult.user);
      return authResult.user != null;
    } catch (e) {
      return e.message;
    }
  }

  Future signUpWithEmail({
    @required String email,
    @required String password,
    @required String name,
  }) async {
    try {
      var authResult = await _firebaseAuth.createUserWithEmailAndPassword(
        email: email,
        password: password,
      );

      // create a new user profile on firestore
      _currentUser = UserModel(
        id: authResult.user.uid,
        email: email,
        name: name,
      );

      await _firestoreService.createUser(_currentUser);

      return authResult.user != null;
    } catch (e) {
      return e.message;
    }
  }

  Future<bool> isUserLoggedIn() async {
    var user = await _firebaseAuth.currentUser();
    if (user != null) {
      await _populateCurrentUser(user);
    }
    return user != null;
  }

  Future _populateCurrentUser(FirebaseUser user) async {
    if (user != null) {
      _currentUser = await _firestoreService.getUser(user.uid);
    }
  }

  void logOut() {
    _firebaseAuth.signOut();
  }
}
