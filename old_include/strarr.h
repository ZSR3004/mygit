/**
 * @file starr.h
 * @brief A dynamic array of strings.
 * 
 * This file is the header for a dynamic array of strings, abbreviated as "strArr" (STRing ARRay).
 * 
 * The main use cases for the dynamic array will be storing strings from files in .mygit to make
 * accessing data easier during the execution of the "mygit checkout" command or for dealing with
 * .mygitignore.
 * 
 * @author Ziyad Rahman
 * 
 */

#ifndef STRARR_H
#define STRARR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "file.h"

/*
 * If sa is a valid representation of an strArr, then
 * sa represents [x_0, x_1,...,x_{sa->count}].
 * 
 * sa->items represents an array of size sa->capacity which holds
 * sa->count items.
 * 
 * sa->items initializes with a size of INIT_CAPACITY = 10, and it will
 * grow by GROWTH_FACTOR = 1.5 if the invariant will be false upon the 
 * current insertion's completion.
 * 
 * 
 * Invariants:
 *      sa->count <= sa->capacity
 * 
*/
typedef struct {
    char **items;
    int count;
    int capacity;
} strArr;

strArr *init_strArr();

strArr *grow_strArr(strArr *sa);

void insert_strArr(strArr *sa, char *item);

strArr *build_strArr(char *file_path);

bool in_strArr(strArr *sa, dirent *item);

void debug_print_strArr(strArr *sa);

void free_strArr(strArr *sa);

#endif // STRARR_H