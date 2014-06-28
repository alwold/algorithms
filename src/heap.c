#include "heap.h"

void heapify(int *heap, int count) {
  for (int i = count/2; i >= 0; i--) {
    max_heapify(heap, i, count-1);
  }
}

int heap_left(int i) {
  return 2*i+1;
}

int heap_right(int i) {
  return 2*i+2;
}

void max_heapify(int *heap, int i, int end) {
  int largest = i;
  if (heap_left(i) <= end && heap[heap_left(i)] > heap[largest]) {
    largest = heap_left(i);
  }
  if (heap_right(i) <= end && heap[heap_right(i)] > heap[largest]) {
    largest = heap_right(i);
  }
  if (largest != i) {
    int x = heap[i];
    heap[i] = heap[largest];
    heap[largest] = x;
    max_heapify(heap, largest, end);
  }
}

void heap_sort(int *list, int count) {
  heapify(list, count);
  int heap_start = 0;
  for (int i = count-1; i > 0; i--) {
    int x = list[i];
    list[i] = list[0];
    list[0] = x;
    count--;
    max_heapify(list, 0, count-1);
  }
}