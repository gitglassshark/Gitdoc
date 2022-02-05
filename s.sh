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
git remote -v
git remote -v;git rtup;git ss;git branch -av;git  status -s ;git log --oneline -10
