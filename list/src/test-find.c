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

	int* tofind = malloc(sizeof(int));
	*tofind = -1;
	// should not exist since rand() only returns positive values
	assert(list_find(list,tofind) == NULL);

	*tofind = *(int*)list_get(list, 24);
	int* found = list_find(list,tofind);
	assert(list_get(list, 24) == found);

	list_destroy(list);
	return EXIT_SUCCESS;
}

