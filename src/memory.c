#include "../include/memory.h"

void create_directory(char* path, int permissions) {
    int status = mkdir(path, permissions);

    if (status != 0) {
        printf("Error creating directory.\n");
        exit(1);
    }

}