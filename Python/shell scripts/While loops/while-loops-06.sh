#!/bin/bash

FS_NUM=1
grep xfs /etc/fstab | while read FS MP REST
do
  echo "${FS_NUM}: file system: ${FS}"
  echo "${FS_NUM}: mount point: ${MP}"
  ((FS_NUM++))
done
