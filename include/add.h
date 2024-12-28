/**
 * @file add.h
 * @author Ziyad Rahman
 * @brief Handles indexing done by the "mygit add" command.
 * 
 * This file is the header for the "mygit add" command. When the "mygit add" command runs
 * the program "stages" all changes (that is, files that were altered since the last commit).
 * To note which files are changed, the "add" command does two things:
 *      1. Creates a blob object of the file (see objects.h file for information on blobs)
 *      2. Adds the information to the index file (see staging.h for more on the index file)
 * 
 * The command can take in one of three possible
 * arguments:
 *      mygit add <file>
 *      mygit add <directory>
 *      mygit add .
 * 
 * The "." represents the current working directory and will add all the files in the current
 * working directory. So, in effect, "mygit add ." is really just "mygit add <path to current
 * working directory>"
 * 
 * The actual process for staging is listed out in the staging.h file. The add.h file and its 
 * source counter-part, add.c, handle parsing the user's input and hold functions that index
 * that input. The staging.h and staging.c files hold the step by step functions that the 
 * indexing functions in this file use.
 * 
 */

#ifndef ADD_H
#define ADD_H

#include "common.h"

/**
 * Deals with adding a file or directory.
 * 
 */
void add_cases(char *arg);

/**
 * Adds a files or directories. Also handles indexing of the object.
 * 
 */
void add_file(char *path);
void add_dir(char *path);

#endif // ADD_H