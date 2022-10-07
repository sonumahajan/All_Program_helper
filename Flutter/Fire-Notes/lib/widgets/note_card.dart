import 'package:flutter/material.dart';
// ignore: depend_on_referenced_packages
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:notesappfirebase/style/app_style.dart';

Widget noteCard(Function()? onTap, QueryDocumentSnapshot doc) {
  return InkWell(
    onTap: onTap,
    child: Container(
      padding: const EdgeInsets.all(8.0),
      margin: const EdgeInsets.all(8.0),
      decoration: BoxDecoration(
        color: AppStyle.cardColor[doc['color_id']],
        borderRadius: BorderRadius.circular(8.0),
      ),
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          Text(
            doc["note_title"],
            style: AppStyle.mainTile,
          ),
          const SizedBox(
            height: 4.0,
          ),
          Text(
            doc["creation_date"],
            style: AppStyle.dateTitle,
          ),
          const SizedBox(
            height: 8.0,
          ),
          Text(
            doc["note_content"],
            style: AppStyle.mainContent,
            overflow: TextOverflow.ellipsis,
          ),
        ],
      ),
    ),
  );
}
