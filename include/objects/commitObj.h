/**
 * @file commitObj.h
 * @author Ziyad Rahman
 * @brief Handles the commit object for mygit.
 * @version 0.1
 * @date 2024-12-28
 * 
 * Below are the functions related to commit objects. Commit objects are abbreviated to commitObj to differentiate
 * them from the MyGit "commit" command.
 * 
 * A commit object stores metadata about each commit. When the commit command is ran, a new commit object is created that
 * details the state of the current working directory, the parent commit, and the author, and the commit message. You'll 
 * find these files in the following format:
 * 
 * tree <hash for the tree object of the current working directory>
 * parent <hash for the parent commit or "null" if it's the first one>
 * author <the person making the commit>
 * <the commit message>
 * 
 * For example, if John Doe makes a commit with the message "second commit", then it would appear as the following:
 * 
 * tree abcd1234
 * parent efgh5678
 * author 'John Doe'
 * second commit
 * 
 */

#ifndef COMMITOBJ_H
#define COMMITOBJ_H

#include "../common.h"

void create_commitObj();
void free_commitObj();

#endif // COMMITOBJ_H