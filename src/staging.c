#include "../include/common.h"

void create_blank_index() {
    FILE *index = open_file(INDEX_PATH, "w");
    close_file(index);
}

void index_add(FILE *file, char *path) {
    fprintf(file, "%s;%s\n", 
            path,
            object_hash(get_file_text(file))
        );
}