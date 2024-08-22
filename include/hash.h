/**
 * @file hash.h
 * @brief Deals with hashing and hashing lookup.
 * 
 * This file handles hashing for the program. Currently, there is a simplified implementation, but 
 * I plan to replace it with a SHA-1 hash like Git uses.
 * 
 * @author Ziyad Rahman
 * 
 */

#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file.h"

char *hash_function(char* str);

char *hash_lookup(char *object_hash);

#endif // HASH_H