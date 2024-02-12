#!/bin/sh

if [ $# -ne 1 ]; then
    exit 1
fi

facto() {
    n="$1"
    res=1
    while [ $n -gt 0 ]; do
        res="$((res * n))"
        n="$((n - 1))"
    done
}

facto "$1"
echo "$res"
