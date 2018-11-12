#include "./list.h"

#include <stdlib.h>
#include <stdbool.h>

#define PSIZE sizeof(void*)

void* list_get(List* list, int index) {
	if (index < 0 || index >= list->_count)
		return NULL;
	return list->_data[index];
}

List* list_add(List* list, void* pointer) {
	if (list->_lock)
		return NULL;

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

void list_lock(List* list) {
	list->_lock = true;
	//TODO QuickSort, realloc to minimum size
}

void list_unlock(List* list) {
	list->_lock = false;
}

bool list_is_locked(List* list) {
	return list->_lock;
}

void list_destroy(List* list) {
	free(list->_data);
	free(list);
}

static List* _list_init(List* list) {
	list->_count = 0;
	list->_size = 16;
	list->_data = malloc(list->_size * PSIZE);
	list->_lock = false;
	if (list->_data)
		return list;
	return NULL;
}

List* list_new(_compFunc function) {
	List* list = malloc(sizeof(List));
	if (list) {
		List* filled = _list_init(list);
		if (filled)
			list->_compare = function;
			return list;
		// could not init the list, free the memory
		free(list);
	}
	return NULL;
}

