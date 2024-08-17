#ifndef MEMORY_H
#define MEMORY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>


void create_directory(char* path, int permissions);

FILE *open_file(char *path, char *state);

unsigned long get_file_size(FILE *file);

size_t copy_file_to_string(char *file_contents, long unsigned file_size, FILE *file);

char *get_file_text(FILE *file);

void close_file(FILE *file);

#endif // MEMORY_H