#!/bin/bash
echo -e "list current diretory file:"
echo -e "======================================="
ls
echo -e "ls git files:"
git ls
echo -e "======================================="
git add *
git cm "add and commit"
echo -e "stat git:"
echo -e "======================================="
git s -b --show-stash --short
echo -e "ls git branch stat"
echo -e "======================================="
git lb
git rtup
echo -e "ls git remote branch stat"
echo -e "======================================="
git remote -v
git ss
git branch -av
echo -e "log stat" "======================================="
git log --oneline -10
git push -v
