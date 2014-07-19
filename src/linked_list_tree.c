#include <stdlib.h>
#include "linked_list_tree.h"

llt_node* llt_add(llt_node* head, int value) {
  llt_node *new_node = malloc(sizeof(llt_node));
  new_node->value = value;
  new_node->next = NULL;
  new_node->prev = NULL;
  new_node->child = NULL;
  // if head is NULL, this is a new list, so just return new_node as head
  if (head == NULL) {
    return new_node;
  } else {
    // otherwise, find the end and attach
    llt_node *current = head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_node;
    new_node->prev = current;
    // return the original head
    return head;
  }
}