#!/bin/bash

str1="Learn Bash"
str2="Learn Bash"

if [ "$str1" == "$str2" ]
# double quotes around the variables
# used for condition is important
# because without them when encounter
# string variables that contains spaces
# bash will consider as multiple strings
then
    echo "Both strings are equal."
else
    echo "Both strings are not equal."
fi

str1="Another"
str2="Other"

if [ "$str1" != "$str2" ]
then
    echo "Both strings are not equal."
else
    echo "Both strings are equal."
fi
