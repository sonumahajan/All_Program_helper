// GENERATED CODE - DO NOT MODIFY BY HAND

// **************************************************************************
// AutoRouteGenerator
// **************************************************************************

import 'package:flutter/material.dart';
import 'package:flutter/cupertino.dart';
import 'package:auto_route/auto_route.dart';
import 'package:flutter_chat_app/ui/views/startup/startup_view.dart';
import 'package:flutter_chat_app/ui/views/login/login_view.dart';
import 'package:flutter_chat_app/ui/views/signup/signup_view.dart';
import 'package:flutter_chat_app/ui/views/dashboard/dashboard_view.dart';
import 'package:flutter_chat_app/ui/views/chat/chat_view.dart';
import 'package:flutter_chat_app/models/UserModel.dart';

abstract class Routes {
  static const startupViewRoute = '/';
  static const loginViewRoute = '/login-view-route';
  static const signupViewRoute = '/signup-view-route';
  static const dashboardViewRoute = '/dashboard-view-route';
  static const chatViewRoute = '/chat-view-route';
  static const all = {
    startupViewRoute,
    loginViewRoute,
    signupViewRoute,
    dashboardViewRoute,
    chatViewRoute,
  };
}

class Router extends RouterBase {
  @override
  Set<String> get allRoutes => Routes.all;

  @Deprecated('call ExtendedNavigator.ofRouter<Router>() directly')
  static ExtendedNavigatorState get navigator =>
      ExtendedNavigator.ofRouter<Router>();

  @override
  Route<dynamic> onGenerateRoute(RouteSettings settings) {
    final args = settings.arguments;
    switch (settings.name) {
      case Routes.startupViewRoute:
        if (hasInvalidArgs<StartupViewArguments>(args)) {
          return misTypedArgsRoute<StartupViewArguments>(args);
        }
        final typedArgs =
            args as StartupViewArguments ?? StartupViewArguments();
        return MaterialPageRoute<dynamic>(
          builder: (context) => StartupView(key: typedArgs.key),
          settings: settings,
        );
      case Routes.loginViewRoute:
        return MaterialPageRoute<dynamic>(
          builder: (context) => LoginView(),
          settings: settings,
        );
      case Routes.signupViewRoute:
        return MaterialPageRoute<dynamic>(
          builder: (context) => SignupView(),
          settings: settings,
        );
      case Routes.dashboardViewRoute:
        return MaterialPageRoute<dynamic>(
          builder: (context) => DashboardView(),
          settings: settings,
        );
      case Routes.chatViewRoute:
        if (hasInvalidArgs<ChatViewArguments>(args, isRequired: true)) {
          return misTypedArgsRoute<ChatViewArguments>(args);
        }
        final typedArgs = args as ChatViewArguments;
        return MaterialPageRoute<dynamic>(
          builder: (context) => ChatView(typedArgs.friend),
          settings: settings,
        );
      default:
        return unknownRoutePage(settings.name);
    }
  }
}

// *************************************************************************
// Arguments holder classes
// **************************************************************************

//StartupView arguments holder class
class StartupViewArguments {
  final Key key;
  StartupViewArguments({this.key});
}

//ChatView arguments holder class
class ChatViewArguments {
  final UserModel friend;
  ChatViewArguments({@required this.friend});
}
