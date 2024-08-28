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
#include "../include/tree.h"

int main(int argc, char *argv[]) {

    if (argc == 1) {

        FILE *index = fopen("/home/zsr/curr_proj/mygit/tests/test_repo_one/.mygit/index/index.txt", "r");

        tree_cache *working_tree = init_tree_cache();
        working_tree->down = malloc(sizeof(subtree_cache) * 25);
        
        build_trees(index, working_tree, "/home/zsr/curr_proj/mygit/tests/test_repo_one/");

        printf("Printing Tree...\n");
        print_tc(working_tree, 0);


        recursive_free_tree_cache(working_tree);
        fclose(index);
        return 0;
        
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