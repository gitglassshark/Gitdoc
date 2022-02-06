#!/bin/bash
for n in {1..10}
do
  echo  \#`date`+ \#`pwd`+" #$n"+" #auto"+"change..."+" #$1" >> readme.autofile
  git add readme.autofile 
#  git commit -m"$n.th auto add and commit file readme.autofile #$n"
git commit -m"$n.th auto add and commit""$(cat readme.autofile|tail -1)"
done
#git show-branch -g --reflog=26 
#:w
#git show-branch --more=100
