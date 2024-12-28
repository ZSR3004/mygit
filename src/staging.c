#include "../include/common.h"

/**
 * @brief Creates a blank index file.
 * 
 * This function opens the index file specified by INDEX_PATH in write mode,
 * effectively creating a new blank index file or truncating an existing one.
 * The file is then closed immediately.
 */
void create_blank_index() {
    FILE *index = open_file(INDEX_PATH, "w");
    close_file(index);
}

/**
 * @brief Adds a file entry to the index.
 * 
 * @param file A pointer to the index file where the entry will be added.
 * @param path The path of the file to be added to the index.
 * 
 * This function writes an entry to the index file in the format "path;hash\n",
 * where 'path' is the provided file path and 'hash' is the hash of the file's
 * contents obtained by calling object_hash on the file's text.
 */
void index_add(FILE *file, char *path) {
    fprintf(file, "%s;%s\n", 
            path,
            object_hash(get_file_text(file))
        );
}