#!/bin/bash

# number variable
num=10
echo $num

# character variable
ch='c'
echo $ch

# string variable
str="Hello Bob!"
echo $str

# array variable
arr=("bash" "shell" "script")
echo "${arr[0]}"
echo "${arr[1]}"
echo "${arr[2]}"

# bash variable
SHELL="Unix"

function bashShell {
    # bash local variable
    local SHELL="Bash"
    echo $SHELL
}

echo $SHELL
bashShell
echo $SHELL
