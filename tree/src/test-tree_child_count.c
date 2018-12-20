/**
 * \file test-tree.c
 * \brief testing program
 * \author Johan
 * \version 0.1
 * \date 15 november 2018
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "tree.h"
#include "tree.inc"

/**
 * Function to compare int (local)
 */
int compare_int(void *nb1, void *nb2) { return *(int *)nb1 - *(int *)nb2; }

int main(void) {
  int *one = malloc(sizeof(int));
  *one = 1;
  int *two = malloc(sizeof(int));
  *two = 2;
  int *three = malloc(sizeof(int));
  *three = 3;
  int *four = malloc(sizeof(int));
  *four = 4;
  int *five = malloc(sizeof(int));
  *five = 5;
  int *six = malloc(sizeof(int));
  *six = 6;
  int *seven = malloc(sizeof(int));
  *seven = 7;

  Tree *root = tree_new(NULL, compare_int);
  Tree *t1 = tree_new(one, compare_int);
  Tree *t2 = tree_new(two, compare_int);
  Tree *t3 = tree_new(three, compare_int);
  Tree *t4 = tree_new(four, compare_int);
  Tree *t5 = tree_new(five, compare_int);
  Tree *t6 = tree_new(six, compare_int);
  Tree *t7 = tree_new(seven, compare_int);

  tree_add_child(root, t1);  // root-1
  tree_add_child(t1, t2);    // root-1-2
  tree_add_child(t1, t3);    // root-1-3
  tree_add_child(t1, t4);    // root-1-4
  tree_add_child(t4, t5);    // root-1-4-5
  tree_add_child(t4, t6);    // root-1-4-6
  tree_add_child(t5, t7);    // root-1-4-5-7

  assert(tree_child_count(root) == 1);  // root
  assert(tree_child_count(t1) == 3);    // 1
  assert(tree_child_count(t2) == 0);    // 2
  assert(tree_child_count(t3) == 0);    // 3
  assert(tree_child_count(t4) == 2);    // 4
  assert(tree_child_count(t5) == 1);    // 5
  assert(tree_child_count(t6) == 0);    // 6
  assert(tree_child_count(t7) == 0);    // 7

  tree_destroy(root, &free);

  return 0;
}
