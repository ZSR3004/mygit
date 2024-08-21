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

#ifndef MEMORY_H
#define MEMORY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

typedef struct dirent dirent;

void create_directory(char* path);
FILE *create_file(char* path);

char *get_cwd(void);

DIR *open_directory (char* path);
FILE *open_file(char *path, char *state);

unsigned long get_file_size(FILE *file);
size_t copy_file_to_string(char *file_contents, long unsigned file_size, FILE *file);
char *get_file_text(FILE *file);

bool in_directory(char* directory_path, char *entry_name);

void close_directory(DIR *directory);
void close_file(FILE *file);

#endif // MEMORY_H