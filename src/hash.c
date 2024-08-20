#include "../include/hash.h"

/**
 * @brief Hash function.
 * 
 * Converts each character of a string into its hexadecimal representation, 
 * then concatenates each hexadecimal.
 * 
 * @param str The string to be hashed.
 * 
 * @return Hashed string.
 */
char *hash_function(const char *str) {

    size_t len = strlen(str);
    char *hash = malloc((2 * len + 1) * sizeof(char) + 1);
    
    if (hash == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < len; i++) {
        sprintf(&hash[2 * i], "%02x", (unsigned char)str[i]);
    }

    hash[2 * len] = '\0';
    
    return hash;
}