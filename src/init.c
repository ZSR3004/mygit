/**
 * @file init.c
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

#include "../include/init.h"

/**
 * @brief Creates the .mygit directory.
 * 
 */
void init_mygit_directory(void) {

    create_directory(".mygit");
    create_directory(".mygit/objects");
    create_directory(".mygit/index");
    create_blank_index();
    create_directory(".mygit/info/");
    create_directory(".mygit/refs");
    create_directory(".mygit/refs/heads");
    create_directory(".mygit/HEAD");

    FILE *index_file = create_file(".mygit/index/index.txt");
    close_file(index_file);

    return;
    
}