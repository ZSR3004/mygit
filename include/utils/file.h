/**
 * @file.h
 * @brief Handles file input/output
 * 
 * file.h handles file input, output, and creation. It's primary purpose is to error handle
 * for possibly finicky file functions like fopen and fwrite. It also handles writing to files
 * and extracting what are in files and placing that text into strings.
 * 
 * @author Ziyad Rahman
 * 
 */

#ifndef FILE_H
#define FILE_H

#include "../common.h"

/** 
 * @brief The standard permissions for creating a file or directory.
 * 
 * Allows the creator to read and write into the file.
 * 
*/
extern const int STANDARD_PERM;

DIR *create_directory(const char *path);
DIR* open_directory(const char *path);
void close_directory(DIR *dir);

FILE *create_file(const char *path);
FILE *open_file(const char *path, char* flags);
void close_file(FILE *file);

char *get_cwd(void);

unsigned long get_file_size(FILE *file);
size_t copy_file_to_string(char *file_contents, long unsigned file_size, FILE *file);
char *get_file_text(FILE *file);

#endif // FILE_H