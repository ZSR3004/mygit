#ifndef DARR_H
#define DARR_H

#include "../common.h"

extern const int INIT_CAPACITY;
extern const int GROWTH_FACTOR;

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

/*
 * If arr is a valid representation of an strArr, then
 * arr represents [x_0, x_1,...,x_{da->count}].
 * 
 * arr->items represents an array of size arr->capacity which holds
 * arr->count items.
 * 
 * arr->items initializes with a size of INIT_CAPACITY = 10, and it will
 * grow by GROWTH_FACTOR = 1.5 if the invariant will be false upon the 
 * current insertion's completion.
 * 
 * 
 * Invariants:
 *      arr->count <= arr->capacity
 * 
*/
typedef struct {
    kv **items;
    int count;
    int capacity;
} darr;

darr *darr_init();
darr *darr_grow(darr *arr);
void darr_free(darr *arr);

void darr_insert(kv *item, darr *arr);
kv *darr_lookup(char *key, darr *arr);
void darr_delete(char *key, darr *arr);

#endif // DARR_H