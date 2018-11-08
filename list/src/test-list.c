#include <stdlib.h>
#include <assert.h>

#include "./list.h"

int main(void) {
	List* list = list_new();
	assert(list != NULL);
	assert(list_count(list) == 0);

	int* val = malloc(sizeof(int));
	*val = 10;
	list_add(list, val);

	assert(list_count(list) == 1);

	assert(list_get(list,0) == val);
	assert(list_get(list,1) == NULL);
	assert(list_get(list,-1) == NULL);

	//test realloc
	int i;
	// reach 65 to force list realloc
	for (i=1; i<66; i++) {
		assert(list_add(list, val) == list);
	}
	assert(list->_size == 128);

	list_destroy(list);
	return EXIT_SUCCESS;
}

