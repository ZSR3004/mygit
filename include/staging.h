#ifndef STAGING_H
#define STAGING_H

#include "file.h"

void create_blank_index(void);
void add_to_index(char *file_path, char *blob_hash, char *blob_size);

#endif // STAGING_H