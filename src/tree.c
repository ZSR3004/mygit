#include "../include/tree.h"

tree *init_tree(OBJ_TYPE type, char *name, char *hash) {

    tree *t = malloc(sizeof(tree));
    t->type = type;
    t->name = name;
    t->hash = hash;
    return t;

}

void write_tree_to_file(OBJ_TYPE type, char *name, char *hash) {

    tree *t = init_tree(type, name, hash);

    char *index_location = create_index_location(t->hash);
    create_directory(index_location);

    char *final_path = malloc(strlen(index_location) + strlen(t->hash) + 1 + BUFSIZ);
    strcpy(final_path, index_location);
    strcat(final_path, "/");
    strcat(final_path, &t->hash[2]);
    strcat(final_path, ".txt");

    FILE *file = open_file(final_path, "w");

    fseek(file, 0, SEEK_END);
    fprintf(file, "%d, %s, %s", t->type, t->name, t->hash);

    close_file(file);
    free(index_location);
    free(final_path);
    free_tree(t);
    return;

}

void free_tree(tree *t) {
    free(t);
}