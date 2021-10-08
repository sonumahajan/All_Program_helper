// GENERATED CODE - DO NOT MODIFY BY HAND

// **************************************************************************
// InjectableConfigGenerator
// **************************************************************************

import 'package:flutter_chat_app/services/services.dart';
import 'package:flutter_chat_app/services/auth_service.dart';
import 'package:stacked_services/stacked_services.dart';
import 'package:flutter_chat_app/services/firebase_push_notification_serice.dart';
import 'package:flutter_chat_app/services/firestore_service.dart';
import 'package:get_it/get_it.dart';

void $initGetIt(GetIt g, {String environment}) {
  final servicesModule = _$ServicesModule();
  g.registerLazySingleton<AuthService>(() => servicesModule.authService);
  g.registerLazySingleton<DialogService>(() => servicesModule.dialogService);
  g.registerLazySingleton<FirebasePushNotificationService>(
      () => servicesModule.pushNotificationService);
  g.registerLazySingleton<FirestoreService>(
      () => servicesModule.firestoreService);
  g.registerLazySingleton<NavigationService>(
      () => servicesModule.navigationService);
}

class _$ServicesModule extends ServicesModule {
  @override
  AuthService get authService => AuthService();
  @override
  DialogService get dialogService => DialogService();
  @override
  FirebasePushNotificationService get pushNotificationService =>
      FirebasePushNotificationService();
  @override
  FirestoreService get firestoreService => FirestoreService();
  @override
  NavigationService get navigationService => NavigationService();
}
