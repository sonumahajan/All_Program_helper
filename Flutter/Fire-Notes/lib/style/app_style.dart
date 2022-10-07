import 'package:flutter/material.dart';
// ignore: depend_on_referenced_packages
import 'package:google_fonts/google_fonts.dart';

class AppStyle {
  static Color mainColor = const Color(0xFF000633);
  static Color AppBarColor = Color.fromARGB(255, 36, 43, 98);
  static Color accentColor = const Color(0xFF0065FF);
  static Color bgColor = const Color(0xFFe2e2ff);

  static List<Color> cardColor = [
    Colors.white,
    Colors.red.shade100,
    Colors.pink.shade100,
    Colors.orange.shade100,
    Colors.yellow.shade100,
    Colors.green.shade100,
    Colors.blue.shade100,
    Colors.blueGrey.shade100,
  ];

  static TextStyle mainTile =
      GoogleFonts.roboto(fontSize: 18.0, fontWeight: FontWeight.bold);
  static TextStyle mainContent =
      GoogleFonts.nunito(fontSize: 16.0, fontWeight: FontWeight.normal);
  static TextStyle dateTitle =
      GoogleFonts.roboto(fontSize: 13.0, fontWeight: FontWeight.w500);
}
