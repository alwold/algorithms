#include <stdlib.h>
#include "linked_list_tree.h"

llt* llt_create() {
  llt* list = malloc(sizeof(llt));
  list->head = NULL;
  list->tail = NULL;
  return list;
}

void llt_add(llt* list, int value) {
  llt_node* new_node = malloc(sizeof(llt_node));
  new_node->value = value;
  new_node->next = NULL;
  new_node->prev = NULL;
  new_node->child = NULL;
  // if head is NULL, this is a new list, so just return new_node as head
  if (list->head == NULL) {
    list->head = new_node;
    list->tail = new_node;
  } else {
    // otherwise, find the end and attach
    llt_node *current = list->head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_node;
    new_node->prev = current;
    list->tail = new_node;
  }
}

void llt_flatten(llt_node* head) {
  llt_node* current = head;
  while (current != NULL) {
    if (current->child != NULL) {
      // move child list to end of this list
    }
    current = current->next;
  }
}