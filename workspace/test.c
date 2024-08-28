#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {

    char *line = "home/zsr/yasc";

    // char *last_slash = strrchr(line, '/');

    // printf("%s\n", last_slash);

    char *token = strtok(line, "/");
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, "/");
    }
  

    return 0;

}