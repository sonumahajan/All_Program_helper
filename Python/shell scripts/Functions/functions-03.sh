#!/bin/bash

function hello() {
    echo "Hello!"
    now
}

# This will cause an error as the "now()" function is not yet defined.
hello

function now() {
    echo "It's $(date +%r)"
}
