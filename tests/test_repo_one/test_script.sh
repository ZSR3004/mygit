#!/bin/bash

if [ "$1" = "clean" ]; then
    rm -rf .mygit
else
    rm -rf .mygit
    mygit=./../../bin/mygit
    $mygit init
    $mygit add src/main.c
fi