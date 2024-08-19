#include "../include/ignore.h"

#define GROW_CAPACITY ()

const int INIT_CAPACITY = 10;
const int GROWTH_FACTOR = 1.5;

ignoreList *init_ignoreList() {

    ignoreList *iL = malloc(sizeof(ignoreList));
    iL->arr = malloc(sizeof(char) * INIT_CAPACITY);
    iL->capacity = INIT_CAPACITY;
    iL->count = 0;

    return iL;

}

ignoreList *grow_ignoreList(ignoreList *iL) {

    iL->capacity *= GROWTH_FACTOR;
    iL->arr = realloc(iL->arr, sizeof(char) * iL->capacity);
    return iL;

}

void insert_ignoreList(ignoreList *iL, char *item) {

    if (iL->count + 1 > iL->capacity) {
        iL = grow_ignoreList(iL);
    }

    iL->arr[iL->count] = malloc(strlen(item) * sizeof(char));
    strcpy(iL->arr[iL->count], item);
    iL->count++;
    return;

}

ignoreList *build_ignoreList() {

    ignoreList *iL = init_ignoreList();


    char *path = get_cwd();
    strcat(path, "/.mygitignore");
    FILE *file = open_file(path, "r");

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '\n' || line[0] == '#') {
            continue;
        }
        line[strcspn(line, "\n")] = '\0';
        insert_ignoreList(iL, line);
    }

    close_file(file);

    return iL;

}

bool in_ignoreList(ignoreList *iL, char *item) {

    for (int i = 0; i < iL->count; i++) {
        if (strcmp(iL->arr[i], item) == 0) {
            return true;
        }
    }

    return false;

}

void debug_print_ignoreList(ignoreList *iL) {

    printf("Ignore List:\n");
    for (int i = 0; i < iL->count; i++) {
        printf("\t%s\n", iL->arr[i]);
    }

}

void free_ignoreList(ignoreList *iL) {

    free(iL->arr);
    free(iL);
    return;

}