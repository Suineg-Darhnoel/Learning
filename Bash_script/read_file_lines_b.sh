#!/bin/bash

# using file loop
i=1

while read l
do
    # l is available for processing
    echo Line $i : $l
    i=$(( i + 1 ))
done < read_file_lines_b.sh

# preventing backslash escapes
i=1
while read -r line
do
    # line is available for processing
    echo Line $i : $line
    let "i++"
done < read_file_lines_b.sh

# prevent trimming of leading
# or trailing white-spaces
i=1
while IFS= read line
do
    # line is available for processing
    echo Line $i : $line
    i=`expr $i + 1`
done < read_file_lines_b.sh
