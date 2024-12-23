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

#include "add.h"
#include "commit.h"
#include "init.h"
#include "staging.h"
#include "utils/file.h"
#include "utils/hash/hash_map.h"
#include "objects/blob.h"
#include "objects/commitObj.h"
#include "objects/tree.h"

#endif // COMMON_H