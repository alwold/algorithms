#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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

int* merge(int* list1, int count1, int* list2, int count2) {
  int *list = malloc(sizeof(int)*(count1+count2));
  int i = 0;
  int j = 0;
  int pos = 0;
  while (i < count1 && j < count2) {
    if (list1[i] <= list2[j]) {
      list[pos++] = list1[i++];
    } else {
      list[pos++] = list2[j++];
    }
  }
  while (i < count1) {
    list[pos++] = list1[i++];
  }
  while (j < count2) {
    list[pos++] = list2[j++];
  }
  return list;
}

int *sort(int *list, int count) {
  if (count == 1) {
    int *new_list = malloc(sizeof(int));
    new_list[0] = list[0];
    return new_list;
  } else if (sizeof(list) == 2) {
    // just put each element in a list and merge
    int l1[1];
    int l2[1];
    l1[0] = list[0];
    l2[0] = list[1];
    return merge(l1, 1, l2, 1);
  } else {
    // split the list in half, sort each, then merge
    int size1 = count/2;
    int size2 = count-size1;
    int list1[size1];
    int list2[size2];
    memcpy(list1, list, size1*sizeof(int));
    // memcpy(list2, &list[size1], size2*sizeof(int));
    memcpy(list2, list+size1, size2*sizeof(int));
    int* new_list1 = sort(list1, size1);
    int* new_list2 = sort(list2, size2);
    int* new_list = merge(new_list1, size1, new_list2, size2);
    free(new_list1);
    free(new_list2);
    return new_list;
  }
}

int main(int argc, char **argv) {
  int list[] = {3, 1, 2, 7, 5, 6};
  // int list[] = {1};
   int count = 6;
   int *new_list = sort(list, count);
   print_list(new_list, count);
}
