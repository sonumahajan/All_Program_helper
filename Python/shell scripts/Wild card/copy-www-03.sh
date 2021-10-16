#!/bin/bash

# This will loop through all the "html" files in the current directroy.
for FILE in *.html
do
    echo "Copying $FILE"
    cp $FILE /var/www-just-html
done
