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
*/
char *create_blob(char *path, FILE *file) {

    char *file_name = get_file_name(path);
    char *file_text = get_file_text(file);
    unsigned long int_file_size = get_file_size(file);

    char *char_file_size = malloc(int_file_size * 4 + SIZE_BUFFER);
    sprintf(char_file_size, "%lu", int_file_size);

    char *result = malloc(strlen(file_name) + strlen(file_text) + 1);
    strcpy(result, file_name);
    strcat(result, "\t");
    strcat(result, char_file_size);
    strcat(result, " bytes \n");
    strcat(result, file_text);

    return result;

}

void index_file(char *path) {
    
    FILE *file = open_file(path, "r");

    char *blob = create_blob(path, file);

    printf("%s\n", blob); // replace with indexing

    close_file(file);
    
}

