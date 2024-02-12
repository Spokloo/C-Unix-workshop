#!/bin/sh

[ -n "$2" ] && [ "$2" -eq "$2" ] 2>/dev/null
if [ $? -ne 0 ]; then
    exit 1
fi

if [ $# -ne 2 ] || [ ! -f "$1" ] || [ "$2" -le 0 ]; then
    exit 1
fi

if [ $(wc -l < "$1") -lt "$2" ]; then
    exit 1
fi

res=$(sed -En "$2s/^[^;]*;([^;]*);([^;]*);.*/\1 is \2/p" "$1")

echo "$res"

exit 0
