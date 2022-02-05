#!/bin/bash
git add *
git cm "add and commit"
echo -e "stat git:\n"
git s -b --show-stash --short
echo -e "ls git files:\n"
git ls
echo -e "ls git branch stat\n"
git lb
echo -e "ls current diretory file:\n"
ls
git rtup
git remote -v
git ss
git branch -av
git log --oneline -10
git push -v
