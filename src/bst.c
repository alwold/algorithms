#include <stdlib.h>

#include "bst.h"

bst_node* bst_node_create(int data) {
  bst_node* node = malloc(sizeof(bst_node));
  node->left = NULL;
  node->right = NULL;
  node->data = data;
  return node;
}

void bst_insert(bst_node* root, int data) {
  if (data <= root->data) {
    if (root->left == NULL) {
      root->left = bst_node_create(data);
    } else {
      bst_insert(root->left, data);
    }
  } else {
    if (root->right == NULL) {
      root->right = bst_node_create(data);
    } else {
      bst_insert(root->right, data);
    }
  }
}
