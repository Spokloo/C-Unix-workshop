#!/bin/sh

if [ $# -eq 1 ]; then
    if [ ! -f "$1" ]; then
        exit 1
    fi

    while IFS= read -r line; do
        if [ $(echo "$line" | wc -m) -gt 80 ]; then
            printf '%s\n' "$line"
        fi
    done < "$1"
    exit 0
fi

exit 1
