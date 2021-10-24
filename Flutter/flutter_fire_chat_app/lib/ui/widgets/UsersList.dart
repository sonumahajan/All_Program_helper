import 'package:flutter/material.dart';
import 'package:flutter_chat_app/models/UserModel.dart';
import 'package:flutter_chat_app/ui/widgets/UsersListViewModel.dart';
import 'package:stacked/stacked.dart';

class UsersList extends StatelessWidget {
  const UsersList({
    Key key,
    @required this.users,
  }) : super(key: key);

  final List<UserModel> users;

  @override
  Widget build(BuildContext context) {
    return ViewModelBuilder<UsersListViewModel>.nonReactive(
      builder: (context, model, child) => Container(
        margin: EdgeInsets.only(top: 20),
        child: ListView.separated(
          separatorBuilder: (_, __) => Divider(
            color: Colors.grey[400],
          ),
          itemCount: users.length,
          itemBuilder: (ctx, idx) => Padding(
            padding: const EdgeInsets.symmetric(horizontal: 8),
            child: ListTile(
              leading: CircleAvatar(
                child: Text('${users[idx].name[0]}'),
              ),
              trailing: IconButton(
                icon: Icon(
                  Icons.arrow_forward_ios,
                  size: 15,
                ),
                onPressed: () => model.navigateToChatScreen(users[idx]),
              ),
              title: Text('${users[idx].name}'),
              subtitle: Text('${users[idx].email}'),
              onTap: () => model.navigateToChatScreen(users[idx]),
            ),
          ),
        ),
      ),
      viewModelBuilder: () => UsersListViewModel(),
    );
  }
}
