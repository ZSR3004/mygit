/**
 * @file add.h
 * @brief Handles processes for the "mygit add" command.
 * 
 * 
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
#include "ignore.h"

/*
 * Function that handles if mygit treats the source as a file
 * or as a directory.
 * 
*/
void index_cases(char *path);

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