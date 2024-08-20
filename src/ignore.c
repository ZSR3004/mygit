#include "../include/ignore.h"

#define GROW_CAPACITY ()

const int INIT_CAPACITY = 10;
const int GROWTH_FACTOR = 1.5;

/**
 * @brief
 * 
 * 
 * 
 * @parameter
 * 
 * @return 
 */
ignoreList *init_ignoreList() {

    ignoreList *iL = malloc(sizeof(ignoreList));
    iL->arr = malloc(sizeof(char) * INIT_CAPACITY);
    iL->capacity = INIT_CAPACITY;
    iL->count = 0;

    return iL;

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
ignoreList *grow_ignoreList(ignoreList *iL) {

    iL->capacity *= GROWTH_FACTOR;
    iL->arr = realloc(iL->arr, sizeof(char) * iL->capacity);
    return iL;

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
void insert_ignoreList(ignoreList *iL, char *item) {

    if (iL->count + 1 > iL->capacity) {
        iL = grow_ignoreList(iL);
    }

    iL->arr[iL->count] = malloc(strlen(item) * sizeof(char));
    strcpy(iL->arr[iL->count], item);
    iL->count++;
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

/**
 * @brief
 * 
 * 
 * 
 * @parameter
 * 
 * @return 
 */
bool in_ignoreList(ignoreList *iL, dirent *item) {

    for (int i = 0; i < iL->count; i++) {
        if (strcmp(iL->arr[i], item->d_name) == 0) {
            return true;
        }
    }

    return false;

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
void debug_print_ignoreList(ignoreList *iL) {

    printf("Ignore List:\n");
    for (int i = 0; i < iL->count; i++) {
        printf("\t%s\n", iL->arr[i]);
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
void free_ignoreList(ignoreList *iL) {

    free(iL->arr);
    free(iL);
    return;

}