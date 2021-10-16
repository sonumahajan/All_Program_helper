#!/bin/bash

my_function() {
    local LOCAL_VAR=1
    echo "LOCAL_VAR can be accessed inside of the function: $LOCAL_VAR"
}

my_function

# LOCAL_VAR is not available outside of the function.
echo "LOCAL_VAR can NOT be accessed outside of the function: $LOCAL_VAR"
