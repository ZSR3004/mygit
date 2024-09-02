#include "../include/commit.h"

typedef struct {

    int front;
    int count;
    subtree_cache **arr;

} stc_stack;

/**
 * 
 */

void commit_changes(char *commit_message) {

    FILE *index = open_file("/home/zsr/curr_proj/mygit/tests/test_repo_one/.mygit/index/index.txt", "r");
    tree_cache *working_tree = init_tree_cache();
    working_tree->down = malloc(sizeof(subtree_cache) * 25);

    build_trees(index, working_tree, "/home/zsr/curr_proj/mygit/tests/test_repo_one/");

    // print_tc(working_tree, 0);

    stc_stack *stack = malloc(sizeof(stc_stack));
    stack->arr = malloc(sizeof(subtree_cache) * 10);
    stack->front = 0;
    stack->count = 0;

    strArr *tree_arr = init_strArr();
    tree_write(working_tree, tree_arr);

    debug_print_strArr(tree_arr);

    // printf("I am printing this now: \n\n%s\n", tree_str);

    free_strArr(tree_arr);
    recursive_free_tree_cache(working_tree);
    close_file(index);

}