#ifndef HASH_MAP_H
#define HASH_MAP_H

#include "../../common.h"

typedef enum HASH_MATCH {
    MATCH,
    KEY_MATCH,
    VAL_MATCH,
    DIFF
} HASH_MATCH;

typedef struct kv {
    char *key;
    char *val;
} kv;

typedef struct hashmap {
    kv ***arr;
    int size;
} hashmap;

char *hash_function();
hashmap *init_hashmap();
void free_hashmap();

bool *cmp_kv();

void map_insert();
void map_delete();
kv *map_lookup();

#endif // HASH_MAP_H