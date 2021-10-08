import 'package:emoji_picker/emoji_picker.dart';
import 'package:flutter/material.dart';
// import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:flutter_chat_app/models/UserModel.dart';
// import 'package:provider/provider.dart';
import 'package:flutter_chat_app/ui/views/chat/chat_viewmodel.dart';
import 'package:flutter_chat_app/ui/widgets/MessagesList.dart';
import 'package:stacked/stacked.dart';
import 'package:basic_utils/basic_utils.dart';

// import '../models/UserModel.dart';
// import '../providers/ChatProvider.dart';
// import '../../widgets/MessagesList.dart';

class ChatView extends StatelessWidget {
  static const routeName = '/chat';
  ChatView(this.friend);
  final UserModel friend;
  final TextEditingController _messageBodyController = TextEditingController();
  final FocusNode _messageFocus = FocusNode();
  @override
  Widget build(BuildContext context) {
    Widget buildChatMessages(model, friendId) {
      if (model.isBusy) {
        return Center(
          child: CircularProgressIndicator(),
        );
      } else {
        if (model.messages.length == 0) {
          return Expanded(
            child: Center(
              child: Image.asset('assets/images/empty_inbox.jpg', height: 200),
            ),
          );
        }

        return MessagesList(messages: model.messages, friendId: friend.id);
      }
    }

    return ViewModelBuilder<ChatViewModel>.reactive(
      onModelReady: (model) => model.listenToMessages(friend.id),
      builder: (context, model, child) {
        return Scaffold(
          backgroundColor: Color(0xffF2F8FD),
          appBar: AppBar(
            iconTheme: IconThemeData(color: Colors.black54),
            elevation: 0,
            backgroundColor: Colors.transparent,
            title: Text(
              friend.name,
              style: TextStyle(color: Colors.black54, fontSize: 20),
            ),
          ),
          body: Column(
            crossAxisAlignment: CrossAxisAlignment.stretch,
            mainAxisAlignment: MainAxisAlignment.spaceBetween,
            children: <Widget>[
              buildChatMessages(model, friend.id),
              SizedBox(height: 20),
              Container(
                color: Colors.white,
                child: Row(
                  children: <Widget>[
                    IconButton(
                      icon: Icon(Icons.tag_faces),
                      onPressed: () {
                        _messageFocus.unfocus();
                        model.showEmojiPicker();
                      },
                    ),
                    IconButton(
                      icon: Icon(Icons.attach_file),
                      onPressed: () {},
                    ),
                    Expanded(
                      child: TextField(
                        focusNode: _messageFocus,
                        onTap: () {
                          if (model.isShowEmojiPicker) {
                            model.showEmojiPicker();
                          }
                        },
                        controller: _messageBodyController,
                        decoration: InputDecoration(
                          border: InputBorder.none,
                          hintText: 'Send Message',
                        ),
                      ),
                    ),
                    IconButton(
                      onPressed: () {
                        if (_messageBodyController.text.isEmpty) {
                          return;
                        }
                        model.sendMessage(_messageBodyController.text,
                            friend.id, friend.name);
                        _messageBodyController.clear();
                      },
                      icon: Icon(
                        Icons.send,
                        color: Colors.green,
                      ),
                    )
                  ],
                ),
              ),
              model.isShowEmojiPicker
                  ? EmojiPicker(
                      rows: 3,
                      columns: 7,
                      selectedCategory: Category.SMILEYS,
                      buttonMode: ButtonMode.MATERIAL,
                      onEmojiSelected: (item, category) {
                        _messageBodyController.text =
                            StringUtils.addCharAtPosition(
                                _messageBodyController.text,
                                item.emoji,
                                _messageBodyController.text.length);
                      },
                    )
                  : Container()
            ],
          ),
        );
      },
      viewModelBuilder: () => ChatViewModel(),
    );
  }
}
