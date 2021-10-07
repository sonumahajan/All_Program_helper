import 'package:flutter/material.dart';
import 'package:flutter_chat_app/ui/views/startup/startup_viewmodel.dart';
import 'package:stacked/stacked.dart';

class StartupView extends StatelessWidget {
  const StartupView({Key key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return ViewModelBuilder<StartupViewModel>.reactive(
      onModelReady: (model) => model.handleStartUpLogic(),
      builder: (context, model, child) => Scaffold(
          backgroundColor: Colors.white,
          body: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: <Widget>[
              Hero(tag: 'splash', child: Image.asset('assets/images/splash.gif')),
              Text(
                'Flutter Fire Chat',
                style: TextStyle(fontSize: 30),
              ),
            ],
          )),
      viewModelBuilder: () => StartupViewModel(),
    );
  }
}
