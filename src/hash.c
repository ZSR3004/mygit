#include "../include/hash.h"

char *hash_function(char* str) {
    size_t len = strlen(str);
    
    char *hash = (char *)malloc((2 * len + 1) * sizeof(char));
    
    for (size_t i = 0; i < len; i++) {
        sprintf(&hash[2 * i], "%02x", str[i]);
    }
    
    return hash;
}