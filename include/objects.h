/**
 * @file objects.h
 * @brief Header for initializing and freeing MyGit objects.
 * 
 * This file details the abstraction for each of the three MyGit objects. These objects
 * are:
 *      1.  Blobs: Stores file information.
 *      2.  Trees: Stores directory information.
 *      3.  Commits (which are referred to as Commit Objects or commitObj): Stores commit
 *          information
 * 
 * Each object file is titled with their hash, which is generated from the object file's
 * content, that is, every line of the plain-text file (see hash.h and hash.c for more). 
 * Objects are used in practically all commands.
 * 
 * The function headers in this file are grouped by objects (rather than what they do), and
 * you can find detailed explanations of each object directly above its section.
 * 
 * To learn about how these objects are used by each command is used you can refer to the
 * header and source files of the same name as the command.
 * 
 * @author Ziyad Rahman
 * 
 */

#ifndef OBJECTS_H
#define OBJECTS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "file.h"

/**
 * Below are the functions related to blob objects. 
 * 
 * A blob object is how MyGit keeps track of the various versions of a file when they are committed or added. Basically,
 * it stores a file's state (literally the text on the file) in it so it can be referenced by the MyGit later.
 * 
 * The blob object is a file that contains two pieces of infomation: the size of the file in bytes represented by the 
 * blob and the contents of that file. It will be in the following format:
 * 
 * blob     <number of bytes> bytes
 * <file contents>
 * 
 * For example, if you had a plain-text file with one line that said "Hello, World!" that was 12 bytes long the blob 
 * would be as follows:
 * 
 * blob     12 bytes
 * Hello, World!
 * 
 */
char *init_blob(unsigned long file_size, char *file_text);
char *build_blob(FILE *file);
void free_blob(char *blob);

/**
 * Below are the functions related to tree objects.
 * 
 * A tree object is the directory equivalent to the blob object. Basically, its a text file that holds all the files within
 * a given directory and points to any subdirectories.
 * 
 * For each object in the tree, there are three key pieces of information listed that follow this format for each line:
 *      <object type>   <object hash>   <object name>
 * 
 * For example, if your working directory looks like this:
 *      myproject/
 *      ├── file1.txt
 *      └── subdir/
 *          └── file2.txt
 *  
 * Then, the tree for the myproject directory would look like this:
 * 
 * blob     abcd1234    file1.txt
 * tree     efgh5678    subdir
 * 
 * And the tree of the subdir directory would look like:
 * 
 * blob     ijkl90  file2.txt
 * 
 * 
 */
char *init_tree(char *index_path);
char *add_to_tree(char *mode, char *object_type, char* object_hash, char *object_name);
char *build_tree(char *index_path);
void free_tree(char *tree);

/**
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
char *init_commitObj(char *tree_hash, char *parent_commitObj_hash, char *author_name);
char *build_commitObj(FILE *indexTable);
char *free_commitObj(char *commitObj);

#endif // OBJECTS_H