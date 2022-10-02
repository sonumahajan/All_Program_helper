import 'package:flutter/material.dart';
import 'package:flutter_chat_app/app/locator.dart';
import 'package:stacked_services/stacked_services.dart';

import 'app/router.gr.dart';

void main() {
  setupLocator();
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      title: 'FireChat',
      initialRoute: Routes.startupViewRoute,
      onGenerateRoute: Router().onGenerateRoute,
      navigatorKey: locator<NavigationService>().navigatorKey,
    );
  }
}

// class MainApp extends StatelessWidget {
//   @override
//   Widget build(BuildContext context) {
//     final auth = Provider.of<AuthProvider>(context, listen: false);
//     return StreamBuilder<FirebaseUser>(
//         stream: auth.isAuth,
//         builder: (context, snapshot) {
//           if (snapshot.connectionState == ConnectionState.waiting) {
//             return Center(
//               child: CircularProgressIndicator(),
//             ); // Splash screen will be here
//           } else {
//             if (snapshot.hasData) {
//               return HomeScreen(snapshot.data);
//             }
//             return LoginScreen();
//           }
//         });
//   }
// }
