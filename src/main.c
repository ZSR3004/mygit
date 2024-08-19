#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "../include/help.h"
#include "../include/memory.h"
#include "../include/init.h"
#include "../include/hash.h"
#include "../include/add.h"
#include "../include/ignore.h"

int main(int argc, char *argv[]) {

    if (argc == 1) { // used for debugging at the moment; usually takes you to the general help menu
        gen_help();
    } else if (argc > 1) {
        char command[100];
        strcpy(command, argv[1]);
        if (strcmp(command, "init") == 0) {
            init_mygit_directory();
        } else if (strcmp(command, "add") == 0) {
            index_cases(argv[2]);
        } else if (strcmp(command, "commit") == 0) {
            //code
        } else if (strcmp(command, "log") == 0) {
            // code
        } else {
            // code
        }
    }

    return 0;

}