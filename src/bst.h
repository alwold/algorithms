#ifndef BST_H
#define BST_H

struct bst_node {
  struct bst_node* left;
  struct bst_node* right;
  int data;
};
typedef struct bst_node bst_node;

bst_node* bst_node_create(int data);

void bst_insert(bst_node* root, int data);

void bst_delete(bst_node* root, bst_node* target);

#endif