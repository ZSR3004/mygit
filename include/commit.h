/**
 * @file commit.h
 * @brief Header for the "mygit commit" command.
 * 
 * The "mygit commit" command is used after staging changes with the "mygit add" command. This
 * command sets all stages in stone by referencing the index file. The command does two things:
 *      1. Creates a tree object based on the index file.
 *      2. Creates a commit object (commitObj) to store metadata about the commit.
 * 
 * To learn more about these object types see objects.h and objects.c. To learn more about the
 * index file see staging.h, staging.c, add.h, and add.c.
 * 
 * The "commit" command can be written with a flag called the message flag. This flag is written
 * after "mygit commit" as either "--message" or "-m" for short. This flag indicates that the next
 * string (staring and ending with a single quotation mark) is the commit message. This operates
 * largely similar to Git's commit messages and can be used by someone to go back through commits
 * and see the purpose of each commit.
 * 
 * @author Ziyad Rahman
 * 
 */

#include "file.h"
#include "staging.h"
#include "tree.h"

void commit_changes(char *commit_message);