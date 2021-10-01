#!/bin/bash

read -p "Enter y or n: " ANSWER

case "$ANSWER" in
    [yY]*)
        echo "You answered yes."
        ;;
   *)
        echo "You answered something else."
        ;;
esac
