import 'package:flutter/material.dart';
import 'package:flutter_chat_app/ui/views/login/login_viewmodel.dart';
import 'package:flutter_chat_app/ui/widgets/BusyButton.dart';
import 'package:stacked/stacked.dart';
// import './SignupScreen.dart';
// import '../providers/AuthProvider.dart';

class LoginView extends StatelessWidget {
  final TextEditingController _emailController = TextEditingController();
  final TextEditingController _passwordController = TextEditingController();
  final FocusNode _emailFocus = FocusNode();
  final FocusNode _passwordFocus = FocusNode();

  void _fieldFocusChange(BuildContext context, FocusNode currentFocus, FocusNode nextFocus) {
    currentFocus.unfocus();
    FocusScope.of(context).requestFocus(nextFocus);
  }

  @override
  Widget build(BuildContext context) {
    return ViewModelBuilder<LoginViewModel>.reactive(
      builder: (context, model, child) => Scaffold(
        backgroundColor: Colors.white,
        appBar: AppBar(
          backgroundColor: Colors.transparent,
          elevation: 0,
          title: Text(
            'Login',
            style: TextStyle(color: Colors.black, fontSize: 30),
          ),
          centerTitle: true,
        ),
        body: SingleChildScrollView(
          child: Column(
            children: <Widget>[
              Image.asset(
                'assets/images/splash.jpg',
                height: 300,
                width: 300,
              ),
              Card(
                elevation: 3,
                margin: EdgeInsets.symmetric(horizontal: 20),
                child: Padding(
                  padding: const EdgeInsets.symmetric(vertical: 10),
                  child: TextField(
                    textInputAction: TextInputAction.next,
                    focusNode: _emailFocus,
                    onEditingComplete: () =>
                        _fieldFocusChange(context, _emailFocus, _passwordFocus),
                    style: TextStyle(fontSize: 20, color: Colors.blueGrey),
                    enabled: !model.isBusy,
                    controller: _emailController,
                    decoration: InputDecoration(
                      focusedBorder: InputBorder.none,
                      border: InputBorder.none,
                      prefixIcon: Icon(
                        Icons.email,
                        color: Colors.blueGrey,
                      ),
                    ),
                  ),
                ),
              ),
              SizedBox(height: 20),
              Card(
                elevation: 3,
                margin: EdgeInsets.symmetric(horizontal: 20),
                child: Padding(
                  padding: const EdgeInsets.symmetric(vertical: 10),
                  child: TextField(
                    textInputAction: TextInputAction.done,
                    focusNode: _passwordFocus,
                    onEditingComplete: () => model.login(
                      email: _emailController.text,
                      password: _passwordController.text,
                    ),
                    style: TextStyle(fontSize: 20, color: Colors.blueGrey),
                    obscureText: model.hidePassword,
                    enabled: !model.isBusy,
                    controller: _passwordController,
                    decoration: InputDecoration(
                      focusedBorder: InputBorder.none,
                      border: InputBorder.none,
                      prefixIcon: Icon(
                        Icons.vpn_key,
                        color: Colors.blueGrey,
                      ),
                      suffixIcon: IconButton(
                        onPressed: () => model.togglePasswordValue(),
                        icon: Icon(
                          model.hidePassword ? Icons.enhanced_encryption : Icons.remove_red_eye,
                          color: Colors.blueGrey,
                        ),
                      ),
                    ),
                  ),
                ),
              ),
              SizedBox(height: 50),
              BusyButton(
                onPressed: () => model.login(
                  email: _emailController.text,
                  password: _passwordController.text,
                ),
                busy: model.isBusy,
                enabled: !model.isBusy,
                title: 'Log in',
              ),
              Center(
                  child: Padding(
                padding: const EdgeInsets.only(top: 20),
                child: Text('Or'),
              )),
              FlatButton(
                onPressed: () => model.navigateToSignUp(),
                child: Text('Create an Account!'),
                textColor: Colors.blue,
              )
            ],
          ),
        ),
      ),
      viewModelBuilder: () => LoginViewModel(),
    );
  }
}
