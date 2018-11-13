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
	
	for (int i=0; i<n; i++) {
		val = malloc(sizeof(int));
		assert(val != NULL);
		*val = rand();
		assert(list_add(list, val) != NULL);
	}

	list_lock(list);
	// Check list is sorted
	for (int i=1; i<n; i++) {
		assert(compare_int(list_get(list, i-1), list_get(list, i)) <= 0);
	}

	list_destroy(list);
	return EXIT_SUCCESS;
}

