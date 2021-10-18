#!/bin/sh
# Author bellabeen
# Delete Backup DB 1 Week
# cron time -> 00 13  *  *  *
# TODO output log 00 01  *  *  * user sh /path/file.sh >> /path/example.log 2>&1

# Token
GROUP_ID=
BOT_TOKEN=

# TODO Append variable
txt_1="[REPORT - Finish Del DB TEDS TDM]"
txt_2=`date +"%d-%m-%Y %T"`

# Script execute
# Extension example = .dump
find /example/folder/ -type f -mtime +6 -name '*.extension' -execdir rm -- '{}' \;

sendNotif()
{
    echo "$txt_1"
    echo "$txt_2"
}

TEXT=$(sendNotif)

curl -s --data "text=$TEXT" --data "chat_id=$GROUP_ID" 'https://api.telegram.org/bot'$BOT_TOKEN'/sendMessage' > /dev/null
