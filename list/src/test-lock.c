/**
 * \file test-lock.c
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

int main(void) {
  setbuf(stdout, NULL);

  List* list = list_new(NULL);

  int* val = malloc(sizeof(int));
  *val = 0;
  assert(list_add(list, val) == list);

  assert(list_count(list) == 1);
  assert(list_is_locked(list) == false);

  list_lock(list);
  assert(list_is_locked(list));
  assert(list->_size == 1);

  //	assert(list_add(list, val) == NULL);

  // free memory
  free(val);
  list_destroy(list, NULL);
  return EXIT_SUCCESS;
}
