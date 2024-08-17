#!/bin/bash

if [ "$1" = "clean" ]; then
    rm -rf .mygit
else
    mygit=./../../bin/mygit
    $mygit init
fi