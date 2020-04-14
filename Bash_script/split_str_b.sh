#!/bin/bash

# split string with single character
# delimter(s) in bash using IFS

# 1. Set IFS to the delimiter you would
# want. IFS='<delimiter>' IFS is an internal
# variable that determines how bash recognizes
# word boundaries.
# The default value of IFS is white space.

# 2. Read your string to a variable with options
# -ra. syntax:  read -ra ARR <<< "$str"

# now you have your string split by
# the delimter (set in IFS) stored
# in array ARR. ARR is just array name.
# Any string literal that is valid could
# be used as an array name

# 3. You may now access the tokens split
# into an array using bash for loop

str="Learn to split a string in bash scripting"

# example 1
IFS=' ' # space is set as delimiter
read -ra ADDR <<< "$str" # str is read into an array as tokens separated by IFS

for i in "${ADDR[@]}"
do
    echo "$i"
done

# example 2
str="Learn-to-split-a-string-in-bash-scripting"

IFS='-'
read -ra ADDR <<< "$str"

for i in "${ADDR[@]}"
do
    echo "$i"
done

# example 3
str="LearnABCtoABCSplitABCaABCString"
delimiter=ABC
s=$str$delimiter

echo "----------------"

array=()
while [[ $s ]]
do
    array+=( "${s%%"$delimiter"*}" )
    s=${s#*"$delimiter"}
done
declare -p array

# parameter-expansions are used
# expansion             description
# ${parameter%%word}    Remove the longest matching suffix pattern
# ${parameter#word}     Remove the shortest matching prefix pattern

