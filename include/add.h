/**
 * @file add.h
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
 * @author Ziyad Rahman
 * 
 */

#ifndef ADD_H
#define ADD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file.h"
#include "hash.h"
#include "strarr.h"

/*
 * Function that handles if mygit treats the source as a file
 * or as a directory.
 * 
*/
void add_command_cases(char *path);

/*
 * Functions to handle creating the directory that blob objects 
 * will be placed in. 
 * 
 */
char *get_file_name(char *path);
char *create_index_location(char *blob_hash);

/*
 * Functions that do the actual staging work.
*/
void stage_directory(char *path);
void stage_file(char *path);

#endif // ADD_H