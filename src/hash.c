#include "../include/common.h"

#define HASHMAP_SIZE 200

char *object_hash(char *str) {
    size_t len = strlen(str);
    char *hash = malloc((2 * len + 1) * sizeof(char) + 1);
    if (hash == NULL) {
        perror("Failed to hash string");
        exit(1);
    }
    for (size_t i = 0; i < len; i++) {
        sprintf(&hash[2 * i], "%02x", (unsigned char)str[i]);
    }
    hash[2 * len] = '\0';
    return hash;
}

unsigned int hash(const char *key) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash * 31) + *key++;
    }
    return hash % HASHMAP_SIZE;
}

hashMap *hashmap_init() {
    hashMap *map = malloc(sizeof(hashMap));
    if (!map) {
        perror("Failed to allocate hashmap");
        exit(1);
    }
    map->buckets = calloc(HASHMAP_SIZE, sizeof(hashNode));
    if (!map->buckets) {
        perror("Failed to allocate buckets");
        free(map);
        exit(1);
    }
    return map;
}

hashNode *hashnode_init(char *key, char *val) {
    hashNode *node = malloc(sizeof(hashNode));
    if (!node) {
        perror("Failed to allocate node");
        exit(1);
    }
    node->key = strdup(key);
    node->val = strdup(val);
    node->next = NULL;
    return node;
}

void hashmap_free(hashMap *map) {
    for (int i = 0; i < HASHMAP_SIZE; i++) {
        hashNode *current = map->buckets[i];
        while (current) {
            hashNode *temp = current;
            current = current->next;
            free(temp->key);
            free(temp->val);
            free(temp);
        }
    }
    free(map->buckets);
    free(map);
}

void hashmap_insert(hashMap *map, char *key, char *val) {
    unsigned int index = hash(key);
    hashNode *current = map->buckets[index];

    while (current) {
        if (strcmp(current->key, key) == 0) {
            free(current->val); 
            current->val = strdup(val);
            return;
        }
        current = current->next;
    }

    hashNode *new_node = hashnode_init(key, val);
    new_node->next = map->buckets[index];
    map->buckets[index] = new_node;
}

char *hashmap_lookup(hashMap *map, char *key) {
    unsigned int index = hash(key);
    hashNode *current = map->buckets[index];

    while (current) {
        if (strcmp(current->key, key) == 0) {
            return current->val;
        }
        current = current->next;
    }
    return NULL;
}

HASH_MATCH hashnode_compare(hashNode *node1, hashNode *node2) {
    if (strcmp(node1->key, node2->key) == 0) {
        if (strcmp(node1->val, node2->val) == 0) return MATCH;
        else return KEY_MATCH;
    } else if (strcmp(node1->val, node2->val) == 0) return VAL_MATCH;
    return DIFF;
}

void hashmap_delete(hashMap *map, char *key) {
    unsigned int index = hash(key);
    hashNode *current = map->buckets[index];
    hashNode *prev = NULL;

    while (current) {
        if (strcmp(current->key, key) == 0) {
            if (prev) {
                prev->next = current->next;
            } else {
                map->buckets[index] = current->next;
            }
            free(current->key);
            free(current->val);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}
