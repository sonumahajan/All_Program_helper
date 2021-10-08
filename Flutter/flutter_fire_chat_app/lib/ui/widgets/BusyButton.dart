import 'package:flutter/material.dart';

/// A button that shows a busy indicator in place of title
class BusyButton extends StatefulWidget {
  final bool busy;
  final String title;
  final Function onPressed;
  final bool enabled;
  const BusyButton(
      {@required this.title, this.busy = false, @required this.onPressed, this.enabled = true});

  @override
  _BusyButtonState createState() => _BusyButtonState();
}

class _BusyButtonState extends State<BusyButton> {
  @override
  Widget build(BuildContext context) {
    return GestureDetector(
      onTap: widget.onPressed,
      child: InkWell(
        child: Card(
          elevation: 10,
          child: AnimatedContainer(
            height: widget.busy ? 60 : 60,
            width: widget.busy ? 60 : 300,
            duration: const Duration(milliseconds: 300),
            alignment: Alignment.center,
            padding: EdgeInsets.symmetric(
                horizontal: widget.busy ? 10 : 15, vertical: widget.busy ? 10 : 10),
            decoration: BoxDecoration(
              color: widget.enabled ? Colors.purple : Colors.grey[300],
              borderRadius: BorderRadius.circular(5),
            ),
            child: !widget.busy
                ? Text(
                    widget.title,
                    style: TextStyle(color: Colors.white),
                  )
                : CircularProgressIndicator(
                    strokeWidth: 2, valueColor: AlwaysStoppedAnimation<Color>(Colors.black)),
          ),
        ),
      ),
    );
  }
}
