#include "quick_sort.h"
#include "merge.h"

int main(int argc, char **argv) {
  int list[] = {3, 4, 5, 1, 2, 6};
  quick_sort(list, 6);
  print_list(list, 6);
}