#!/bin/bash

# example 1
# check the variable is set
# use [[ -v <variablename> ]]
a=10 # a is set
if [[ -v a ]]
then
    echo "variable is already set"
else
    echo "variable is not set"
fi

# b is not set
if [[ -v b ]]
then
    echo "variable is already set"
else
    echo "variable is not set"
fi

# example 2
# check variable is empty
# use [[ -z ${<variablename>} ]]

c=10 # a is set
if [[ -z ${c} ]]
then
    echo "variable is empty"
else
    echo "variable is not empty"
fi

# d is empty
if [[ -z ${d} ]]
then
    echo "variable is empty"
else
    echo "variable is not empty"
fi
