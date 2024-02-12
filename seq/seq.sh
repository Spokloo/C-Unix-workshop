#!/bin/sh

if [ $# -ne 3 ]; then
    echo "Usage: ./seq.sh FIRST INCREMENT LAST" 1>&2
    exit 1
fi

if [ "$2" -eq 0 ]; then
    exit 1
fi

if [ "$1" -eq "$3" ]; then
    echo "$1"
elif [ "$1" -lt "$3" ]; then
    if [ "$2" -le 0 ]; then
        exit 1
    fi

    i=0
    n="$(($1 + $i * $2))"
    while [ $n -ge "$1" ] && [ $n -le "$3" ]; do
        echo "$n"
        i="$(($i + 1))"
        n="$(($1 + $i * $2))"
    done
else
    if [ "$2" -ge 0 ]; then
        exit 1
    fi

    i=0
    n="$(($1 + $i * $2))"
    while [ $n -ge "$3" ] && [ $n -le "$1" ]; do
        echo "$n"
        i="$(($i + 1))"
        n="$(($1 + $i * $2))"
    done
fi

exit 0
