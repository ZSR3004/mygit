#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file.h"

char *hash_function(char* str);

char *hash_lookup(char *object_hash);

#endif // HASH_H