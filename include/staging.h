/**
 * @file staging.h
 * @brief Handles staging.
 * 
 * This header lays out the functions needed to properly stage files when the "mygit add" command
 * is used on them. It handles the creation of the index file and the functions for adding to that 
 * file.
 * 
 * Once the user has indicated a file (or directory) to be staged (see the add.h file), two things 
 * occur:
 *      1.  A blob object is created of that file and placed into the ".mygit/objects" directory (see
 *          the objects.h file for more on blobs and the add.h file for more on how they're stored).
 *      2.  The index file is updated with information about that file and its blob.
 * 
 * Only files are added to the index list (since only files can be turned into blobs). Directories are
 * recorded only once the "mygit commit" command is ran. So, the staging process only handles files,
 * not directories.
 * 
 * The index file is never cleared (while on the same branch). It is a running record of all files that
 * have been added. This is to prevent MyGit from adding the same file twice (ie, making a duplicate of
 * a file in the directory).
 * 
 * @author Ziyad Rahman
 * 
 */

#ifndef STAGING_H
#define STAGING_H

#include "file.h"

void create_blank_index(void);
void add_to_index(char *file_path, char *blob_hash, char *blob_size);

#endif // STAGING_H