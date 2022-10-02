import 'package:flutter_chat_app/services/firebase_push_notification_serice.dart';
import 'package:flutter_chat_app/services/firestore_service.dart';
import 'package:injectable/injectable.dart';
import 'package:stacked_services/stacked_services.dart';
import 'package:flutter_chat_app/services/auth_service.dart';

@module
abstract class ServicesModule {
  @lazySingleton
  NavigationService get navigationService;
  @lazySingleton
  DialogService get dialogService;
  @lazySingleton
  AuthService get authService;
  @lazySingleton
  FirestoreService get firestoreService;
  @lazySingleton
  FirebasePushNotificationService get pushNotificationService;
}
