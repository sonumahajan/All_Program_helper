import 'package:flutter/material.dart';
import 'package:flutter_chat_app/ui/views/dashboard/dashboard_viewmodel.dart';
import 'package:stacked/stacked.dart';
// import 'package:flutter_chat_app/models/UserModel.dart';
// import 'package:provider/provider.dart';

// import '../providers/ChatProvider.dart';
import '../../widgets/DrawerWidget.dart';
import '../../widgets/UsersList.dart';
import '../../../helpers/UserSearchDelegate.dart';

class DashboardView extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return ViewModelBuilder<DashboardViewModel>.reactive(
      builder: (context, model, child) {
        return Scaffold(
          drawer: DrawerWidget(model),
          appBar: AppBar(
            iconTheme: IconThemeData(color: Colors.black54),
            elevation: 0,
            backgroundColor: Colors.transparent,
            title: Text(
              'Hi, ${model.user.name}',
              style: TextStyle(color: Colors.black54, fontSize: 20),
            ),
            actions: <Widget>[
              IconButton(
                icon: Icon(Icons.search),
                onPressed: () =>
                    showSearch(context: context, delegate: UserSearchDelegate(users: model.data)),
              )
            ],
          ),
          body: model.isBusy ? LinearProgressIndicator() : UsersList(users: model.data),
        );
      },
      viewModelBuilder: () => DashboardViewModel(),
    );
  }
}
