#include "../include/memory.h"
#include <unistd.h>

const int STANDARD_PERM = 0755;

/**
 * @brief
 * 
 * 
 * 
 * @parameter
 * 
 * @return 
 */
void create_directory(char* path) {

    if (access(path, F_OK) == 0) return;

    int status = mkdir(path, STANDARD_PERM);
    if (status != 0) {
        printf("Error creating directory: %s\n", path);
        exit(1);
    }

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
void create_file(char* path, char* mode) {
    FILE* file = fopen(path, mode);
    if (file == NULL) {
        printf("Failed to create the file: %s\n", path);
        exit(1);
    }
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
 * @brief
 * 
 * 
 * 
 * @parameter
 * 
 * @return 
 */
DIR *open_directory (char* path) {

    DIR* directory = opendir(path);
    if (directory == NULL) {
        printf("Failed to open directory: %s\n", path);
        exit(1);
    }
    return directory;

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
FILE *open_file(char *path, char *state) {
    FILE *file = fopen(path, state);
    if (file == NULL) {
        printf("Failed to open the file: %s\n", path);
        exit(1);
    }
    return file;
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
unsigned long get_file_size(FILE *file) {
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    return file_size;
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
 * @brief
 * 
 * 
 * 
 * @parameter
 * 
 * @return 
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

/**
 * @brief
 * 
 * 
 * 
 * @parameter
 * 
 * @return 
 */
void close_directory(DIR *directory) {
    closedir(directory);
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
void close_file(FILE *file) {
    fclose(file);
    return;
}