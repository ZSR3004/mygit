#ifndef STAGING_H
#define STAGING_H

#include "common.h"

FILE *create_blank_index();

void index_add();
void index_delete();
int index_lookup();

#endif // STAGING_H