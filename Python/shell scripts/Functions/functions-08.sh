#!/bin/bash

my_function() {
    GLOBAL_VAR=1
}

# GLOBAL_VAR not available yet.
echo "GLOBAL_VAR value BEFORE my_function called: $GLOBAL_VAR"

my_function

# GLOBAL_VAR is NOW available
echo "GLOBAL_VAR value AFTER my_function called: $GLOBAL_VAR"
