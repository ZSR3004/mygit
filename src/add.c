#include "../include/add.h"

const int SIZE_BUFFER = 20;

char *get_file_name(char *path) {

    char *file_name = strrchr(path, '/');
    if (file_name != NULL) {
        file_name++;
    } else {
        file_name = path;
    }

    return file_name;

}

/*
 * !! This function is ommiting the last line of the file.
 * 
 * TODO: Fix the last line issue; likely resides in this function.
 * TODO: Add error handling if the hash ends up being two or less.
*/
char *create_blob(FILE *file) {

    char *file_text = get_file_text(file);
    unsigned long int_file_size = get_file_size(file);

    char *char_file_size = malloc(int_file_size * 4 + SIZE_BUFFER);
    sprintf(char_file_size, "%lu", int_file_size);

    char *blob = malloc(strlen(file_text) + sizeof("blob") + sizeof("1000"));
    strcpy(blob, "blob");
    strcat(blob, "\t");
    strcat(blob, char_file_size);
    strcat(blob, " bytes \n");
    strcat(blob, file_text);

    return blob;

}

char *create_index_location(char *blob_hash) {

    char *path = malloc(strlen(".mygit/index/") + sizeof(char) * 2 + 1);

    strcpy(path, ".mygit/index/");
    strncat(path, &blob_hash[0], 1);
    strncat(path, &blob_hash[1], 1);

    return path;

}

void index_file(char *path) {
    
    FILE *file = open_file(path, "r");

    char *blob = create_blob(file);
    close_file(file);

    char *blob_hash = hash_function(blob);
    char *index_path = create_index_location(blob_hash);

    create_directory(index_path);


    
}

