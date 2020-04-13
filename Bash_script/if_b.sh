#!/bin/bash

# if statement is used
# for conditional branching
# in the sequential flow of
# execution of statements

# if statement can accept options
# to perform a specific task.
# these options are used for file
# operations, string operations, etc.

if [ "hello" == "hello" ]
then
    echo "true condition"
else
    echo "false condition"
fi


if [ "hello" == "bello" ] && [ "hello" == "hello" ]
then
    echo "true condition"
else
    echo "false condition"
fi

if [[ "hello" == "bello"  ||  "hello" == "hello" ]]
then
    echo "true condition"
else
    echo "false condition"
fi

# check if string has zero length
if [ -z "" ]
then
    echo "string has zero length"
else
    echo "string has length greater than zero"
fi

if [ -z "not zero" ]
then
    echo "string has zero length"
else
    echo "string has length greater than zero"
fi

# check if file size is greater than zero
curr_dir=$PWD
file_path=$PWD/if_b.sh
echo $file_path

if [ -s $file_path ]
then
    echo "size of '$file_path' is greater than zero"
else
    echo "size of '$file_path' is zero"
fi
