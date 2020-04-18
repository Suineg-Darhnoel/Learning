#!/bin/bash

EXEC_STR=`ls -htr`

IFS=' '
read -ra LISTED_LS <<< "$EXEC_STR"

LS_LEN=${#LISTED_LS}
echo $LS_LEN
# for (( i=0; i < $LS_LEN; i++ ))
# do
#     echo $i : "${LISTED_LS[ $i ]}"
# done
