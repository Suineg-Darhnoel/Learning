#!/bin/bash


# # about
# Function has to be deined in the
# shell script first, before we can
# use it.

# Arguments could be passed to functions
# and accessed inside the function as $1, $2 etc

# Local vairables could be declared
# inside the function and the scope of
# such local variable is only that function

# Using functions, you may override bultin
# commands of bash shell.

# form #1
myfunc_1 () {
    echo "This is my first function"
}

# form #2
function myfunc_2 {
    echo "This is my second function"
}

# call the first funcition
myfunc_1
myfunc_2

# learn how to pass arguments
function func_with_args {
    echo $1 : $2 in this $3
}

func_with_args "`date +"[%m-%d %H:%M:%S]"`" "Learn Functions" "Bash Tutorial"
