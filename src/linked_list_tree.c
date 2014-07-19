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

llt_node* llt_add_after(llt_node* prev, int value) {
  if (prev == NULL) {
    return NULL;
  }
  llt_node* orig_next = prev->next;
  llt_node* new_node = malloc(sizeof(llt_node));
  prev->next = new_node;
  new_node->next = orig_next;
  new_node->prev = prev;
  new_node->child = NULL;
  new_node->value = value;
  if (orig_next != NULL) {
    orig_next->prev = prev->next;
  }
  return new_node;
}

void llt_flatten(llt* list) {
  llt_node* current = list->head;
  while (current != NULL) {
    if (current->child != NULL) {
      // copy child list to end of this list
      list->tail->next = current->child;
      // set child's prev link
      list->tail->next->prev = list->tail;
      // move tail to end of child data
      llt_node* current2 = list->tail->next;
      while (current2->next) {
        current2 = current2->next;
      }
      list->tail = current2;
    }
    current = current->next;
  }
}