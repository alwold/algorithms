#include <stdlib.h>

#include "bst.h"
#include "stack.h"

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
  if (source->right != NULL) {
    return source->right;
  } else {
    // go up the tree until we find an ancestor that is the left child of something
    // when that is true, the parent of the left child is the successor
    bst_node *ancestor = source->parent;
    while (ancestor && ancestor->right == source) {
      source = ancestor;
      ancestor = source->parent;
    }
    return ancestor;
  }
}

/**
 * preorder traversal without recursion
 */
char* bst_preorder_print(bst_node* root) {
  stack* s = stack_init(10);
  char *str = malloc(sizeof(char)*100);
  str[0] = 0;
  if (root != NULL) {
    stack_push(s, root);
    while ((root = (bst_node *)stack_pop(s)) != NULL) {
      sprintf(str + strlen(str), "%d ", root->data);
      if (root->right != NULL) {
        stack_push(s, root->right);
      }
      if (root->left != NULL) {
        stack_push(s, root->left);
      }
    }
    strcat(str, "\n");
    return str;
  }
}

