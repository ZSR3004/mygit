#!/bin/bash

 mygit=./../../bin/mygit

if [ "$1" = "clean" ]; then
    rm -rf /home/zsr/curr_proj/mygit/tests/test_repo_one/.mygit
elif [ "$1" = "1" ]; then
    rm -rf .mygit
    $mygit init
    $mygit add /src/main.c
elif [ "$1" = "2" ]; then
    rm -rf .mygit
    cd test_repo_one
    $mygit init
    $mygit add /home/zsr/curr_proj/mygit/tests/test_repo_one
elif [ "$1" = "3" ]; then
    rm -rf .mygit
    cd test_repo_one
    $mygit init
    $mygit add .
    $mygit
else
    echo "Invalid argument"
fi