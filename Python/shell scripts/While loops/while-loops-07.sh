#!/bin/bash

while true
do
  read -p "1: Show disk usage.  2: Show uptime. " CHOICE
  case "$CHOICE" in
    1)
      df -h
      ;;
    2)
      uptime
      ;;
    *) 
      break
      ;;
  esac
done

