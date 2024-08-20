#include "../include/init.h"

/**
 * @brief Creates the .mygit directory.
 * 
 */
void init_mygit_directory(void) {

    create_directory(".mygit");
    create_directory(".mygit/objects");
    create_directory(".mygit/index");
    create_directory(".mygit/info/");
    create_directory(".mygit/refs");
    create_directory(".mygit/refs/heads");
    create_directory(".mygit/HEAD");

    FILE *index_file = create_file(".mygit/index/index.txt");
    close_file(index_file);

    return;
    
}