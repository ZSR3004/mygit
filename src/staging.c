/**
 * @file staging.c
 * @brief Implementation file for staging processes.
 * 
 * This file handles the creation and adding to the index function.
 * 
 * The index file is a single plain-text file that holds a few pieces of information before changes
 * are commited via the "mygit commit" command. The general format is as follows:
 * 
 * <file path>, <the file's blob hash>, <file size>
 * <second file path>, <the second file's blob hash>, <second file size>
 * 
 * This is basically just a CSV file, but beacuse Git uses binary files, and I am already using plain-
 * text files as a stand-in for binary files in this project, I made the index file a plain-text for
 * consistency's sake.
 * 
 * If a file changes, then MyGit overwrites that line with the new information. It determines if a file
 * is the same file (and not just a different file with the same name) via the path.
 * 
 * @author Ziyad Rahman
 * 
 */


#include "../include/staging.h"

char *index_path = ".mygit/index/index.txt";

/**
 * @brief Creates a blank index file.
 * 
 * Creates an index file in the ".mygit/index/" directory. The index
 * starts as a blank plain-text file.
 * 
 */
void create_blank_index(void) {

    FILE *index = create_file(index_path);
    close_file(index);

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
void add_to_index(char *file_path, char *blob_hash, long unsigned int blob_size) {

    FILE *index = open_file(index_path, "a");

    fprintf(index, file_path);
    fprintf(index, ",");

    fprintf(index, blob_hash);
    fprintf(index, ",");

    char *char_blob_size = malloc(225);
    printf("blob size; %lu", blob_size);
    sprintf(char_blob_size, "%lu", blob_size);
    fprintf(index, char_blob_size);
    fprintf(index, ",");
    free(char_blob_size);
    fprintf(index, "\n");

    close_file(index);
    return;

}