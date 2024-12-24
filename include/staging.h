#ifndef STAGING_H
#define STAGING_H

#include "common.h"

FILE *create_blank_index();

void index_add(char *path, FILE *file);
void index_delete();
char *index_lookup();

#endif // STAGING_H