#include "../include/commit.h"

/**
 * 
 */

void commit_changes(char *commit_message) {

    FILE *index = open_file("/home/zsr/curr_proj/mygit/tests/test_repo_one/.mygit/index/index.txt", "r");
    tree_cache *working_tree = init_tree_cache();
    working_tree->down = malloc(sizeof(subtree_cache) * 25);

    build_trees(index, working_tree, "/home/zsr/curr_proj/mygit/tests/test_repo_one/");

    print_tc(working_tree, 0);
    
    recursive_free_tree_cache(working_tree);
    close_file(index);

}