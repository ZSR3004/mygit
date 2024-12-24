#ifndef DARR_H
#define DARR_H

#include "../common.h"



typedef struct keyval {
    char *key;
    char *val;
} keyval;

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
    keyval **items;
    int count;
    int capacity;
} darr;

darr *darr_init();
darr *darr_grow(darr *arr);
void darr_free(darr *arr);

void darr_insert(keyval *item, darr *arr);
keyval *darr_lookup(char *k, darr *arr);
void darr_delete(char *k, darr *arr);

HASH_MATCH cmp_kv(struct keyval *kv1, keyval *kv2);

#endif // DARR_H