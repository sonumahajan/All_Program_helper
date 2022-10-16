#!/bin/bash
usage() {
    cat <<EOM
Usage: $(basename $0) [int]
  Parameter:
    - int: Number of top results to return
  Examples:
    ./$(basename $0) 10
EOM
    exit 0
}

[ -z $1 ] && { usage; }

#find . -type f -print0 | xargs -0 ls -la | awk '{print int($5/1000) " KB\t" $9}' | sort -n -r -k1 | head -$1
find . -type f -ls | sort -k 7 -r -n | head -$1
