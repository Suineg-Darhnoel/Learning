#!/bin/bash

cnt=0
while [[ $cnt -lt 10 ]]
do
    (( cnt += 1 ))
    echo $cnt
    sleep 1
done
