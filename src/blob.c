#include "../include/common.h"

node *init_bt(FILE *file) {
    node *n = malloc(sizeof(node));
    n->contents = get_file_text(file);
    n->hash = object_hash(n->contents);
    n->left = NULL;
    n->right = NULL;
    return n;
}

void free_bt(node *bt) {
    if (bt == NULL) return;
    
    free(bt->contents);
    free(bt->hash);

    free_bt(bt->left);
    free_bt(bt->right);
    free(bt);
}

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

void bt_serialize(node *root) {
    return;
}

node *bt_deserialize() {
    return NULL;
}