#!/bin/bash

# # in bash, an array
# is not a collection of
# similar elements, since
# bash does not discriminate
# string from a number,
# an array can contain a mix
# of strings and numbers.

# Bash array declaration
# declare -a ARRAY_NAME

# Bash array initialization
# ARRAY_NAME=( ELEMENT_1 ELEMENT_2 ELEMENT_N )

# ARRAY_NAME : name that you would
# give to the array.

# ELEMENT_N : Nth element of array

# example 1
# declare names as an indexed array
declare -a names

# initialize the array
names=( Messi Ronaldo Salah Mane)

# access elements of array using index
echo ${names[2]}

# you may display the attributes and
# value of each element of array

declare -p names

# append elements to bash array
arr=( "bash" "shell" "script" )
arr+=( "new" "element" )
for i in "${arr[@]}"
do
    echo $i
done

# bash array length
arr=( "bash" "shell" "script" )
echo ${#arr[@]}


