/**
 * @file file.c
 * @brief Implementation for file and directory handling.
 * 
 * This file takes basic functions like fopen and fclose from <stdlib.h> and executes them
 * while handling potential errors by exiting the program if they occur.
 * 
 * @author Ziyad Rahman
 * 
 */

#include "../../include/common.h"

const int STANDARD_PERM = 0755;

/**
 * @brief Creates a directory at path.
 * 
 * @param path The path for the directory to be created.
 * 
 */
DIR *create_directory(const char *path) {

    if (access(path, F_OK) != 0) exit(1);

    int status = mkdir(path, STANDARD_PERM);
    if (status != 0) {
        printf("Error creating directory: %s\n", path);
        exit(1);
    }

    DIR *dir = opendir(path);
    if (dir == NULL) {
        printf("Error opening directory after creation: %s\n", path);
        exit(1);
    }

    return dir;
}

/**
 * @brief Opens the directory at path.
 * 
 * @param path The path of the directory.
 * 
 * @return Returns the directory's object.
 * 
 */
DIR* open_directory(const char *path) {

    DIR* directory = opendir(path);
        if (directory == NULL) {
            printf("Failed to open directory: %s\n", path);
            exit(1);
        }
        return directory;
}

/**
 * @brief Closes directory.
 * 
 * @param directory The directory to be closed.
 * 
 */
void close_directory(DIR *dir) {

    closedir(dir);
    return;
}

/**
 * @brief Creates a file at path.
 * 
 * 
 * 
 * @param path The path for the file to be created.
 * 
 * @return 
 */
FILE *create_file(const char *path) {

    FILE* file = fopen(path, "a");
    if (file == NULL) {
        printf("Failed to create the file: %s\n", path);
        exit(1);
    }
    return file;
}

/**
 * @brief Opens the file at path.
 * 
 * @param path The path of the file.
 * 
 * @return Returns the file's object.
 * 
 */
FILE *open_file(const char *path, char *flags) {

    FILE *file = fopen(path, flags);
    if (file == NULL) {
        printf("Failed to open the file: %s\n", path);
        exit(1);
    }
    return file;
}

/**
 * @brief Closes file.
 * 
 * @param file The file to be closed.
 * 
 */
void close_file(FILE *file) {

    fclose(file);
    return;
}

/**
 * @brief Returns the current working directory.
 * 
 * @return Returns the absolute path for the current working directory.
 * 
 */
char *get_cwd(void) {

    char *cwd = (char *)malloc(100);
    if (getcwd(cwd, 100) != NULL) {
        return cwd;
    } else {
        printf("Failed to get current working directory.\n");
        free(cwd);
        exit(1);
    }
}


/**
 * @brief Gets file size in bytes.
 * 
 * @param file  The file of which you're trying to find the size of.
 * 
 * @return The file's size in bytes.
 * 
 */
unsigned long get_file_size(FILE *file) {

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    return file_size;
}

/**
 * @brief Copies the contents of a file to a string.
 * 
 * Takes the text of the file and places it all into a string. This function assumes 
 * file_contents is large enough to handle all the contents.
 * 
 * @param file_contents An empty string of sufficient size to take the file's contents.
 * @param file_size The size of the file in bytes.
 * @param file The file object for which you're trying to copy the text of.
 * 
 * @pre file_contents is large enough to support all the content from the file.
 * 
 * @return Returns the number of bytes read; can be used for error handling.
 * 
 */
size_t copy_file_to_string(char *file_contents, long unsigned file_size, FILE *file) {

    size_t bytes_read = fread(file_contents, 1, file_size, file);
    if (bytes_read != file_size) {
        printf("Failed to read the file.\n");
        free(file_contents);
        fclose(file);
        exit(1);
    }

    return bytes_read;
}

/**
 * @brief Handles memory allocation for getting file text.
 * 
 * This function deals with the memory allocation needed for file_contents in the
 * copy_file_to_string function (above).
 * 
 * @param file The file object for which you're trying to copy the text of.
 * 
 * @return The string of the file's contents.
 * 
 */
char *get_file_text(FILE *file) {

    long unsigned file_size = get_file_size(file);

    char *file_contents = (char *)malloc(file_size + 1);
    if (file_contents == NULL) {
        printf("Failed to allocate memory.\n");
        close_file(file);
        exit(1);
    }

    copy_file_to_string(file_contents, file_size, file);
    file_contents[file_size] = '\0';

    return file_contents;
}