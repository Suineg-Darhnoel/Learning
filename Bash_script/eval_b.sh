#!/bin/bash

x="5+50*3/20 + (19*2)/7"
charcount="wc -c eval_b.sh"
eval $charcount

xx="$(($x))"
printf "%d\n" $xx

printf "%.3f\n" `echo $x | bc -l`
