#include <check.h>
#include <stdlib.h>
#include <stdio.h>
#include "../src/merge.h"
#include "../src/quick_sort.h"
#include "../src/linked_list.h"
#include "../src/heap.h"
#include "../src/util.h"
#include "../src/bst.h"
#include "../src/linked_list_tree.h"
#include "../src/stack.h"
#include "../src/int.h"

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

START_TEST (test_linked_list_mth_last_element)
{
  int data[] = {1, 2, 3, 4, 5, 6};
  node *list = linked_list_create(data, 6);
  ck_assert_int_eq(linked_list_mth_last_element(list, 3), 3);
  list = linked_list_create(data, 3);
  ck_assert_int_eq(linked_list_mth_last_element(list, 0), 3);
  ck_assert_int_eq(linked_list_mth_last_element(list, 3), -1);
  ck_assert_int_eq(linked_list_mth_last_element(list, 2), 1);
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

START_TEST (test_heapsort)
{
  int list[] = {2, 8, 7, 1, 4, 5, 6, 3};
  int count = 8;
  heap_sort(list, count);
  int last = -1;
  for (int i = 0; i < count; i++) {
    ck_assert_int_ge(list[i], last);
    last = list[i];
  }
}
END_TEST

START_TEST (test_bst_node_create)
{
  bst_node *root = bst_node_create(1);
  ck_assert_ptr_eq(root->left, NULL);
  ck_assert_ptr_eq(root->right, NULL);
  ck_assert_int_eq(root->data, 1);
}
END_TEST

START_TEST (test_bst_insert)
{
  bst_node *root = bst_node_create(3);
  bst_insert(root, 5);

  ck_assert_ptr_eq(root->left, NULL);
  ck_assert_ptr_ne(root->right, NULL);
  ck_assert_int_eq(root->right->data, 5);
  ck_assert_ptr_eq(root->right->left, NULL);
  ck_assert_ptr_eq(root->right->right, NULL);

  bst_insert(root, 1);
  ck_assert_ptr_ne(root->left, NULL);
  ck_assert_int_eq(root->left->data, 1);

  bst_insert(root, 99);
  ck_assert_ptr_ne(root->right->right, NULL);
  ck_assert_int_eq(root->right->right->data, 99);
}
END_TEST

START_TEST (test_bst_successor)
{
  bst_node *root = bst_node_create(3);
  bst_insert(root, 6);
  bst_node* ten = bst_insert(root, 10);
  bst_insert(root, 1);
  bst_insert(root, 4);
  bst_insert(root, 2);
  bst_insert(root, 8);
  bst_insert(root, 9);
  bst_insert(root, 7);
  bst_node* five = bst_insert(root, 5);
  ck_assert_int_eq(bst_successor(five)->data, 6);
  ck_assert_ptr_eq(bst_successor(ten), NULL);
}
END_TEST

START_TEST (test_bst_delete)
{
  bst_node *root = bst_node_create(3);
  bst_insert(root, 5);
  bst_insert(root, 1);
  bst_insert(root, 99);

  bst_delete(root, root->right); // this one is the 5, and it has 99 under it, to the right
  // ck_assert_int_eq(root->right->data, 99);
}
END_TEST

START_TEST (test_bst_preorder_print)
{
  bst_node *root = bst_node_create(100);
  bst_insert(root, 50);
  bst_insert(root, 150);
  bst_insert(root, 25);
  bst_insert(root, 75);
  bst_insert(root, 125);
  bst_insert(root, 175);
  bst_insert(root, 110);

  char *str = bst_preorder_print(root);
  ck_assert_str_eq(str, "100 50 25 75 150 125 110 175 \n");

}
END_TEST

START_TEST (test_linked_list_tree)
{
  llt* list = llt_create();
  llt_add(list, 1);
  llt_add(list, 2);
  llt_add(list, 3);
  llt_add(list, 4);
  llt_add(list, 5);
  llt_add(list, 6);
  ck_assert_int_eq(list->head->value, 1);
  ck_assert_int_eq(list->head->next->next->value, 3);
  ck_assert_int_eq(list->head->next->prev->value, 1);
  ck_assert_int_eq(list->head->next->next->prev->value, 2);
  ck_assert_int_eq(list->tail->value, 6);
  ck_assert_int_eq(list->tail->prev->value, 5);
}
END_TEST

START_TEST (test_linked_list_tree_flatten)
{
  llt* list = llt_create();
  llt_node* l1_node = llt_add(list, 5);
  llt_node* l2_node = llt_add_child(l1_node, 6);
  l2_node = llt_add_after(l2_node, 25);
  llt_node* l3_node = llt_add_child(l2_node, 8);
  l2_node = llt_add_after(l2_node, 6);
  l3_node = llt_add_child(l2_node, 9);
  llt_add_child(l3_node, 7);
  llt_add(list, 33);
  llt_add(list, 17);
  l1_node = llt_add(list, 2);
  l2_node = llt_add_child(l1_node, 2);
  l3_node = llt_add_child(l2_node, 12);
  llt_node* l4_node = llt_add_child(l3_node, 21);
  llt_add_after(l4_node, 3);
  llt_add_after(l3_node, 5);
  llt_add_after(l2_node, 7);
  llt_add(list, 1);
  ck_assert_int_eq(list->head->child->value, 6);
  ck_assert_int_eq(list->head->child->next->value, 25);
  ck_assert_int_eq(list->head->child->next->child->value, 8);
  ck_assert_int_eq(list->head->next->next->next->child->value, 2);
  ck_assert_int_eq(list->head->next->next->next->child->next->value, 7);
  ck_assert_int_eq(list->head->next->next->next->child->child->value, 12);
  ck_assert_int_eq(list->head->next->next->next->child->child->child->next->value, 3);

  llt_flatten(list);

  llt_node *current = list->head->next->next->next->next->next; // set to just past the original end
  ck_assert_int_eq(current->value, 6);
  current = current->next;
  ck_assert_int_eq(current->value, 25);
  current = current->next;
  ck_assert_int_eq(current->value, 6);
  current = current->next;
  ck_assert_int_eq(current->value, 2);
  current = current->next;
  ck_assert_int_eq(current->value, 7);
  current = current->next;
  ck_assert_int_eq(current->value, 8);
  current = current->next;
  ck_assert_int_eq(current->value, 9);
  current = current->next;
  ck_assert_int_eq(current->value, 12);
  current = current->next;
  ck_assert_int_eq(current->value, 5);
  current = current->next;
  ck_assert_int_eq(current->value, 7);
  current = current->next;
  ck_assert_int_eq(current->value, 21);
  current = current->next;
  ck_assert_int_eq(current->value, 3);
  ck_assert_ptr_eq(current->next, NULL);
  ck_assert_ptr_eq(list->tail, current);
  current = current->prev;
  ck_assert_int_eq(current->value, 21);
  current = current->prev;
  ck_assert_int_eq(current->value, 7);
  current = current->prev;
  ck_assert_int_eq(current->value, 5);
  current = current->prev;
  ck_assert_int_eq(current->value, 12);
  // make sure original child relations are maintained
  ck_assert_int_eq(current->child->value, 21);
}
END_TEST

START_TEST (test_stack)
{
  stack *s = stack_init(10);
  int x = 1;
  stack_push(s, &x);
  int y = 2;
  stack_push(s, &y);
  int *a = (int *)stack_pop(s);
  ck_assert_int_eq(*a, 2);
  int *b = (int *)stack_pop(s);
  ck_assert_int_eq(*b, 1);
  ck_assert_ptr_eq(stack_pop(s), NULL);
}
END_TEST

START_TEST (test_int_to_str)
{
  ck_assert_str_eq(int_to_str(400), "400");
  ck_assert_str_eq(int_to_str(452), "452");
  ck_assert_str_eq(int_to_str(1238193821), "1238193821");
  ck_assert_str_eq(int_to_str(0), "0");
  ck_assert_str_eq(int_to_str(-134), "-134");
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
  tcase_add_test(ll, test_linked_list_mth_last_element);
  suite_add_tcase(s, ll);
  TCase *llt = tcase_create("Linked List Tree");
  tcase_add_test(llt, test_linked_list_tree_flatten);
  suite_add_tcase(s, llt);
  TCase *heap = tcase_create("Heaps");
  tcase_add_test(heap, test_heapify);
  tcase_add_test(heap, test_heapsort);
  suite_add_tcase(s, heap);
  TCase *bst = tcase_create("Binary Search Tree");
  tcase_add_test(bst, test_bst_node_create);
  tcase_add_test(bst, test_bst_insert);
  tcase_add_test(bst, test_bst_successor);
  tcase_add_test(bst, test_bst_delete);
  tcase_add_test(bst, test_bst_preorder_print);
  suite_add_tcase(s, bst);
  TCase *stack = tcase_create("Stack");
  tcase_add_test(stack, test_stack);
  suite_add_tcase(s, stack);
  TCase *i = tcase_create("Integer stuff");
  tcase_add_test(i, test_int_to_str);
  suite_add_tcase(s, i);
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
