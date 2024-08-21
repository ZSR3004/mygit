#include "../include/strarr.h"

/**
 * @brief Constants needed for handling memory allocation of the strArr.
 * 
 * @todo Move these defintions to the header file so the strArr representation
 *          is more complete.
 * 
 */
const int INIT_CAPACITY = 10;
const int GROWTH_FACTOR = 1.5;

/**
 * @brief Inits an strArr.
 * 
 * Allocates memory for the strArr, sa. Inits with 
 * sa->capacity = INIT_CAPACITY = 10.
 * 
 * @return A valid representation of an strArr.
 * 
 */
strArr *init_strArr() {

    strArr *sa = malloc(sizeof(strArr));
    sa->items = malloc(sizeof(char) * INIT_CAPACITY);
    sa->capacity = INIT_CAPACITY;
    sa->count = 0;

    return sa;

}

/**
 * @brief Grows the capacity of an strArr.
 * 
 * Re-allocates memory for the strArr to grow it by 
 * GROWTH_FACTOR = 1.5.
 * 
 * @param sa Valid strArr.
 * 
 * @return The re-allocated strArr.
 * 
 */
strArr *grow_strArr(strArr *sa) {

    sa->capacity *= GROWTH_FACTOR;
    sa->items = realloc(sa->items, sizeof(char) * sa->capacity);
    return sa;

}

/**
 * @brief Inserts an item into the strArr.
 * 
 * @param sa Valid strArr.
 * @param item The item to be inserted.
 * 
 */
void insert_strArr(strArr *sa, char *item) {

    if (sa->count + 1 > sa->capacity) {
        sa = grow_strArr(sa);
    }

    sa->items[sa->count] = malloc(strlen(item) * sizeof(char));
    strcpy(sa->items[sa->count], item);
    sa->count++;
    return;

}

/**
 * @brief Creates an strArr based on .mygitignore.
 * 
 * Inits an strArr containing the files and directories detailed in
 * the local .mygitignore file. 
 * 
 * @return A valid representation of an strArr.
 *  
 */
strArr *build_strArr() {

    strArr *sa = init_strArr();


    char *path = get_cwd();
    strcat(path, "/.mygitignore");
    FILE *file = open_file(path, "r");

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '\n' || line[0] == '#') {
            continue;
        }
        line[strcspn(line, "\n")] = '\0';
        insert_strArr(sa, line);
    }

    close_file(file);

    return sa;

}

/**
 * @brief Determines if an item is in the strArr.
 * 
 * @param sa Valid strArr.
 * @param item The item to look for.
 * 
 * @return  true if item is in sa
 *          else, false.
 * 
 */
bool in_strArr(strArr *sa, dirent *item) {

    for (int i = 0; i < sa->count; i++) {
        if (strcmp(sa->items[i], item->d_name) == 0) {
            return true;
        }
    }

    return false;

}

/**
 * @brief Prints the strArr.
 * 
 * Prints sa, mostly for debugging purposes.
 * 
 * @param sa Valid strArr.
 * 
 */
void debug_print_strArr(strArr *sa) {

    printf("Ignore List:\n");
    for (int i = 0; i < sa->count; i++) {
        printf("\t%s\n", sa->items[i]);
    }

}

/**
 * @brief Frees allocated memory for strArr.
 * 
 * @param sa Valid strArr.
 *
 */
void free_strArr(strArr *sa) {

    free(sa->items);
    free(sa);
    return;

}