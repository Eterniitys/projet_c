/**
 * \file test-lock_qs.c
 * \brief testing program
 * \author Kilian
 * \version 0.1
 * \date 15 november 2018
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "list.inc"

int compare_int(void* a, void* b) { return *(int*)a - *(int*)b; }

int main(void) {
  List* list = list_new(&compare_int);
  // init RNG with constant value
  srand(0);

  int* val;
  int n = 42;
  int i;

  for (i = 0; i < n; i++) {
    val = malloc(sizeof(int));
    assert(val != NULL);
    *val = rand();
    assert(list_add(list, val) != NULL);
  }

  list_lock(list);
  // Check list is sorted
  for (i = 1; i < n; i++) {
    assert(compare_int(list_get(list, i - 1), list_get(list, i)) <= 0);
  }

  // check find returns null for invalid values
  int value = -1;
  assert(list_find(list, &value) == NULL);

  // free memory
  list_destroy(list, &free);
  return EXIT_SUCCESS;
}
