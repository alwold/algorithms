#ifndef LINKED_LIST_TREE_H
#define LINKED_LIST_TREE_H

typedef struct llt {
  struct llt_node *head;
  struct llt_node *tail;
} llt;

typedef struct llt_node {
  struct llt_node *next;
  struct llt_node *prev;
  struct llt_node *child;
  int value;
} llt_node;

llt* llt_create();

void llt_add(llt* list, int value);

#endif
