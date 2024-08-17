#include "../include/init.h"

const int STANDARD_PERM = 0755;

void init_mygit_directory(void) {

    create_directory(".mygit", STANDARD_PERM);
    create_directory(".mygit/objects", STANDARD_PERM);
    create_directory(".mygit/index", STANDARD_PERM);
    create_directory(".mygit/refs", STANDARD_PERM);
    create_directory(".mygit/refs/heads", STANDARD_PERM);
    create_directory(".mygit/HEAD", STANDARD_PERM);

}