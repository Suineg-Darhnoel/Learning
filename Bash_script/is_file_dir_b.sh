#!/bin/bash

# to check if the spcecified file
# is a directory in bash scripting
# use [ -d FILE ]

curr_dir="$PWD"
# When file is a directory
file_name=$curr_dir
if [ -d $file_name ]
then
    echo "$file_name is a directory"
else
    echo "$file_name is not a directory"
fi

# When file is not a directory
file_name="$curr_dir/is_file_dir_b.sh"
if [ -d $file_name ]
then
    echo "$file_name is a directory"
else
    echo "$file_name is not a directory"
fi

# # check if argument passed to function
# is a directory

check_if_directory () {
    if [ -d "$1" ]
    then
        echo "$1 exists and is a directory"
    else
        echo "$1 is not a directory."
    fi
}

file_name1=$curr_dir
file_name2="$curr_dir/is_file_dir_b.sh"
check_if_directory $file_name1
check_if_directory $file_name2
