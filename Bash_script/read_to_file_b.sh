#!/bin/bash

# bash read file using -cat filename

value=`cat read_to_file_b.sh`
echo "$value"

# bash read file using -$(<filename>)

value=$(<read_to_file_b.sh)
echo "$value"
