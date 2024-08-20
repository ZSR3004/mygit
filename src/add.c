#include "../include/add.h"

// indexTable is in the index file. 

/*
 * Need to move stuff around so object creation, building, and freeing are done in the objects file.
 * 
 * This file does one thing: stage objects. Clean up how the strings are made.
*/

/**
 * @brief Extra space for when creating a string.
 * 
 * @todo Move this definition to a file so other libraries like 
 * memory.h can access it.
 *
 */
const int SIZE_BUFFER = 100;

/**
 * @brief Enumeration for the d_type attribute in the directory library
 * 
 * @todo Edit directory index function to support the library's native comparison.
 * 
*/
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
 * @brief Creates the file path for a blob object.
 * 
 * Creates the file path that the blob object (represented by the hash) to be written into.
 * The object will always be placed in (".mygit/objects/" + blob_hash[0:1]). In other words,
 * all blobs are placed in a directory titled with the first two values of the hash in the 
 * .mygit/objects directory.
 * 
 * @param blob_hash A valid representation of a blob's hash function.
 * 
 * @return The path in which the blob will be placed.
 */
char *create_index_location(char *blob_hash) {


    char *path = malloc(strlen(".mygit/objects/") + sizeof(char) * 2 + 1);

    strcpy(path, ".mygit/objects/");
    strncat(path, &blob_hash[0], 1);
    strncat(path, &blob_hash[1], 1);

    return path;

}

/**
 * @brief Indexes a directory when added using the mygit add command.
 * 
 * Indexes directories by either indexing any files in the directory or 
 * entering a subdirectory through recursive calling.
 * 
 * @param path The path given by the user in the mygit add command.
 *  (issue w/ first few char)
 * 
 * @bug May add a file twice if its name is similar to another file's.
 * 
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
 * @brief Indexes a file.
 * 
 * Creates a blob object for the file at the path and adds it 
 * to the index table.
 * 
 * @param path The path for the file to be indexed.
 * 
 */
void index_file(char *path) {
    
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