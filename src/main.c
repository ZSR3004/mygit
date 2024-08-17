#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "../include/help.h"
#include "../include/memory.h"
#include "../include/init.h"

int main(int argc, char *argv[]) {

    if (argc == 1) {
        gen_help();
    } else if (argc > 1) {
        switch (argv[1][0]) {
            case 'i':
                create_directory(".mygit", 0777);
            case 'c':
                // Code to handle argument 'b'
                break;
            case 'l':
                // Code to handle argument 'c'
                break;
            default:
                // Code to handle unknown argument
                break;
        }

    }

    return 0;

}