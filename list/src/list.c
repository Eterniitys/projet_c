#include "./list.h"

#include <stdlib.h>

void* list_get(List* list, int index) {
	//TODO lel
}

void list_add(List* list, void* pointer) {
	//TODO lel
}

int list_count(List* list) {
	return list->_count;
}

void list_destroy(List* list) {
	free(list->_data);
	free(list);
}

static List* _list_init(List* list) {
	list->_count = 0;
	list->_size = 64;
	list->_data = malloc(sizeof(void**)*64);
	if (list->_data)
		return list;
	return NULL;
}

List* list_new() {
	List* list = malloc(sizeof(List));
	if (list) {
		List* filled = _list_init(list);
		if (filled)
			return list;
		// could not init the list, free the memory
		free(list);
	}
	return NULL;
}

