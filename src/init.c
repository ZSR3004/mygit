#include "../include/init.h"

void init_mygit_directory(void) {

    create_directory(".mygit");
    create_directory(".mygit/objects");
    create_directory(".mygit/index");
    create_directory(".mygit/refs");
    create_directory(".mygit/refs/heads");
    create_directory(".mygit/HEAD");

}