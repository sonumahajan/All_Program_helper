import 'package:flutter_chat_app/app/locator.dart';
import 'package:flutter_chat_app/app/router.gr.dart';
import 'package:flutter_chat_app/services/auth_service.dart';
import 'package:stacked/stacked.dart';
import 'package:stacked_services/stacked_services.dart';

class SignupViewModel extends BaseViewModel {
  final AuthService _authService = locator<AuthService>();
  final DialogService _dialogService = locator<DialogService>();
  final NavigationService _navigationService = locator<NavigationService>();

  bool _hidePasswordValue = true;

  bool get hidePassword => _hidePasswordValue;

  void togglePasswordValue() {
    _hidePasswordValue = !_hidePasswordValue;
    notifyListeners();
  }

  Future signUp({String email, String password, String name}) async {
    setBusy(true);
    final result = await _authService.signUpWithEmail(email: email, password: password, name: name);

    if (result is bool) {
      if (result) {
        setBusy(false);
        _navigationService.replaceWith(Routes.dashboardViewRoute);
      } else {
        setBusy(false);

        await _dialogService.showDialog(
          title: 'Sign Up Failure',
          description: 'General sign up failure. Please try again later',
        );
      }
    } else {
      setBusy(false);
      await _dialogService.showDialog(
        title: 'Sign Up Failure',
        description: result,
      );
    }
  }
}
