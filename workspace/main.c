#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {

    char line[] = "/home/zsr/curr_proj/mygit/tests/test_repo_one/src/main.c, 343220626974730a70726f6772616d0a0a746573745f7478745f6e652e7478740a746573745f7478745f74776f2e747874, 50";
    char *cwd = "/home/zsr/curr_proj/mygit/tests/test_repo_one";

    char *token = strtok(line, ", ");
    char *new_token = malloc((strlen(token) + 1) * sizeof(char));
    strcpy(new_token, token);
    char *needle = strrchr(new_token, '/');

    printf("output: %s\n", needle);

    free(new_token);

    return 0;
    
}