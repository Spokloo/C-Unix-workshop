#!/bin/sh

sed -n -E "/^\w.*\)$/p" "$1" | sed 's/$/;/g'
