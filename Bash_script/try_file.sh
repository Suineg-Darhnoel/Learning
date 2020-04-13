#!/bin/bash

for file in *.sh
do
    test -f "$file" || continue
    echo "Working on $file"
done
