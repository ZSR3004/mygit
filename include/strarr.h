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

strArr *build_strArr(void);

bool in_strArr(strArr *sa, dirent *item);

void debug_print_strArr(strArr *sa);

void free_strArr(strArr *sa);

#endif // STRARR_H