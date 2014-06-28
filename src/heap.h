#ifndef HEAP_H
#define HEAP_H

void heapify(int *heap, int count);

void max_heapify(int *heap, int i, int end);

void heap_sort(int *list, int count);

#endif