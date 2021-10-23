#!/bin/sh
# Check Folder Empty
# cron time -> 10 00  *  *  *
# TODO output log 00 01  *  *  * user sh /path/file.sh >> /path/example.log 2>&1

# # Import credentials form config file
# . .././.env

# Testing Testing Bot
# GROUP_ID=
# BOT_TOKEN=

# Token
GROUP_ID=
BOT_TOKEN=

# TODO Append variable
txt_1='[FOLDER is Not Empty!] -'
txt_2=`date +"%d-%m-%Y %T"`
txt_3='[FOLDER is Empty!] -'
c="${txt_1} ${txt_2}"
d="${txt_3} ${txt_2}"

# PATH
PATH="/example/folder/"

sendNotif() {
if [ "0" != "$(ls -A $PATH | wc -l)" ]; then
    echo "${c}"
else
    echo "${d}"
fi
}

TEXT=$(sendNotif)
curl -s --data "text=$TEXT" --data "chat_id=$GROUP_ID" 'https://api.telegram.org/bot'$BOT_TOKEN'/sendMessage' > /dev/null
