#include "../include/objects.h"

// Blob Object Functions
char *init_blob(int file_size, char *file_contents) {



}

char *build_blob(FILE *file) {



}

void free_blob(char *blob) {



}

// Tree Object Functions
char *init_tree(char *mode, char *object_type, char* object_hash, char *object_name) {



}

char *build_tree(DIR *dir) {



}

void free_tree(char *tree) {



}

// Commit Object Functions
char *init_commitObj(char *tree_hash, char *parent_commitObj_hash, char *author_name, char* author_email) {



}

char *build_commitObj(FILE *index_table) {



}

char *free_commitObj(char *commitObj) {



}