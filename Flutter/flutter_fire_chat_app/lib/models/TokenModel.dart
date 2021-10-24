import 'package:cloud_firestore/cloud_firestore.dart';

class TokenModel {
  String token;
  FieldValue createdAt;

  TokenModel({
    this.token,
    this.createdAt,
  });

  TokenModel.fromData(Map<String, dynamic> data)
      : token = data['token'],
        createdAt = data['createdAt'];

  static TokenModel fromMap(Map<String, dynamic> map) {
    if (map == null) return null;

    return TokenModel(
      token: map['token'],
      createdAt: map['createdAt'],
    );
  }

  Map<String, dynamic> toJson() {
    return {
      'token': token,
      'createdAt': createdAt,
    };
  }
}
