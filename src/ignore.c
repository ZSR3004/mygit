#include "../include/ignore.h"

/**
 * @brief Constants needed for handling memory allocation of the ignoreList.
 * 
 * @todo Move these defintions to the header file so the ignoreList representation
 *          is more complete.
 * 
 */
const int INIT_CAPACITY = 10;
const int GROWTH_FACTOR = 1.5;

/**
 * @brief Inits an ignoreList.
 * 
 * Allocates memory for the ignoreList, iL. Inits with 
 * iL->capacity = INIT_CAPACITY = 10.
 * 
 * @return A valid representation of an ignoreList.
 * 
 */
ignoreList *init_ignoreList() {

    ignoreList *iL = malloc(sizeof(ignoreList));
    iL->arr = malloc(sizeof(char) * INIT_CAPACITY);
    iL->capacity = INIT_CAPACITY;
    iL->count = 0;

    return iL;

}

/**
 * @brief Grows the capacity of an ignoreList.
 * 
 * Re-allocates memory for the ignoreList to grow it by 
 * GROWTH_FACTOR = 1.5.
 * 
 * @param iL Valid ignoreList.
 * 
 * @return The re-allocated ignoreList.
 * 
 */
ignoreList *grow_ignoreList(ignoreList *iL) {

    iL->capacity *= GROWTH_FACTOR;
    iL->arr = realloc(iL->arr, sizeof(char) * iL->capacity);
    return iL;

}

/**
 * @brief Inserts an item into the ignoreList.
 * 
 * @param iL Valid ignoreList.
 * @param item The item to be inserted.
 * 
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
 * @brief Creates an ignoreList based on .mygitignore.
 * 
 * Inits an ignoreList containing the files and directories detailed in
 * the local .mygitignore file. 
 * 
 * @return A valid representation of an ignoreList.
 *  
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
 * @brief Determines if an item is in the ignoreList.
 * 
 * @param iL Valid ignoreList.
 * @param item The item to look for.
 * 
 * @return  true if item is in iL
 *          else, false.
 * 
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
 * @brief Prints the ignoreList.
 * 
 * Prints iL, mostly for debugging purposes.
 * 
 * @param iL Valid ignoreList.
 * 
 */
void debug_print_ignoreList(ignoreList *iL) {

    printf("Ignore List:\n");
    for (int i = 0; i < iL->count; i++) {
        printf("\t%s\n", iL->arr[i]);
    }

}

/**
 * @brief Frees allocated memory for ignoreList.
 * 
 * @param iL Valid ignoreList.
 *
 */
void free_ignoreList(ignoreList *iL) {

    free(iL->arr);
    free(iL);
    return;

}