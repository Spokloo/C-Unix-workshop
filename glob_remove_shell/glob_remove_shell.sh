#!/bin/sh

ext="txt"
if [ $# -eq 1 ]; then
    ext=$1
fi

for f in *.$ext; do
    if [ ! -f $f ]; then
        exit 1
    else
        rm $f
    fi
done
