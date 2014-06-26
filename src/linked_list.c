#include "linked_list.h"
#include <stdlib.h>

node* linked_list_reverse(node* head) {
  if (head->next != NULL) {
    node *new_head = linked_list_reverse(head->next);
    node *current = new_head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = head;
    head->next = NULL;
    return new_head;
  } else {
    return head;
  }
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