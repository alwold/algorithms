#include <stdlib.h>
#include "linked_list_tree.h"

llt* llt_create() {
  llt* list = malloc(sizeof(llt));
  list->head = NULL;
  list->tail = NULL;
  return list;
}

llt_node* llt_add(llt* list, int value) {
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
  return new_node;
}

llt_node* llt_add_child(llt_node* parent, int value) {
  if (parent->child != NULL) {
    // can't add, there's already something
    return NULL;
  }
  parent->child = malloc(sizeof(llt_node));
  parent->child->next = NULL;
  parent->child->prev = NULL;
  parent->child->child = NULL;
  parent->child->value = value;
  return parent->child;
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