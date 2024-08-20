#include "../include/add.h"

const int SIZE_BUFFER = 100;

// Enumeration for the d_type attribute in the directory library
const int DIR_ENUM = 4;
const int FILE_ENUM = 8;


/**
 * @brief Indexes the cases based on the given path.
 *
 * Indexes cases based on provided path where "." represents current working directory. 
 * If a "/" is the first character of the path, then this function treats it as a directory, 
 * otherwise it treats it like a file.
 *
 * @param path Path to be indexed.
 */
void index_cases(char *path) {

    if (strcmp(path, ".") == 0) {
        char *cwd = get_cwd();
        index_directory(cwd);
        free(cwd);
    } else if (strcmp(path, "/") == 0) {
        index_directory(path);
    } else {
        index_file(path);
    }

}

/**
 * @brief Gets the name of a file.
 * 
 * Returns a string representing the file name at path.
 * 
 * @param path Path to be indexed.
 * 
 * @return The name of file.
 */
char *get_file_name(char *path) {

    char *file_name = strrchr(path, '/');
    if (file_name != NULL) {
        file_name++;
    } else {
        file_name = path;
    }

    return file_name;

}

/**
 * @brief
 * 
 * @parameter
 * 
 * @return 
 */
char *create_blob(FILE *file) {

    char *file_text = get_file_text(file);
    unsigned long int_file_size = get_file_size(file);

    char *char_file_size = malloc((int_file_size * 4 + SIZE_BUFFER) * sizeof(char));
    sprintf(char_file_size, "%lu", int_file_size);

    size_t blob_size = strlen(file_text) + sizeof("blob") + SIZE_BUFFER;
    char *blob = malloc((blob_size + 1) * sizeof(char));
    snprintf(blob, blob_size + 1, "blob\t%s bytes \n%s", char_file_size, file_text);

    free(char_file_size);
    free(file_text);

    return blob;

}

/**
 * @brief
 * 
 * 
 * 
 * @param
 * 
 * @return 
 */
char *create_index_location(char *blob_hash) {


    char *path = malloc(strlen(".mygit/objects/") + sizeof(char) * 2 + 1);

    strcpy(path, ".mygit/objects/");
    strncat(path, &blob_hash[0], 1);
    strncat(path, &blob_hash[1], 1);

    return path;

}

/**
 * @brief
 * 
 * 
 * 
 * @parameter
 *  (issue w/ first few char)
 * @return 
 */
void index_directory(char *path) {

    DIR *dir = open_directory(path);
    ignoreList *iL = build_ignoreList();
    char* subdir_path;
    dirent *entry;

    while ((entry = readdir(dir)) != NULL) {

        if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..")) continue;

        char *curr_path = malloc(strlen(path) + strlen(entry->d_name) + SIZE_BUFFER);
        strcpy(curr_path, path);
        strcat(curr_path, "/");
        strcat(curr_path, entry->d_name);

        if (entry->d_type == FILE_ENUM) {
            index_file(curr_path);
        } else if (entry->d_type == DIR_ENUM) {
            subdir_path = malloc(strlen(path) + strlen(entry->d_name) + SIZE_BUFFER);
            strcpy(subdir_path, path);
            strcat(subdir_path, "/");
            strcat(subdir_path, entry->d_name);
            index_directory(subdir_path);
            free(subdir_path);
        }

        free(curr_path);

    }

    free_ignoreList(iL);
    close_directory(dir);
    return;

}

/**
 * @brief
 * 
 * 
 *  
 * @parameter
 * 
 * @return 
 */
void index_file(char *path) {

    add_index_table(path);
    
    FILE *file = open_file(path, "r");

    char *blob = create_blob(file);
    close_file(file);


    char *blob_hash = hash_function(blob);
    char *index_path = create_index_location(blob_hash);

    create_directory(index_path);

    char *final_path = malloc(strlen(index_path) + strlen(blob_hash) + 1 + SIZE_BUFFER);
    strcpy(final_path, index_path);
    strcat(final_path, "/");
    strcat(final_path, &blob_hash[2]);
    strcat(final_path, ".txt");

    FILE *final_file = open_file(final_path, "w");
    fwrite(blob, sizeof(char), strlen(blob), final_file);

    free(final_path);
    free(index_path);
    free(blob_hash);
    free(blob);
    close_file(final_file);

}