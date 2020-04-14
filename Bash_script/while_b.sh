#!/bin/bash

count=10
i=0

# while loop
while [ $i -lt $count ]
do
    echo "$i"
    let i++
done

a=0
b=0

# multiple conditions in the
# expression of while loop

while [[ $a -lt $count && $b -lt 4 ]]
do
    echo "$a"
    let a++
    let b++
done
