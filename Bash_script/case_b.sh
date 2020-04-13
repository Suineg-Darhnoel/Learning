#!/bin/bash

# key points of bash case statements:
# - case statement first expands the
# expression and tries to match it
# against each pattern

# - When a match is found all of the
# associated statements until the double
# semicolon (;;) are executed.

# - After the first match, case terminates
# with the exit status of the last
# command that was executed

# - If there is no match, exit status
# of case is zero.

time=12

# if condition is true
case $time in
    9)
        echo Good Morning!
        ;;
    12)
        echo Good Noon!
        ;;
    17)
        echo Good Evening!
        ;;
    21)
        echo good Night!
        ;;
esac

# bash-case statement with default case
time=40

case $time in
    9)
        echo Good Morning!
        ;;
    12)
        echo Good Noon!
        ;;
    17)
        echo Good Evening!
        ;;
    21)
        echo good Night!
        ;;
    *)
        echo Good Day!
        ;;
esac
