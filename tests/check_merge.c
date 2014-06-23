#include <check.h>
#include "../src/merge.h"

START_TEST (test_merge)
{
  int list[] = {3, 1, 2, 7, 5, 6};
  int *new_list = sort(list, 6);
  ck_assert_int_eq(new_list[0], 1);
  ck_assert_int_eq(new_list[1], 2);
  ck_assert_int_eq(new_list[2], 3);
  ck_assert_int_eq(new_list[3], 4);
  ck_assert_int_eq(new_list[4], 5);
  ck_assert_int_eq(new_list[5], 6);
  free(new_list);
}
END_TEST

int main(void) {
  return 0;
}