#!/bin/bash
echo `date` "change the file $1 .auto.change.sh">>$1
echo "change the file $1"
echo "==========================x"
echo "cat file $1"
echo "==========================x"
cat $1
echo "git status --short"
echo "==========================x"
git status --short
