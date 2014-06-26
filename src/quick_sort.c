#include <stdio.h>
#include "quick_sort.h"
#include "util.h"

void quick_sort(int* list, int count) {
  if (count > 1) {
    int p_index = partition(list, count);
    if (p_index > 0) {
      printf("sorting sublist from 0-%d\n", p_index);
      quick_sort(list, p_index);
    }
    if (p_index < count-1) {
      printf("sorting sublist from %d-%d\n", p_index+1, count-(p_index+1));
      quick_sort(list+p_index+1, count-(p_index+1));
    }
  }
}

int partition(int *list, int count) {
  // pick partition from the middle
  int p = list[count/2];
  // put it at the end
  list[count/2] = list[count-1];
  list[count-1] = p;
  int list_1_end = -1;
  for (int list_2_end = 0; list_2_end < count-1; list_2_end++) {
    // if element less than partition, extend the list
    if (list[list_2_end] <= p) {
      list_1_end++;
      int x = list[list_1_end];
      list[list_1_end] = list[list_2_end];
      list[list_2_end] = x;
    }
  }
  // move the partition to the proper spot
  int x = list[count-1];
  list[count-1] = list[list_1_end+1];
  list[list_1_end+1] = x;
  return list_1_end+1;
}