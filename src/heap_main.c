#include "util.h"
#include "heap.h"

int main(int argc, char **argv) {
  int heap[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
  print_heap(heap, 11);
  heapify(heap, 11);
  print_heap(heap, 11);

  int list[] = {2, 4, 5, 7, 1, 6, 8, 11, 10, 3, 9};
  heap_sort(list, 11);
  print_list(list, 11);
  return 0;
}