#!/bin/sh

if [ $# -eq 0 ]; then
    echo
else
    echo $1/*.[a-zA-Z][a-zA-Z]
fi
