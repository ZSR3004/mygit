#include "../include/common.h"

int main(int argc, char *argv[]) {

    if (argc == 1) {
        // Prints out a help message in the terminal.
    } else if (argc > 1) {
        if (strcmp(argv[1], "init") == 0) {
            printf("Come forth, INIT\n");
        } else if (strcmp(argv[1], "add") == 0) {
            printf("Come forth, ADD\n");
        } else if (strcmp(argv[1], "commit") == 0) {
            printf("Come forth, COMMIT\n");
        } else {
            printf("Invalid myGit command.\n");
        }
    }

    return 0;

}