#ifndef IGNORE_H
#define IGNORE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "file.h"

/*
 * I think there may be worth in just making this a generic dyanmic array. Need to see how index list 
 * and this interact on the interact on an implementation level.
 * 
*/

/*
 * If iL is a valid representation of an ignoreList, then
 * iL represents [x_0, x_1,...,x_{iL->count}].
 * 
 * iL->arr represents an array of size iL->capacity which holds
 * il->count items.
 * 
 * An ignoreList is simply a dynamic array of strings. It's titled as
 * "ignoreList" since its only purpose in mygit is to handle data access
 * for .mygitignore.
 * 
 * Invariants:
 *      iL->count <= iL->capacity
 * 
*/
typedef struct {
    char **arr;
    int count;
    int capacity;
} ignoreList;

ignoreList *init_ignoreList();

ignoreList *grow_ignoreList(ignoreList *iL);

void insert_ignoreList(ignoreList *iL, char *item);

ignoreList *build_ignoreList(void);

bool in_ignoreList(ignoreList *iL, dirent *item);

void debug_print_ignoreList(ignoreList *iL);

void free_ignoreList(ignoreList *iL);

#endif // IGNORE_H