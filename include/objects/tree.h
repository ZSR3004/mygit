/**
 * @file tree.h
 * @author Ziyad Rahman
 * @brief Handles the tree object for mygit.
 * @version 0.1
 * @date 2024-12-28
 * 
 /**
 * Below are the functions related to tree objects.
 * 
 * A tree object is the directory equivalent to the blob object. Basically, its a text file that holds all the files within
 * a given directory and points to any subdirectories.
 * 
 * For each object in the tree, there are three key pieces of information listed that follow this format for each line:
 *      <object type>   <object hash>   <object name>
 * 
 * For example, if your working directory looks like this:
 *      myproject/
 *      ├── file1.txt
 *      └── subdir/
 *          └── file2.txt
 *  
 * Then, the tree for the myproject directory would look like this:
 * 
 * blob     abcd1234    file1.txt
 * tree     efgh5678    subdir
 * 
 * And the tree of the subdir directory would look like:
 * 
 * blob     ijkl90  file2.txt
 * 
 */

#ifndef TREE_H
#define TREE_H

#include "../common.h"

char *create_tree();
void free_tree(char *t);

char *compare_trees(char *t1, char *t2);
char *compare_treeLine(char *l1, char *l2);

#endif // TREE_H