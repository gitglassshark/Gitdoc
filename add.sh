#!/bin/bash
echo "$0 to change add file $1"
echo "change the file .auto-add.sh">>$1
git add $1
