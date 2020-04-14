#!/bin/bash

arr=( "elem1" "elem2" "elem3" )

for i in "${arr[@]}"
do
    echo $i
done

# for loop to consider white spaces
# in string as word separators

files="file1 file2 file3
file4 file5
file6"

for i in $files
do
    echo "$i"
done

# for loop to consider each line
# in string as separate word

for line in "$files"
do
    echo "$line"
done

# for loop to iterate over a sequence

for i in `seq 1 10`
do
    echo "->" $i
done

# for loop that uses a counter to
# iterate over elements of an array

arr=( "elem1" "elem2" "elem3" )

arr_len=${#arr[@]}

for (( i=1; i<${arr_len}+1; i++))
do
    echo $i : ${arr[$i-1]}
done


# for loop containing break statement

array=( "bash" "shell" "script" "language" )

for i in "${array[@]}"
do
    echo $i
    # break for loop based on a condition
    if [ $i == "script" ]
    then
        break
    fi
done
