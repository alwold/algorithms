#include <stdlib.h>
#ifndef STACK_H
#define STACK_H

typedef struct stack {
  void** stack;
  int top;
} stack;

stack* stack_init(int capacity);
void* stack_pop(stack *s);
void stack_push(stack *s, void* node);

#endif
