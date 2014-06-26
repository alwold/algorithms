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