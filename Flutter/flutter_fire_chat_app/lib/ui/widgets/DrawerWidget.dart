import 'package:flutter/material.dart';
import 'package:flutter_chat_app/ui/views/dashboard/dashboard_viewmodel.dart';

class DrawerWidget extends StatelessWidget {
  final DashboardViewModel model;
  DrawerWidget(this.model);

  @override
  Widget build(BuildContext context) {
    // final auth = Provider.of<AuthProvider>(context);
    return Drawer(
      child: Column(
        mainAxisAlignment: MainAxisAlignment.spaceBetween,
        crossAxisAlignment: CrossAxisAlignment.stretch,
        children: <Widget>[
          Container(
            decoration: BoxDecoration(
                gradient: LinearGradient(
                    begin: Alignment.topLeft,
                    end: Alignment.bottomRight,
                    stops: [0.3, 1],
                    colors: [Colors.green, Colors.blue])),
            height: 200,
            child: Center(
                child: Text(
              '${model.user.name}',
              style: TextStyle(
                color: Colors.white,
                fontSize: 25,
              ),
            )),
          ),
          Expanded(
            child: ListView(
              children: <Widget>[
                ListTile(
                  leading: Icon(Icons.people),
                  title: Text('Friends'),
                ),
                ListTile(
                  leading: Icon(Icons.settings),
                  title: Text('Settings'),
                ),
              ],
            ),
          ),

          // ListTile(leading: Icon(Icons.people),title: Text('Friends'),),

          FlatButton(
            color: Colors.red,
            textColor: Colors.white,
            child: Text('Logout'),
            materialTapTargetSize: MaterialTapTargetSize.shrinkWrap,
            onPressed: () => model.signOut(),
          )
        ],
      ),
    );
  }
}
