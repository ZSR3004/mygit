#include "../include/common.h"

/**
 * @brief Initializes a binary tree node with the contents of a given file.
 *
 * This function allocates memory for a new binary tree node, reads the contents
 * of the provided file, computes the hash of the contents, and initializes the
 * left and right child pointers to NULL.
 *
 * @param file A pointer to the file to be read.
 * @return A pointer to the newly created binary tree node.
 */
node *init_bt(FILE *file) {
    node *n = malloc(sizeof(node));
    n->contents = get_file_text(file);
    n->hash = object_hash(n->contents);
    n->left = NULL;
    n->right = NULL;
    return n;
}

/**
 * @brief Frees the memory allocated for a binary tree.
 *
 * This function recursively frees the memory allocated for the nodes of a binary tree.
 * It first frees the contents and hash of the current node, then recursively frees
 * the left and right subtrees, and finally frees the current node itself.
 *
 * @param bt Pointer to the root node of the binary tree.
 */
void free_bt(node *bt) {
    if (bt == NULL) return;
    
    free(bt->contents);
    free(bt->hash);

    free_bt(bt->left);
    free_bt(bt->right);
    free(bt);
}

/**
 * @brief Inserts a new node into a binary tree.
 *
 * This function inserts a new node into the binary tree based on the hash value
 * of the file. It initializes a new node with the given file, then compares the
 * hash value of the new node with the current node to determine whether to insert
 * it into the left or right subtree. The function is called recursively until the
 * correct position is found.
 *
 * @param file Pointer to the file to be inserted into the binary tree.
 * @param bt Pointer to the root node of the binary tree.
 */
void bt_insert(FILE *file, node *bt) {
    node *new_node = init_bt(file);
    if (strcmp(new_node->hash, bt->hash) < 0) {
        if (bt->left == NULL) {
            bt->left = new_node;
        } else {
            bt_insert(file, bt->left);
        }
    } else {
        if (bt->right == NULL) {
            bt->right = new_node;
        } else {
            bt_insert(file, bt->right);
        }
    }
}

/**
 * @brief Deletes a node with the given hash from the binary tree.
 *
 * This function searches for a node with the specified hash in the binary tree
 * and deletes it. If the node to be deleted has two children, it finds the
 * in-order successor (smallest node in the right subtree) and replaces the
 * node's hash and contents with the successor's hash and contents, then deletes
 * the successor node.
 *
 * @param hash The hash of the node to be deleted.
 * @param bt The root of the binary tree.
 */
void bt_delete(char *hash, node *bt) {
    if (bt == NULL) return;

    if (strcmp(hash, bt->hash) < 0) {
        bt_delete(hash, bt->left);
    } else if (strcmp(hash, bt->hash) > 0) {
        bt_delete(hash, bt->right);
    } else {
        if (bt->left == NULL && bt->right == NULL) {
            free_bt(bt);
        } else if (bt->left == NULL) {
            node *temp = bt->right;
            *bt = *temp;
            free(temp);
        } else if (bt->right == NULL) {
            node *temp = bt->left;
            *bt = *temp;
            free(temp);
        } else {
            node *temp = bt->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            bt->hash = temp->hash;
            bt->contents = temp->contents;
            bt_delete(temp->hash, bt->right);
        }
    }
}

/**
 * @brief Looks up a node with the given hash in the binary tree.
 *
 * This function searches for a node with the specified hash in the binary tree
 * and returns a pointer to the node if found. If the node is not found, it
 * returns NULL.
 *
 * @param hash The hash of the node to be looked up.
 * @param bt The root of the binary tree.
 * @return A pointer to the node with the specified hash, or NULL if not found.
 */
node *bt_lookup(char *hash, node *bt) {
    if (bt == NULL) return NULL;

    if (strcmp(hash, bt->hash) == 0) {
        return bt;
    } else if (strcmp(hash, bt->hash) < 0) {
        return bt_lookup(hash, bt->left);
    } else {
        return bt_lookup(hash, bt->right);
    }
}

/**
 * @brief Serializes a binary tree to a specific format.
 *
 * This function takes the root of a binary tree and serializes it into the 
 * objects.bin file.
 *
 * @param root The root node of the binary tree to be serialized.
 */
void bt_serialize(node *root) {
    return;
}

/**
 * @brief Deserializes a binary tree from a specific format.
 *
 * This function deserializes a binary tree and returns the root node based on the 
 * objects.bin file.
 *
 * @return The root node of the deserialized binary tree, or NULL if deserialization 
 * fails.
 */
node *bt_deserialize() {
    return NULL;
}