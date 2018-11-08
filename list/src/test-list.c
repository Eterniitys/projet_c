#include <stdlib.h>
#include <assert.h>

#include "./list.h"

int main(void) {
	List* list = list_new();
	assert(list != NULL);
	return EXIT_SUCCESS;
}

