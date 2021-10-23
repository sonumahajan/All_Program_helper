#!/bin/bash

my_function() {
    echo "$GLOBAL_VAR"
}

# The value of GLOBAL_VAR is NOT available to my_function since GLOBAL_VAR was defined after my_function was called.
my_function
GLOBAL_VAR=1

