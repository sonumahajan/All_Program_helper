import 'package:flutter_chat_app/app/locator.dart';
import 'package:flutter_chat_app/app/router.gr.dart';
import 'package:flutter_chat_app/models/UserModel.dart';
import 'package:stacked/stacked.dart';
import 'package:stacked_services/stacked_services.dart';

class UsersListViewModel extends BaseViewModel {
  NavigationService _navigationService = locator<NavigationService>();

  void navigateToChatScreen(UserModel friend) {
    _navigationService.navigateTo(
      Routes.chatViewRoute,
      arguments: ChatViewArguments(friend: friend),
    );
  }
}
