#!/bin/bash

# SED stands for stream editor.

# This stream-oriented editor
# was created exclusively for
# executing scripts.

# Thus, all the input you feed
# into it passes through and
# goes to STDOUT and it does not
# change the input file.

# Example

TRY_FILE="sed_content.txt"

# check if sed_content.txt exist
until [ -e "$TRY_FILE" ]
do
    echo "Please add contents"
    # recommend type in
    # >>> first line
    # >>> sezond line
    # >>> third line
    sleep 2
    vim $TRY_FILE
done

# after sed_content.txt is modified
# invoke sed

# delete all lines with sed
# first method
cat $TRY_FILE | sed 'd'

# second method
sed -e 'd' $TRY_FILE

# sed Addresses
# The sed also supports addresses.
# Addresses are either particular
# locations in a file or a range
# or a range where a particular
# editing command should be applied.
# When sed encounters no addresses,
# it performs its operations on
# every line in the file

echo "Remove the first line"
cat $TRY_FILE | sed '1d' | more

echo "Remove from first to third"
cat $TRY_FILE | sed '1,3d' | more

echo "Remove the third"
cat $TRY_FILE | sed '3,2d' | more
# NOTICE that sed does not work in reverse

echo "Remove everything except from 2 to 3"
cat $TRY_FILE | sed '2,3!d' | more

echo "Remove first, steps over 2"
cat $TRY_FILE | sed '1~2d' | more

# USE the same technique for print <p>
# example
echo "Print the even lines"
cat $TRY_FILE | sed '2~2p' | more
