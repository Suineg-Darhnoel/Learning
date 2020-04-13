#!/bin/bash

# read -p PROMPT <variable_name>
# displays PROMPT without a new line
# and echoes input read from user,
# character by character.

echo "Welcome to our security"
read -p 'Username: ' username

# read -sp PROMPT <variable_name>
# displays PROMPT without a new line
# and echoes input read from user in
# silent mode (does not echo back
# user input).

read -sp 'Password: ' password

echo "Your name is : $username"
echo "Your password is : $password"

# read password with * echoed back
# to shell

# read username
read -p 'Username : ' usrname

echo -n "Enter password : "
stty -echo

# read password
charcount=0
while IFS= read -p "$prompt" -r -s -n 1 ch
do
    # Enter - accept password
    if [[ $ch == $'\0' ]]
    then
        break
    fi

    # Backspace
    if [[ $ch == $'\177' ]]
    then
        if [ $charcount -gt 0 ]
        then
            charcount=$((charcount-1))
            prompt=$'\b \b'
            passwd="${passwd%?}"
        else
            PROMPT=''
        fi
    else
        charcount=$((charcount+1))
        prompt='*'
        passwd+="$ch"
    fi
done

stty echo

echo
echo "Thank $usrname for showing interest"

echo "Your password is $passwd"
