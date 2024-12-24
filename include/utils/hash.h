#ifndef HASH_H
#define HASH_H

#include "../common.h"
#include "darr.h"

typedef struct hashmap {
    kv ***arr;
    int size;
} hashmap;

char *hash_function(char *key);
hashmap *init_hashmap();
void free_hashmap(hashmap *hm);

HASH_MATCH cmp_kv(kv *kv1, kv *kv2);

void map_insert(char *key, char *val, hashmap *hm);
void map_delete(char *key, hashmap *hm);
kv *map_lookup(char *key, hashmap *hm);

#endif // HASH_H