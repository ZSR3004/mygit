#!/bin/bash

if [ "$1" = "clean" ]; then
    rm -rf .mygit
elif [ "$1" = "1" ]; then
    rm -rf .mygit
    mygit=./../../bin/mygit
    $mygit init
    $mygit add src/main.c
fi