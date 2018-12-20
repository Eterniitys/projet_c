/**
 * \file test-lock_qs.c
 * \brief testing program
 * \author Kilian
 * \version 0.1
 * \date 15 november 2018
 */

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "list.inc"

int compare_int(void* a, void* b) { return *(int*)a - *(int*)b; }

bool check_list_sorted(List* list) {
  int i;
  bool output = true;
  for (i = 1; i < list_count(list); i++) {
    output =
        output && compare_int(list_get(list, i - 1), list_get(list, i)) <= 0;
  }
  return output;
}

int main(void) {
  // first column is length of line
  int count = 12;
  int max_length = 10;
  int datasets[12][10] = {
      {0},                                        // 0
      {1, 1},                                     // 1
      {2, 1, 3},                                  // 2
      {2, 3, 1},                                  // 3
      {3, 4, 3, 1},                               // 4
      {3, 4, 1, 3},                               // 5
      {3, 3, 4, 1},                               // 6
      {3, 3, 1, 4},                               // 7
      {3, 1, 3, 4},                               // 8
      {3, 1, 4, 3},                               // 9
      {2, -2, 4},                                 // 10
      {9, 700, 68, 123, 132, 187, 984, 1, -1, 0}  // 11
  };

  List* list;

  int i;
  for (i = 0; i < count; i++) {
    list = list_new(&compare_int);
    int j;
    for (j = 1; j <= datasets[i][0]; j++) {
      list_add(list, &(datasets[i][j]));
    }
    assert(list_count(list) == datasets[i][0]);
    list_lock(list);
    assert(list_count(list) == datasets[i][0]);
    assert(check_list_sorted(list));
    if (datasets[i][0] > 0) {
      list_remove(list, 0);
      assert(list_count(list) == datasets[i][0] - 1);
    }
    assert(check_list_sorted(list));
    list_destroy(list, NULL);
  }
  return EXIT_SUCCESS;
}
