#include "../include/objects.h"

// Blob Object Functions

/**
 * @brief Creates blob object.
 * 
 * Generates a string representation of a blob object.
 * 
 * @param file_size The size of the file in bytes.
 * @param file_text The contents of the file in a string.
 * 
 * @return A string representation of the blob object.
 * 
 */
char *init_blob(unsigned long file_size, char *file_text) {

    char *char_file_size = malloc((file_size * 4 + 100) * sizeof(char)); // Size Buffer
    sprintf(char_file_size, "%lu", file_size);
    size_t blob_size = strlen(file_text) + sizeof("blob") + 100; // Size Buffer

    char *blob = malloc((blob_size + 1) * sizeof(char));
    snprintf(blob, blob_size + 1, "blob\t%s bytes \n%s", char_file_size, file_text);

    free(char_file_size);

    return blob;

}


/**
 * @brief Builds a blob object from a file.
 * 
 * Builds a blob object from the file. It handles getting the content 
 * for the blob and intializing it. Opening and closing the file are 
 * done through external functions. Blob object must be freed by user.
 * 
 * @param file File to be copied into a blob object.
 * 
 * @return A string representation of the blob object.
 */
char *create_blob(FILE *file) {

    char *file_text = get_file_text(file);
    unsigned long int_file_size = get_file_size(file);

    char *blob = init_blob(int_file_size, file_text);

    free(file_text);

    return blob;

}

/**
 * @brief Frees blob object.
 * 
 * Frees blob object. Used mostly for readability.
 * 
 * @param blob The blob object to be freed.
 * 
 */
void free_blob(char *blob) {

    free(blob);

}

// Tree Object Functions
/**
 * 
 */
char *init_tree(char *mode, char *object_type, char* object_hash, char *object_name) {



}

/**
 * 
 */
char *build_tree(DIR *dir) {



}

/**
 *
 */
void free_tree(char *tree) {



}

// Commit Object Functions
char *init_commitObj(char *tree_hash, char *parent_commitObj_hash, char *author_name, char* author_email) {



}

char *build_commitObj(FILE *indexTable) {



}

char *free_commitObj(char *commitObj) {



}