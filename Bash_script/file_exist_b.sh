#!/bin/bash

# Deprecated method
# using [-a FILE ]

# example 1
echo "EXAMPLE 1"
curr_dir="$PWD"
file_name="file_exist_b.sh"
full_path="$curr_dir/$file_name"

# when file exists
if [ -a "$full_path" ]
then
    echo "$file_name - File exists."
else
    echo "$file_name - File does not exist."
fi

# when file does not exist
file_name="doesnotexist.sh"
full_path="$curr_dir/$file_name"

if [ -a "$full_path" ]
then
    echo "$file_name - File exists."
else
    echo "$file_name - File does not exist."
fi

# Preferred method
# [ -e FILE ]

echo "EXAMPLE 2"
file_name="file_exist_b.sh"
full_path="$curr_dir/$file_name"

# when file exists
if [ -e "$full_path" ]
then
    echo "$file_name - File exists."
else
    echo "$file_name - File does not exist."
fi

# when file does not exist
file_name="doesnotexist.sh"
full_path="$curr_dir/$file_name"

if [ -e "$full_path" ]
then
    echo "$file_name - File exists."
else
    echo "$file_name - File does not exist."
fi
