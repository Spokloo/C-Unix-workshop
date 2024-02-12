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

col2=$(cut -d';' -f2 "$1" | head -n "$2" | tail -n 1)
col3=$(cut -d';' -f3 "$1" | head -n "$2" | tail -n 1)
echo "$col2 is $col3"

exit 0
