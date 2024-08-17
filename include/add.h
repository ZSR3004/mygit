#ifndef ADD_H
#define ADD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "memory.h"

char *get_file_name(char *path);

char *create_blob(char *path, FILE *file);

void index_file(char *path);


#endif // ADD_H