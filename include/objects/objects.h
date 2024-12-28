/**
 * @file objects.h
 * @author Ziyad Rahman
 * @brief Handles the blob object for mygit.
 * @version 0.1
 * @date 2024-12-28
 * 
 * This file details the abstraction for the objects.bin file in the MyGit directory.
 * The types of objects in MyGit are as follow:
 *      1.  Blobs: Stores file information.
 *      2.  Trees: Stores directory information.
 *      3.  Commits (which are referred to as Commit Objects or commitObj): Stores commit
 *          information
 * 
 * Each object file is titled with their hash, which is generated from the object file's
 * content, that is, every line of the plain-text file (see hash.h and hash.c for more). 
 * Objects are used in practically all commands.
 * 
 * The blob object is primarily handled in the staging and add files, so its information
 * is detailed in the add.h file. You can refer to the commitobj.h and tree.h for more
 * about those objects.
 * 
 */

#ifndef BLOB_H
#define BLOB_H

#include "../common.h"

/**
 * @brief A binary tree datastructure to hold objects. The core purpose within
 * the program is to hold all objects (trees, blobs, and commits) in persistent
 * memory via a binary file.
 * 
 * the contents attribute stores the actual text of each object (for example: the
 * text of a file for a blob object or the directory structure for a tree). 
 * 
 * the hash attribute holds the hashed version of content and is used for easy
 * lookup.
 * 
 */
typedef struct node {
    
    char *hash;
    char *contents;

    struct node *left;
    struct node *right;

} node;

/**
 * Handles memory allocation during runtime for BT.
 * 
 */
node *init_bt(FILE *file);
void free_bt(node *bt);

/**
 * Basic insertion, deletion, and lookup operations for a
 * BT.
 * 
 */
void bt_insert(FILE *file, node *bt);
void bt_delete(char *hash, node *bt);
node *bt_lookup(char *hash, node *bt);

/**
 * Handles the process of writing (serializing) and extracting
 * (deserializing) the BT from the objects.bin file in the
 * .mygit directory.
 * 
 */
void bt_serialize(node *root);
node *bt_deserialize();

#endif // BLOB_H