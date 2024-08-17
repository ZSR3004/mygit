#!/bin/bash

 mygit=./../../bin/mygit

if [ "$1" = "clean" ]; then
    rm -rf .mygit
elif [ "$1" = "1" ]; then
    rm -rf .mygit
    $mygit init
    $mygit add src/main.c
elif [ "$1" = "2" ]; then
    rm -rf .mygit
    $mygit init
    $mygit add .
else
    echo "Invalid argument"
fi