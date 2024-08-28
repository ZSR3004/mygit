#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "../include/help.h"
#include "../include/file.h"
#include "../include/init.h"
#include "../include/hash.h"
#include "../include/add.h"
#include "../include/strarr.h"
#include "../include/tree_cache.h"
#include "../include/tree.h"
#include "../include/commit.h"

int main(int argc, char *argv[]) {

    if (argc == 1) {

        tree *t = init_tree(0, "some path", "some hash");
        write_tree_to_file(t);
        free_tree(t);

        // commit_changes("This is my message");
        
    } else if (argc > 1) {

        char command[100];
        strcpy(command, argv[1]);

        if (strcmp(command, "init") == 0) {
            init_mygit_directory();
        } else if (strcmp(command, "add") == 0) {
            add_command_cases(argv[2]);
        } else if (strcmp(command, "commit") == 0) {
            //code
        } else if (strcmp(command, "branch") == 0) {
            // code
        } else if (strcmp(command, "checkout") == 0) {
            // code
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;

}