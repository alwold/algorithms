#include "merge.h"
#include "util.h"

int main(int argc, char **argv) {
  int list[] = {3, 1, 2, 7, 5, 6};
  // int list[] = {1};
   int count = 6;
   int *new_list = sort(list, count);
   print_list(new_list, count);
}
