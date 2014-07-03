#include <stdlib.h>

#include "bst.h"

bst_node* bst_node_create(int data) {
  bst_node* node = malloc(sizeof(bst_node));
  node->parent = NULL;
  node->left = NULL;
  node->right = NULL;
  node->data = data;
  return node;
}

bst_node* bst_insert(bst_node* root, int data) {
  if (data <= root->data) {
    if (root->left == NULL) {
      root->left = bst_node_create(data);
      root->left->parent = root;
      return root->left;
    } else {
      return bst_insert(root->left, data);
    }
  } else {
    if (root->right == NULL) {
      root->right = bst_node_create(data);
      root->right->parent = root;
      return root->right;
    } else {
      return bst_insert(root->right, data);
    }
  }
}

void bst_delete(bst_node* root, bst_node* target) {
  if (root->left == target) {
    if (target->left == NULL && target->right == NULL) {
      root->left = NULL;
    } else if (target->left == NULL && target->right != NULL) {
      root->left = target->right;
      return;
    } else if (target->right == NULL && target->left != NULL) {
      root->left = target->left;
    } else {
      
    }
  }
}

bst_node* bst_successor(bst_node* source) {
  return source;
}