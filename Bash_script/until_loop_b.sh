#!/bin/bash

# until_loop is similar to while_loop
# but the block of statements are executed
# until the expression returns true which
# is quite contrast to while_loop

count=10
i=20

# until loop with single condition
until [ $i -lt $count ]
do
    echo "$i"
    let i--
done

a=20
b=16

# until loop for multiple conditions in expression
until [[ $a -lt $count || $b -lt count ]]
do
    echo "a : $a, b : $b"
    let a--
    let b--
done
