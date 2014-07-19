#include "stack.h"

stack* stack_init(int capacity) {
  stack* s = malloc(sizeof(stack));
  s->stack = malloc(sizeof(void *)*capacity);
  s->top = -1;
  return s;
}

void* stack_pop(stack *s) {
  if (s->top != -1) {
    return s->stack[s->top--];
  } else {
    return NULL;
  }
}

void stack_push(stack *s, void* node) {
  s->stack[++s->top] = node;
}
