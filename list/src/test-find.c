/**
 * \file test-find.c
 * \brief testing program 
 * \author Kilian
 * \version 0.1
 * \date 15 november 2018
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "./list.h"

int compare_int(void* a, void* b) {
	return *(int*)a - *(int*)b;
}

int main(void) {
	List* list = list_new(&compare_int);
	// init RNG with constant value
	srand(0);

	int* val;
	int n = 42;
	int i;
	
	for (i=0; i<n; i++) {
		val = malloc(sizeof(int));
		assert(val != NULL);
		*val = rand();
		assert(list_add(list, val) != NULL);
	}

	int* tofind = malloc(sizeof(int));
	*tofind = -1;
	// should not exist since rand() only returns positive values
	assert(list_find(list,tofind) == NULL);

	*tofind = *(int*)list_get(list, 24);
	int* found = list_find(list,tofind);
	assert(*(int*)list_get(list, 24) == *found);

	// find again, but with sorted list
	list_lock(list);
	found = list_find(list,tofind);
	assert(*tofind == *found);

	// free memory
	free(tofind);
	for (i=0; i<n; i++) {
		free(list_get(list, i));
	}

	list_destroy(list);
	return EXIT_SUCCESS;
}

