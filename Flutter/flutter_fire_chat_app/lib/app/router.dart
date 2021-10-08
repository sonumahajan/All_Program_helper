import 'package:auto_route/auto_route_annotations.dart';
import 'package:flutter_chat_app/ui/views/chat/chat_view.dart';
import 'package:flutter_chat_app/ui/views/dashboard/dashboard_view.dart';
import 'package:flutter_chat_app/ui/views/login/login_view.dart';
import 'package:flutter_chat_app/ui/views/signup/signup_view.dart';
import 'package:flutter_chat_app/ui/views/startup/startup_view.dart';

@MaterialAutoRouter()
class $Router {
  @initial
  StartupView startupViewRoute;
  LoginView loginViewRoute;
  SignupView signupViewRoute;
  DashboardView dashboardViewRoute;
  ChatView chatViewRoute;
}
