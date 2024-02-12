#!/bin/sh

if [ $# -ne 1 ] || [ ! -d "$1" ]; then
    exit 1
fi

ls "$1" | file -N "$1"/* | grep -E ".*ASCII.*"

exit 0
