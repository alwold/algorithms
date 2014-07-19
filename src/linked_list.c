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

int linked_list_mth_last_element(node *head, int m) {
  // sample = {1, 2, 3, 4, 5, 6}
  // first advance the list to the mth position
  node* leading = head;
  // leading = 1
  for (int i = 0; i < m; i++) {
    leading = leading->next;
    // if we hit the end of the list, there's no mth last element, so return null
    if (leading == NULL) {
      return -1;
    }
  }
  // leading = 4
  node *trailing = head;
  // trailing = 1
  while (leading->next != NULL) {
    leading = leading->next;
    trailing = trailing->next;
  }
  // leading = 6
  // trailing = 3
  return trailing->data;
}