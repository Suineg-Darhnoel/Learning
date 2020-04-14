#!/bin/bash

# to find substring in bash,
# use the following syntax:
# ${string:position:length}

str="longstring"

subStr=${str:3:9}

echo $subStr

# compute substring provided
# position

subStr=${str:2}
echo $subStr
