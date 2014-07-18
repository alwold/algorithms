#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct node {
  struct node* next;
  int data;
};
typedef struct node node;

node* linked_list_create(int* data, int count);

node* linked_list_reverse(node* head);

int linked_list_mth_last_element(node *head, int m);

#endif