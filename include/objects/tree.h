#ifndef TREE_H
#define TREE_H

#include "../common.h"

char *create_tree();
void free_tree(char *t);

char *compare_trees(char *t1, char *t2);
char *compare_treeLine(char *l1, char *l2);

#endif // TREE_H