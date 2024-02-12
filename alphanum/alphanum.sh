#!/bin/sh

while read -r line; do
    if [ "$(echo "$line" | grep -Ec "^$")" -ge 1 ]; then
        echo "it is empty"
    elif [ "$(echo "$line" | grep -Ec "^[a-zA-Z]+$")" -ge 1 ]; then
        echo "it is a word"
    elif [ "$(echo "$line" | grep -Ec "^[0-9]$")" -ge 1 ]; then
        echo "it is a digit"
    elif [ "$(echo "$line" | grep -Ec "^[0-9]{2,}$")" -ge 1 ]; then
        echo "it is a number"
    elif [ "$(echo "$line" | grep -Ec "^[a-zA-Z0-9]+$")" -ge 1 ]; then
        echo "it is an alphanum"
    else
        echo "it is too complicated"
        exit 0
    fi
done
