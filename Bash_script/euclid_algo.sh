#!/bin/bash

gcd(){
    if [ $2 -eq 0 ]
    then
        echo $1
    else
        remainder=$(($1%$2))
        echo ">> gcd($1, $2) = gcd($2, $remainder)"
        result=$(gcd $2 $remainder)
        printf "$result\n"
    fi
}

gcd 170 51
gcd 3127 901
