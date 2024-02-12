#!/bin/sh

FILENAME="default"
NUMBER=1
EXTENSION="txt"

while [ $# -ne 0 ]; do
    if [ "$1" = '-f' ] || [ "$1" = '--filename' ]; then
        shift
        FILENAME=$1
    elif [ "$1" = '-n' ] || [ "$1" = '--number' ]; then
        shift
        NUMBER=$1
    elif [ "$1" = '-e' ] || [ "$1" = '--extension' ]; then
        shift
        EXTENSION=$1
    else
        exit 1
    fi
    shift
done

for i in $(seq 1 $NUMBER); do
    touch -- "$FILENAME-$i.$EXTENSION"
done
