import 'package:flutter/material.dart';
import 'package:bubble/bubble.dart';

class ChatBubble extends StatelessWidget {
  const ChatBubble({
    Key key,
    @required this.isSent,
    @required this.message,
  }) : super(key: key);

  final bool isSent;
  final String message;

  @override
  Widget build(BuildContext context) {
    return Bubble(
      margin: isSent
          ? BubbleEdges.only(top: 10, right: 20)
          : BubbleEdges.only(top: 10, left: 20),
      padding: BubbleEdges.all(15),
      elevation: 5,
      nipRadius: 5,
      nipWidth: 30,
      nipHeight: 10,
      alignment: isSent ? Alignment.topRight : Alignment.topLeft,
      nip: isSent ? BubbleNip.rightBottom : BubbleNip.leftTop,
      color: isSent ? Colors.blue : Colors.grey[200],
      child: Text(
        message,
        style: TextStyle(color: isSent ? Colors.white : Colors.black),
      ),
    );
  }
}
