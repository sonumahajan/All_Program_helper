#!/bin/bash

debug() {
  echo "Executing: $@"
  $@
}

debug ls

