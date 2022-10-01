#!bin/bash
clear
SAVEIFS=$IFS
IFS=$(echo -en "\n\b")
folder=/etc/NetworkManager/system-connections
echo "--------------------------------------------------------------"
echo "             Here is your all wifi with password"
echo "--------------------------------------------------------------"
for file in $(ls -1 $folder); do
	echo "---------------------------------------"
	name=`sudo cat "$folder/$file" | grep ssid=`
	echo "Wifi Name: ${name:5}"
	pass=`sudo cat "$folder/$file" | grep psk=`
	echo "Password: ${pass:4}"
done
echo "--------------------------------------------------------------"
echo "            By https://github.com/sonumahajan "
echo "--------------------------------------------------------------"
IFS=$SAVEIFS
