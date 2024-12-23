/**
 * @file init.h
 * @brief Creates the .mygit directory.
 * 
 * This creates the .mygit directory. The structure is as follows:
 * 
 * .mygit
 * ├── objects/         // Stores blob, tree, and commit objects.
 * ├── index/           // Contains the index file.
 * |   └── index.txt    // The index file which acts as the staging area.
 * ├── info/            // This is where the .mygitignore features will be stored.
 * ├── refs/            // Holds pointers to files that will be regularly referenced.
 * |   └── heads/       // Holds pointers to the heads of different branches.
 * └── HEAD/            // Holds a pointer to the HEAD (latest commit) of the current working branch.
 * 
 * To learn more about each file and what it does you can follow the below chart:
 *      objects: objects.h
 *      index: staging.h and add.h
 *      info:
 *      HEAD and heads:  
 * 
 * @author Ziyad Rahman
 * 
 */

#ifndef INIT_H
#define INIT_H

#include "file.h"
#include "staging.h"

void init_mygit_directory(void);

#endif // INIT_H