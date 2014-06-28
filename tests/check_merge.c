#include <check.h>
#include <stdlib.h>
#include "../src/merge.h"
#include "../src/quick_sort.h"
#include "../src/linked_list.h"
#include "../src/heap.h"
#include "../src/util.h"

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

START_TEST (test_partition)
{
  int list[] = {2, 8, 7, 1, 4, 5, 6, 3};
  partition(list, 8);
  ck_assert_int_eq(list[0], 2);
  ck_assert_int_eq(list[1], 1);
  ck_assert_int_eq(list[2], 3);
  ck_assert_int_eq(list[3], 4);
  ck_assert_int_eq(list[4], 7);
  ck_assert_int_eq(list[5], 5);
  ck_assert_int_eq(list[6], 6);
  ck_assert_int_eq(list[7], 8);
}
END_TEST

START_TEST (test_quick_sort)
{
  int list[] = {3, 1, 2, 7, 5, 6};
  quick_sort(list, 6);
  ck_assert_int_eq(list[0], 1);
  ck_assert_int_eq(list[1], 2);
  ck_assert_int_eq(list[2], 3);
  ck_assert_int_eq(list[3], 5);
  ck_assert_int_eq(list[4], 6);
  ck_assert_int_eq(list[5], 7);
}
END_TEST

START_TEST (test_linked_list_create)
{
  int data[] = {1, 2, 3, 4, 5, 6};
  node *list = linked_list_create(data, 6);
  node *current = list;
  ck_assert_int_eq(current->data, 1);
  current = current->next;
  ck_assert_int_eq(current->data, 2);
  current = current->next;
  ck_assert_int_eq(current->data, 3);
  current = current->next;
  ck_assert_int_eq(current->data, 4);
  current = current->next;
  ck_assert_int_eq(current->data, 5);
  current = current->next;
  ck_assert_int_eq(current->data, 6);
}
END_TEST

START_TEST (test_linked_list_reverse)
{
  int data[] = {1, 2, 3, 4, 5, 6};
  node *list = linked_list_create(data, 6);
  list = linked_list_reverse(list);
  node *current = list;
  ck_assert_int_eq(current->data, 6);
  current = current->next;
  ck_assert_int_eq(current->data, 5);
  current = current->next;
  ck_assert_int_eq(current->data, 4);
  current = current->next;
  ck_assert_int_eq(current->data, 3);
  current = current->next;
  ck_assert_int_eq(current->data, 2);
  current = current->next;
  ck_assert_int_eq(current->data, 1);
}
END_TEST

START_TEST (test_heapify)
{
  int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  heapify(data, 9);
  print_heap(data, 9);
  for (int i = 0; i < 9/2; i++) {
    ck_assert_int_ge(data[i], data[heap_left(i)]);
    ck_assert_int_ge(data[i], data[heap_right(i)]);
  }
}
END_TEST

Suite *merge_suite(void) {
  Suite *s = suite_create("Algorithms");
  TCase *ms = tcase_create("Merge Sort");
  tcase_add_test(ms, test_merge);
  suite_add_tcase(s, ms);
  TCase *qs = tcase_create("Quick Sort");
  tcase_add_test(qs, test_partition);
  tcase_add_test(qs, test_quick_sort);
  suite_add_tcase(s, qs);
  TCase *ll = tcase_create("Linked List");
  tcase_add_test(ll, test_linked_list_create);
  tcase_add_test(ll, test_linked_list_reverse);
  suite_add_tcase(s, ll);
  TCase *heap = tcase_create("Heaps");
  tcase_add_test(heap, test_heapify);
  suite_add_tcase(s, heap);
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
