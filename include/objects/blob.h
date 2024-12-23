#ifndef BLOB_H
#define BLOB_H

#include "../common.h"

typedef struct node {
    
    char *path;
    char *hash;

    struct node *left;
    struct node *right;

} node;

char *create_blob(FILE *file);
void free_blob(char *blob);

node *init_bt();
void free_bt();

void bt_insert();
void bt_delete();
node *bt_lookup();

void bt_write();

#endif // BLOB_H