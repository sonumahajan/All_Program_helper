#!/bin/bash

my_function() {
    echo "$GLOBAL_VAR"
}

GLOBAL_VAR=1
# The value of GLOBAL_VAR is available to my_function
my_function

