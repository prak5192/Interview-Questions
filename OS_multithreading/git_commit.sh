#! /bin/bash


echo $1 $2

git add $1
git commit -m "$2"
git push -f origin master:master
