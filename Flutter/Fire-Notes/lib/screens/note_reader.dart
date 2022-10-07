import 'package:flutter/material.dart';
import 'package:notesappfirebase/style/app_style.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:notesappfirebase/widgets/note_card.dart';
import 'package:notesappfirebase/style/app_style.dart';

class NoteReaderScreen extends StatefulWidget {
  NoteReaderScreen(this.doc, {Key? key}) : super(key: key);

  QueryDocumentSnapshot doc;
  @override
  State<NoteReaderScreen> createState() => _NoteReaderScreenState();
}

class _NoteReaderScreenState extends State<NoteReaderScreen> {
  @override
  Widget build(BuildContext context) {
    int colorId = widget.doc['color_id'];

    return Scaffold(
      backgroundColor: AppStyle.cardColor[colorId],
      appBar: AppBar(
        backgroundColor: AppStyle.cardColor[colorId],
        elevation: 0.0,
      ),
      body: Padding(
          padding: const EdgeInsets.all(20.0),
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.start,
            children: [
              Text(
                widget.doc["note_title"],
                style: AppStyle.mainTile,
              ),
              const SizedBox(
                height: 4.0,
              ),
              Text(
                widget.doc["creation_date"],
                style: AppStyle.dateTitle,
              ),
              const SizedBox(
                height: 28.0,
              ),
              Text(
                widget.doc["note_content"],
                style: AppStyle.mainContent,
                overflow: TextOverflow.visible,
              )
            ],
          )),
    );
  }
}
