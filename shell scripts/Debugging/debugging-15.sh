#!/bin/bash -x

PS4='+ ${BASH_SOURCE}:${LINENO}:${FUNCNAME[0]}() '

debug() {
  echo "Executing: $@"
  $@
}

debug ls

