/**
 * @file branch.h
 * @brief Handles processes for the "mygit branch3" command.
 * 
 * 
 * 
 * @author Ziyad Rahman
 * 
 */

#ifndef BRANCH_H
#define BRANCH_H

char *init_branch(char *branch_name);
char *build_branch(char *branch_name);
void free_branch(char *branch);

void delete_branch(char *branch_name);

#endif // BRANCH_H