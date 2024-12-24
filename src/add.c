#include "../include/common.h"


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

void add_file(char *path) {
    FILE *file = open_file(path, "r");
    index_add(path, file);
    node *bt = bt_deserialize();

    bt_insert(file, bt);
    bt_serialize(bt);
}

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