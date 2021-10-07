class UserModel {
  String id;
  String name;
  String email;

  UserModel({this.id, this.name, this.email});

  UserModel.fromData(Map<String, dynamic> data)
      : id = data['id'],
        name = data['name'],
        email = data['email'];

  static UserModel fromMap(Map<String, dynamic> map) {
    if (map == null) return null;

    return UserModel(
      id: map['id'],
      name: map['name'],
      email: map['email'],
    );
  }

  Map<String, dynamic> toJson() {
    return {
      'id': id,
      'name': name,
      'email': email,
    };
  }
}
