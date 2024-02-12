#!/bin/sh

for a; do
    if [ -f "$a" ]; then
        echo "$a: file"
    elif [ -d "$a" ]; then
        echo "$a: directory"
    else
        echo "$a: unknown"
    fi
done
