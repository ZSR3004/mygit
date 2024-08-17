#!/bin/bash

if [ "$1" = "clean" ]; then
    rm -rf .mygit
else
    mygit=./../../bin/mygit
    $mygit init
    $mygit add /src/main.c
fi