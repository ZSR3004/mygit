#ifndef ADD_H
#define ADD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "memory.h"
#include "hash.h"

void index_cases(char *path);

char *get_file_name(char *path);

char *create_blob(FILE *file);

char *create_index(char *blob_hash);

void index_file(char *path);

#endif // ADD_H