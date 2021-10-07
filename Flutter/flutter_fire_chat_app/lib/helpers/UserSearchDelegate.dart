import 'package:flutter/material.dart';
import 'package:flutter_chat_app/models/UserModel.dart';
import '../ui/widgets/UsersList.dart';


class UserSearchDelegate extends SearchDelegate<String> {
  UserSearchDelegate({this.users});
  List<UserModel> users;
  @override
  List<Widget> buildActions(BuildContext context) {
    return [
      IconButton(
        icon: Icon(Icons.clear),
        onPressed: () {
          query = '';
        },
      )
    ];
  }

  @override
  Widget buildLeading(BuildContext context) {
    return IconButton(
      icon: AnimatedIcon(
          icon: AnimatedIcons.menu_arrow, progress: transitionAnimation),
      onPressed: () {
        close(context, null);
      },
    );
  }

  @override
  Widget buildResults(BuildContext context) {
    // nothing todo for now
  }

  @override
  Widget buildSuggestions(BuildContext context) {
    List<UserModel> searcUsers = query.isEmpty
        ? users
        : users
            .where((i) =>
                i.name.toLowerCase().contains(query) ||
                i.email.toLowerCase().contains(query))
            .toList();
    if (searcUsers.length == 0) {
      return Center(
        child: Text('No users found'),
      );
    }
    return UsersList(users: searcUsers);
  }
}
