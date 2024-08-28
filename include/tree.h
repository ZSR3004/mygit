#ifndef TREE_H
#define TREE_H

#include "tree_cache.h"
#include "add.h"
#include "file.h"

typedef enum {
    TYPE_BLOB,
    TYPE_TREE
} OBJ_TYPE;

typedef struct {
    OBJ_TYPE type;
    char *name;
    char *hash;
} tree;

tree *init_tree(OBJ_TYPE type, char *name, char *hash);

void write_tree_to_file(tree *t);

void free_tree(tree *tO);

#endif // TREE_H