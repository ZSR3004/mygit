/**
 * @file hash.h
 * @author Ziyad Rahman
 * @brief Handles hashing and the hashtable.
 * @version 0.1
 * @date 2024-12-28
 * 
 * This file handles hashing for the program. Currently, there is a simplified implementation, but 
 * I plan to replace it with a SHA-1 hash like Git uses.
 * 
 * @todo Replace hash function with SHA-1.
 * 
 */

#ifndef HASH_H
#define HASH_H

#include "../common.h"

extern const int INIT_CAPACITY;
extern const int GROWTH_FACTOR;

typedef enum HASH_MATCH {
    MATCH,
    KEY_MATCH,
    VAL_MATCH,
    DIFF
} HASH_MATCH;

typedef struct hashNode {
    char *key;
    char *val;
    struct hashNode *next;
} hashNode;

typedef struct hashMap {
    hashNode **buckets;
} hashMap;

unsigned int hash(const char *key);
char *object_hash(char *str);

hashMap *hashmap_init();
hashNode *hashnode_init(char *key, char *val);
void hashmap_free(hashMap *map);

void hashmap_insert(hashMap *map, char *key, char *val);
char *hashmap_lookup(hashMap *map, char *key);
HASH_MATCH hashnode_compare(hashNode *node1, hashNode *node2);
void hashmap_delete(hashMap *map, char *key);


#endif // HASHMAP_H