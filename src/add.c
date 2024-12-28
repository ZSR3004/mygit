/**
 * @file add.c
 * @author Ziyad Rahman
 * @brief Implementation file for the "mygit add" command.
 * 
 * This file handles staging for the "mygit add" command. The stage_file function is
 * the core of this file and the command. All other functions either parse user input,
 * loop over files, or assist in blob creation.
 * 
 * When the "add" command is triggered, the program takes the argument (that is, the 
 * string right after "add") and enters the add_command_cases function.
 * 
 * That function determines if the input was a file or a directory and enters either the
 * stage_file or stage_directory function respectively. The stage_directory just loops
 * through the directory and its subdirectory at the provided path until it hits a file
 * to stage.
 * 
 * To be clear, during the staging process, only files are indexed and directories are left
 * mostly alone. The stage_directory function is just a means to loop through a directory and
 * refers to the process of automating the staging of the files inside of that directory, not
 * the directory itself.
 * 
 * @related See staging.h and staging.c for more details on the abstraction and implementation
 *          of staging respectively.
 * 
 */

#include "../include/common.h"

/**
 * @brief Indexes the cases based on the given path.
 *
 * Indexes cases based on provided path where "." represents current working directory. 
 * If a "/" is the first character of the path, then this function treats it as a directory, 
 * otherwise it treats it like a file.
 *
 * @param path Path to be indexed.
 */
void add_cases(char *arg) {
     if (strcmp(arg, ".") == 0) {
        char *cwd = get_cwd();
        add_dir(cwd);
        free(cwd);
    } else if (strcmp(arg, "/") == 0) {
        add_dir(arg);
    } else {
        add_file(arg);
    }
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
void add_file(char *path) {
    FILE *file = open_file(path, "r");
    index_add(file, path);
    node *bt = bt_deserialize();

    bt_insert(file, bt);
    bt_serialize(bt);
}

/**
 * @brief Indexes a directory when added using the mygit add command.
 * 
 * Indexes directories by either indexing any files in the directory or 
 * entering a subdirectory through recursive calling.
 * 
 * @param path The path given by the user in the mygit add command.
 * 
 * @todo: Implement ignore feature.
 * 
 */
void add_dir(char *path) {
    DIR *dir = open_directory(path);
    struct dirent *entry;
    char full_path[275];
    struct stat entry_stat;

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
        if (stat(full_path, &entry_stat) == 0) {
            if (S_ISDIR(entry_stat.st_mode)) {
                add_dir(full_path);
            } else if (S_ISREG(entry_stat.st_mode)) {
                add_file(full_path);
            }
        } 
    }
    closedir(dir);
}