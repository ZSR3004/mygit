#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "../include/help.h"
#include "../include/memory.h"
#include "../include/init.h"
#include "../include/hash.h"
#include "../include/add.h"

int main(int argc, char *argv[]) {

    if (argc == 1) { // Used for debugging, normally would print instructions for basic use
        // gen_help();
        
        index_file("tests/test_repo_one/src/main.c");

    } else if (argc > 1) {
        switch (argv[1][0]) {
            case 'i':
                init_mygit_directory();

            case 'c':
                
                break;
            case 'l':
               
                break;
            default:

                break;
        }

    }

    return 0;

}