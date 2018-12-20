/**
 * \file test-list.c
 * \brief testing program 
 * \author Kilian
 * \version 0.1
 * \date 15 november 2018
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "list.h"
#include "list.inc"

int main(void) {
	setbuf(stdout, NULL);

	List* list = list_new(NULL);
	assert(list != NULL);
	assert(list_count(list) == 0);

	int* val = malloc(sizeof(int));
	*val = 0;
	list_add(list, val);

	assert(list_count(list) == 1);

	int n = 17; // 66

	assert(list_get(list,0) == val);
	assert(list_get(list,1) == NULL);
	assert(list_get(list,-1) == NULL);

	//test realloc
	int i;
	// force list realloc
	for (i=1; i<n; i++) {
		val = malloc(sizeof(int));
		assert(val != NULL);
		*val = i;
		assert(list_add(list, val) != NULL);
		assert(list_count(list) == i+1);
		assert(list_get(list,i) == val);
	}

	// check values;
	int* t;
	for (i=0; i<n; i++) {
		t = list_get(list, i);
		assert(*t == i);
	}

	list_destroy(list, &free);
	return EXIT_SUCCESS;
}

