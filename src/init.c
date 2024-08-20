#include "../include/init.h"

/**
 * @brief
 * 
 * 
 * 
 * @parameter
 * 
 * @return 
 */
void init_mygit_directory(void) {

    create_directory(".mygit");
    create_directory(".mygit/objects");
    create_directory(".mygit/index");
    create_file(".mygit/index/index.txt", "w");
    create_directory(".mygit/refs");
    create_directory(".mygit/refs/heads");
    create_directory(".mygit/HEAD");

}