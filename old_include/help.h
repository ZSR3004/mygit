/**
 * @file help.h
 * @brief Prints guidance for how to use MyGit.
 * 
 * This is the implementation file for the "mygit help" command. These functions prints
 * instructions to help users understand how to use the MyGit CLI. 
 * 
 * @author Ziyad Rahman
 * 
 */

#ifndef HELP_H
#define HELP_H

#include <stdio.h>

void gen_help(void);

void init_help(void);

void add_help(void);

void commit_help(void);

void log_help(void);

#endif // HELP_H