#!/bin/bash

# to find string's length

# 1. ${#string}

# 2. expr length "$string"
#   observe the double quote
#   around $string.
#   if your string has spaces,
#   double quotes around $string
#   is kind of mandatory, else in
#   other cases you may ignore.
#   however, to be on the safe side,
#   always try including double
#   quotes around $string

# 3. expr "$string" : '.*'

str="Good Morning"

# example1
len_1=${#str}
echo "Length of '$str' is $len_1"

# example2
len_2=`expr length "$str"`
echo "Length of '$str' is $len_2"

# example3
len_3=`expr "$str" : '.*'`
echo "Length of '$str' is $len_3"
