#!/bin/bash

# use += : Append to variable
str1="Learn"
str2=" Bash Scripting"

str1+=$str2
echo $str1

# include variable in a string
n1=10
echo "Number of Apples : $n1"

# concate two variables using string
str="Number of Apples : "
str="$str$n1"

echo $str
