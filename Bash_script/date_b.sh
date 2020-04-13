#!/bin/bash

# date +<format-option><format-option>

d=`date +%m-%d-%y`
echo $d

d=`date +%m-%Y`
echo $d

d=`date '+%A %d-%B, %Y'`
echo $d
