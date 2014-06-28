#include <math.h>
#include <stdio.h>

#include "linked_list.h"

void print_list(int *new_list, int count) {
   for (int i = 0; i < count; i++) {
     printf("%d", new_list[i]);
     if (i != count-1) {
       printf(", ");
     } else {
       printf("\n");
     }
   }
}

void print_linked_list(node *head) {
  node* current = head;
  while (current) {
    printf("%d", current->data);
    if (current->next) {
      printf(", ");
    } else {
      printf("\n");
    }
    current = current->next;
  }
}

void print_heap(int *heap, int count) {
  int max_level = log2(count);
  int max_space = count/2;
  int last_level = 0;
  int level = 0;
  for (int i = 0; i < (max_space - pow(2, level)); i++) {
    printf(" ");
  }
  for (int i = 0; i < count; i++) {
    level = log2(i+1);
    if (level != last_level) {
      printf("\n");
      printf("\n");
      for (int i = 0; i < (max_space - pow(2, level)); i++) {
        printf(" ");
      }
    }
    last_level = level;
    printf("%d ", heap[i]);
  }
  printf("\n");
}
