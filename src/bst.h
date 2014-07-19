#ifndef BST_H
#define BST_H

struct bst_node {
  struct bst_node* parent;
  struct bst_node* left;
  struct bst_node* right;
  int data;
};
typedef struct bst_node bst_node;

bst_node* bst_node_create(int data);

bst_node* bst_insert(bst_node* root, int data);

void bst_delete(bst_node* root, bst_node* target);

bst_node* bst_successor(bst_node* source);

char* bst_preorder_print(bst_node* root);

#endif