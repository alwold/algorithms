#include "linked_list.h"
#include <stdlib.h>

node* linked_list_reverse(node* head) {
  return head;
}

node* linked_list_create(int* data, int count) {
  node *head = NULL;
  node *last = NULL;
  for (int i = 0; i < count; i++) {
    node *current = malloc(sizeof(node));
    current->data = data[i];
    current->next = NULL;
    if (last) {
      last->next = current;
    }
    if (!head) {
      head = current;
    }
    last = current;
  }
  return head;
}