class MessagesModel {
  String receiverId;
  String senderId;
  String senderName;
  String receiverName;
  String messageBody;
  int createdAt;

  MessagesModel({
    this.receiverId,
    this.senderId,
    this.messageBody,
    this.createdAt,
    this.senderName,
    this.receiverName,
  });

  MessagesModel.fromData(Map<String, dynamic> data)
      : receiverId = data['receiverId'],
        senderId = data['senderId'],
        senderName = data['senderName'],
        receiverName = data['receiverName'],
        messageBody = data['messageBody'],
        createdAt = data['createdAt'];

  static MessagesModel fromMap(Map<String, dynamic> map) {
    if (map == null) return null;

    return MessagesModel(
      receiverId: map['receiverId'],
      senderId: map['senderId'],
      senderName: map['senderName'],
      receiverName: map['receiverName'],
      messageBody: map['messageBody'],
      createdAt: map['createdAt'],
    );
  }

  Map<String, dynamic> toJson() {
    return {
      'receiverId': receiverId,
      'senderId': senderId,
      'senderName': senderName,
      'receiverName': receiverName,
      'messageBody': messageBody,
      'createdAt': createdAt,
    };
  }
}
