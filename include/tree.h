#ifndef TREE_H 
#define TREE_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    FILE_SUBTREE,
    DIR_SUBTREE
} SUBTREE_TYPE;

typedef struct subtree_cache subtree_cache;
struct subtree_cache{
    struct tree_cache *tree_cache;
    SUBTREE_TYPE type;
    char *name;
    int namelen;
    bool used;
};

typedef struct tree_cache tree_cache;
struct tree_cache{
    int entry_count;
    subtree_cache **down;
};

subtree_cache *init_subtree_cache(void);
tree_cache *init_tree_cache(void);

char *get_name(char[], int);
bool is_index_file(char[]);
int dir_in_tree(char*, tree_cache*);

void recursive_tree_insert(tree_cache*, char*);
void build_trees(FILE *index, tree_cache *tc, char *cwd);

void print_tc(tree_cache *tc, int depth);

void free_subtree_cache(subtree_cache *stc);
void recursive_free_tree_cache(tree_cache *tc);

#endif // TREE_H