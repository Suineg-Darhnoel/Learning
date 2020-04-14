#!/bin/bash

log=log_file.txt

# create log file or overrite
# if already present
printf "Log File - " > $log

# append date to long file
date >> $log

x=$(( 3 + 1 ))
# append some data to log file
echo value of x is $x >> $log
