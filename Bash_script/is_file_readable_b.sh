#!/bin/bash

# to check if the specified file
# has read permission in bash scripting
# use [ -r FILE ]

curr_dir="$PWD"

# case file exists and is readable
file_name1="is_file_readable_b.sh"
full_path="$curr_dir/$file_name1"
if [ -r $full_path ]
then
    echo "$full_path is readable"
else
    echo "$full_path is not readable"
fi

# case file is not readable
file_name1="notreadable.sh"
full_path="$curr_dir/$file_name1"
if [ -r $full_path ]
then
    echo "$full_path is readable"
else
    echo "$full_path is not readable"
fi
