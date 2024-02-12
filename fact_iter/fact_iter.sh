#!/bin/sh

if [ $# -ne 1 ]; then
    exit 1
else
    n=$1
    res=1
    while [ $n -gt 1 ]; do
        res=$((res*n))
        n=$((n-1))
    done
    echo $res
fi
