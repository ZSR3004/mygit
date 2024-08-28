#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef enum {
    FILE_SUBTREE,
    DIR_SUBTREE
} SUBTREE_TYPE;

// #define CWD "/home/zsr/curr_proj/mygit/workspace/tree.c"

typedef struct subtree_cache subtree_cache;
struct subtree_cache{
    struct tree_cache *tree_cache;
    SUBTREE_TYPE type;
    char *name;
    int namelen;
    bool used;
};

typedef struct tree_cache tree_cache;
struct tree_cache{
    int entry_count;
    subtree_cache **down;
};

subtree_cache *init_subtree_cache(void) {
    subtree_cache *stc = malloc(sizeof(subtree_cache));
    stc->tree_cache = NULL;
    stc->name = NULL;
    stc->namelen = -1;
    stc->used = false; 
    return stc;
}

tree_cache *init_tree_cache(void) {
    tree_cache *tc = malloc(sizeof(tree_cache));
    tc->entry_count = 0;
    tc->down = NULL;
    return tc;
}

/**
 * @todo: make it for the directory thing too.
 */
char *get_name(char line[], int type) {
    char *token = strtok(line, ", ");
    if (token != NULL) {

        char *name_p = strrchr(token, '/');
        switch (type) {
            case FILE_SUBTREE:
                if (name_p != NULL) {
                    char *name = malloc(strlen(name_p) + 1);
                    strcpy(name, name_p);
                    return name + 1;
                } else {
                    char *name = malloc(strlen(token) + 1);
                    strcpy(name, token);
                    return name;
                } 

            case DIR_SUBTREE:
                if (name_p != NULL) {
                    char *name = malloc((strlen(name_p) + 1) * sizeof(char));
                    name[0] = '/';
                    size_t length = name_p - token + 1;
                    strncpy(name + 1, token, length - 1);
                    name[length] = '\0';
                    return name;
                }

            default:
                printf("This was an invalid input...\n");
                exit(1);
        }

    } else {
            printf("Failed to tokenize %s\n", line);
        }

        

    return NULL;
}

bool is_index_file(char line[], tree_cache *tc) {
    if (strstr(line, "/") != NULL) {
        return false;
    } else {
        return true;
    }
}

int dir_in_tree(char *line, tree_cache *tc) {
    char *name = get_name(line, DIR_SUBTREE);
    for (int i = 0; i < tc->entry_count; i++) {
        if (!strcmp(tc->down[i]->name, name)) {
            return i;
        }
    }

    return -1;

}

void recursive_tree_insert(tree_cache *tc, char *line) {

    char *line_copy = malloc(strlen(line) *sizeof(char));
    strcpy(line_copy, line);

    if (is_index_file(line_copy, tc) == true) {

        subtree_cache *stc = init_subtree_cache();
        stc->name = get_name(line_copy, FILE_SUBTREE);
        stc->namelen = strlen(stc->name);
        stc->type = FILE_SUBTREE;
        stc->tree_cache = NULL;

        tc->down[tc->entry_count] = stc;
        tc->entry_count++;

        return;
    }
    
    int det_pos = dir_in_tree(line_copy, tc);

    if (det_pos > -1) {

        char *new_line = strchr(line, '/') + 1;
        return recursive_tree_insert(tc->down[det_pos]->tree_cache, new_line);

    } else if (det_pos == -1) {

        subtree_cache *stc = init_subtree_cache();
        stc->name = get_name(line_copy, DIR_SUBTREE); // of subdir
        stc->namelen = strlen(stc->name);
        stc->type = DIR_SUBTREE;
        stc->tree_cache = init_tree_cache();
        stc->tree_cache->down = malloc(sizeof(subtree_cache) * 25);

        tc->down[tc->entry_count] = stc;
        tc->entry_count++;

        char *new_line = strchr(line, '/') + 1;
        
        return recursive_tree_insert(tc->down[tc->entry_count - 1]->tree_cache, new_line);
    }
}

void free_subtree_cache(subtree_cache *stc) {
    free(stc);
    return;
}

void recursive_free_tree_cache(tree_cache *tc) {

    for (int i = 0; i < tc->entry_count; i++) {
        if (tc->down[i] == NULL) continue;

        if (tc->down[i]->type == FILE_SUBTREE) {
            free_subtree_cache(tc->down[i]);
        } else if (tc->down[i]->type == DIR_SUBTREE) {
            recursive_free_tree_cache(tc->down[i]->tree_cache);
            free_subtree_cache(tc->down[i]);
        }

    }
    
    free(tc->down);
    free(tc);

}

void print_tc(tree_cache *tc, int depth) {
    for (int i = 0; i < tc->entry_count; i++) {
        if (tc->down[i] == NULL) continue;

        for (int j = 0; j < depth; j++) printf("\t");

        if (tc->down[i]->type == FILE_SUBTREE) printf("%s\n", tc->down[i]->name);
        else if (tc->down[i]->type == DIR_SUBTREE) {

            printf("%s\n", tc->down[i]->name);
            print_tc(tc->down[i]->tree_cache, depth + 1);

        }
    }

}

void build_trees(FILE *index, tree_cache *tc) {
    fseek(index, 0, SEEK_SET);
    char line[BUFSIZ];
    char *cwd = "/home/zsr/curr_proj/mygit/tests/test_repo_one/";
    int offset = strlen(cwd);

    fgets(line, BUFSIZ, index); // Skip first line of size.
    fgets(line, BUFSIZ, index); // Skip second line of index.
    
    fseek(index, offset, SEEK_CUR);
    while (fgets(line, BUFSIZ, index)) {
        fseek(index, offset, SEEK_CUR);
        recursive_tree_insert(tc, line);
    }
}

int main(void) {

    FILE *index = fopen("index.txt", "r");

    tree_cache *working_tree = init_tree_cache();
    working_tree->down = malloc(sizeof(subtree_cache) * 25);

    build_trees(index, working_tree);

    printf("Printing Tree...\n");
    print_tc(working_tree, 0);


    recursive_free_tree_cache(working_tree);
    fclose(index);
    return 0;

}