/**
 * @file staging.c
 * @brief Implementation file for staging processes.
 * 
 * 
 * 
 */

#include "../include/staging.h"

/**
 * @brief Creates a blank index file.
 * 
 * Creates an index file in the ".mygit/index/" directory. The index
 * starts as a blank plain-text file.
 * 
 */
void create_blank_index(void) {



}

/**
 * @brief Adds a blob's information to the index file.
 * 
 * Takes a blob's information and adds it to the index. This function
 * handles the opening and closing of the index file and possible
 * duplicate adds (where the "add" command is used on the same file
 * multiple times during the same comit).
 * 
 * @param file_path The path to the file which is being represented by 
 *                  a blob.
 * @param blob_hash The hash of the file's blob.
 * @param blob_size The size of the file's blob; this is the same number
 *                  listed in the actual blob object file.
 * 
 */
void add_to_index(char *file_path, char *blob_hash, char *blob_size) {



}