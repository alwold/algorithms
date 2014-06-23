#include <check.h>
#include <stdlib.h>
#include "../src/merge.h"

START_TEST (test_merge)
{
  int list[] = {3, 1, 2, 7, 5, 6};
  int *new_list = sort(list, 6);
  ck_assert_int_eq(new_list[0], 1);
  ck_assert_int_eq(new_list[1], 2);
  ck_assert_int_eq(new_list[2], 3);
  ck_assert_int_eq(new_list[3], 5);
  ck_assert_int_eq(new_list[4], 6);
  ck_assert_int_eq(new_list[5], 7);
  free(new_list);
}
END_TEST

Suite *merge_suite(void) {
  Suite *s = suite_create("Merge Sort");
  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_merge);
  suite_add_tcase(s, tc_core);
  return s;
}

int main(void) {
  int number_failed;
  Suite *s = merge_suite();
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
