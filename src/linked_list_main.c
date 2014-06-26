#include "linked_list.h"
#include "util.h"

int main(int argc, char** argv) {
  int data[] = {1, 2, 3, 4, 5, 6};
  node *list = linked_list_create(data, 3);
  list = linked_list_reverse(list);
  print_linked_list(list);
  return 0;
}