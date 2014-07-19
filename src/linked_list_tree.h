#ifndef LINKED_LIST_TREE_H
#define LINKED_LIST_TREE_H

typedef struct llt_node {
  struct llt_node *next;
  struct llt_node *prev;
  struct llt_node *child;
  int value;
} llt_node;

llt_node* llt_add(llt_node* head, int value);

#endif
