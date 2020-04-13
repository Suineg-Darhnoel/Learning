#!/bin/bash

r1=$(( 15 + 8 ))
r2=`expr 15 + 8`

echo "r1 = $r1, r2 = $r2"

# exponentiation
a=15
b=8
r3=$(( $a ** $b ))

echo "the value of $a ** $b = $r3"

# increment variable by constant
x=2
let "x += 5"
echo "x = $x"

y=3
(( y+= 5 ))
echo "y = $y"

# you can also do with
# -=, *=, /=, %=

# NOTE
# double parenthese could be
# used for arithmetic expansion.

echo "x + y = $(( $x + $y ))"

# let construction is used to
# carry out arithmetic operations.

let "z = $(( $x % $y ))"
echo $z

let z=$(( $x % $y ))
