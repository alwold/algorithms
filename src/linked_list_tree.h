#ifndef LINKED_LIST_TREE_H
#define LINKED_LIST_TREE_H

typedef struct llt_node {
  struct llt_node *next;
} llt_node;

llt_node* llt_create(int*, int);

#endif
