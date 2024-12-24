#ifndef BLOB_H
#define BLOB_H

#include "../common.h"

typedef struct node {
    
    char *hash;
    char *contents;

    struct node *left;
    struct node *right;

} node;

node *init_bt(FILE *file);
void free_bt(node *bt);

void bt_insert(FILE *file, node *bt);
void bt_delete(char *hash, node *bt);
node *bt_lookup(char *hash, node *bt);

#endif // BLOB_H