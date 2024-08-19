#ifndef IGNORE_H
#define IGNORE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "memory.h"

typedef struct {
    char **arr;
    int count;
    int capacity;
} ignoreList;

ignoreList *init_ignoreList();

ignoreList *grow_ignoreList(ignoreList *iL);

void insert_ignoreList(ignoreList *iL, char *item);

ignoreList *build_ignoreList(void);

bool in_ignoreList(ignoreList *iL, char *item);

void debug_print_ignoreList(ignoreList *iL);

void free_ignoreList(ignoreList *iL);

#endif // IGNORE_H