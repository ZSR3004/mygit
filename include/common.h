#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <stddef.h>
#include <limits.h>

#include "add.h"
#include "commit.h"
#include "init.h"
#include "staging.h"
#include "utils/file.h"
#include "utils/hash.h"
#include "objects/objects.h"
#include "objects/commitObj.h"
#include "objects/tree.h"

#define INDEX_PATH "/.mygit/index.txt"

#endif // COMMON_H