#include "./list.h"

#include <stdlib.h>

#define PSIZE sizeof(void*)

void* list_get(List* list, int index) {
	if (index < 0 || index >= list->_count)
		return NULL;
	return list->_data[index];
}

List* list_add(List* list, void* pointer) {
	// list is full, need realloc
	if (list->_count >= list->_size) {
		int new_size = list->_size > 256 ? list->_size+256 : list->_size*2;

		// realloc fails
		void* temp = realloc(list->_data, new_size*PSIZE);

		if (temp) {
			list->_data = temp;
			list->_size = new_size;
		} else {
			return NULL;
		}
	}
	list->_data[list->_count++] = pointer;
	return list;
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
	list->_size = 16;
	list->_data = malloc(list->_size * PSIZE);
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

