/**
 * \file list.c
 * \class list
 * \author Kilian
 * \version 0.1
 * \date 15 november 2018
 */

#include "./list.h"
#include <stdlib.h>
#include <stdbool.h>

#include <stdio.h>

#define PSIZE sizeof(void*)

/**
 * \fn void* list_find(List* list, void* object)
 *
 * \return output - return a list who contain 'object' type.
 */

void* list_find(List* list, void* object) {
	void* output = NULL;
	if (!list->_lock) {
		int index = 0;
		while (index < list->_count && !output) {
			if (list->_compare(list->_data[index], object) == 0)
				output = list->_data[index];
			index++;
		}
	} else {
		int a = 0;
		int b = list->_count;
		int med = (a+b)/2;
		int comp = 0;
		while (b - a > 1 && !output) {
			comp = list->_compare(list->_data[med], object);
			if (comp < 0) {
				a = med;
			} else if (comp > 0) {
				b = med;
			} else {
				output = list->_data[med];
			}
			med = (a+b)/2;
		}
		if (med < list->_count &&
				list->_compare(list->_data[med], object) == 0)
			{
			output = list->_data[med];
		}
	}
	return output;
}

/**
 * \fn void* list_get(List* list, int index)
 *
 * \return seed - return the list who has 'index' position.
 */

void* list_get(List* list, int index) {
	if (index < 0 || index >= list->_count)
		return NULL;
	return list->_data[index];
}

/**
 * \fn List* list_add(List* list, void* pointer)
 *
 * \return list - add 'pointer' at the end of the list unless the list is lock
 */

List* list_add(List* list, void* pointer) {
	// list is full, need realloc
	if (list->_count >= list->_size) {
		int new_size;
		if (list->_size < 16) {
			new_size = 16;

		} else if (list->_size > 256) {
			new_size = list->_size + 256;

		} else {
			new_size = list->_size * 2;
		}

		// realloc fails
		void* temp = realloc(list->_data, new_size*PSIZE);

		if (temp) {
			list->_data = temp;
			list->_size = new_size;
		} else {
			return NULL;
		}
	}
	if (list->_lock) {
		fprintf(stderr, "WARN. List: adding element to locked list\n");
		//TODO use dichotomy to find index
		int index = 0;
		while (index < list->_count &&
				list->_compare(list->_data[index], pointer) < 0) {
			index++;
		}
		// we need to insert at the last position
		if (index == list->_count) {
			list->_data[index] = pointer;
			list->_count++;
		// we need to insert somewhere in the list
		} else {
			// move all the cells by one to the right
			void* temp = pointer;
			void* swap;
			while (index < list->_count) {
				swap = list->_data[index];
				list->_data[index] = temp;
				temp = swap;
				index++;
			}
			list->_data[index] = temp;
			list->_count++;
		}
	} else {
		list->_data[list->_count++] = pointer;
	}
	return list;
}

List* list_remove(List* list, int index) {
	if (index < 0 || index >= list->_count)
		return NULL;
	if (index < list->_count-1) {
		if (list->_lock) {
			fprintf(stderr, "WARN. List: removing element from locked list\n");
			while (index < list->_count-1) {
				list->_data[index] = list->_data[index+1];
				index++;
			}
		} else {
			list->_data[index] = list->_data[list->_count-1];
		}
		list->_data[list->_count-1] = NULL;
		list->_count--;
	} else {
		list->_data[index] = NULL;
		list->_count--;
	}
	return list;
}

/**
 * \fn int list_count(List* list)
 *
 * \return list->count - return the counter
 */

int list_count(List* list) {
	return list->_count;
}

/**
 * \fn void _list_qs(List* list, int A, int B)
 *
 * \return  - if the list is lock, sort it in its place
 */

void _list_qs(List* list, int A, int B) {
/*
	fprintf(stderr, "QS list:\n");
	int i;
	for (i=0; i < list_count(list); i++) {
		fprintf(stderr, "%d\t", *(int*)list_get(list, i));
	}
	fprintf(stderr, "\n");
	for (int i=0; i<A; i++) {
		fprintf(stderr, "\t");
	}
	fprintf(stderr,"A");
	for (int i=A; i<B; i++) {
		fprintf(stderr, "\t");
	}
	fprintf(stderr,"B");
	fprintf(stderr,"\n");
*/
	if (A>=B)
		return;
	int watchA = A;
	int watchB = B;
	void* pivot = list->_data[(A + B) / 2];

	while (watchA < watchB) {
		while(list->_compare(list->_data[watchA], pivot) < 0 && watchA<watchB)
			watchA++;
		while(list->_compare(list->_data[watchB], pivot) > 0 && watchB>watchA)
			watchB--;

		void* temp = list->_data[watchA];
		list->_data[watchA] = list->_data[watchB];
		list->_data[watchB] = temp;
	}
	_list_qs(list, A, watchA);
	_list_qs(list, watchA+1, B);
}

/**
 * \fn void list_lock(List* list)
 *
 * \return  - lock the list size to his actual size
 */

void list_lock(List* list) {
	list->_lock = true;

	// if count < size, reduce size in memory
	if (list->_count < list->_size) {
		int new_size = list->_count;

		if (new_size != 0) {
			void* temp = realloc(list->_data, new_size*PSIZE);

			if (temp) {
				list->_data = temp;
				list->_size = new_size;
			}
		} else {
			free(list->_data);
			list->_data = NULL;
			list->_size = 0;
		}
	}
	if (list->_count > 1) {
		_list_qs(list, 0, list->_count-1);
	}
}

/**
 * \fn void list_lock(List* list)
 *
 * \return  - unlock the list size
 */

void list_unlock(List* list) {
	list->_lock = false;
}

/**
 * \fn bool list_is_locked(List* list)
 *
 * \return list->lock - return true if the the list is lock and false if not
 */

bool list_is_locked(List* list) {
	return list->_lock;
}

/**
 * \fn void list_destroy(List* list)
 *
 * \return  - free the list
 */

void list_destroy(List* list) {
	free(list->_data);
	free(list);
}

/**
 * \fn static List* _list_init(List* list)
 *
 * \return list - init the list (variable, malloc the list)
 */

static List* _list_init(List* list) {
	list->_count = 0;
	list->_size = 0;
	list->_data = NULL;
	list->_lock = false;
	return list;
}

/**
 * \fn sList* list_new(_compFunc function)
 *
 * \return list - return pointer on empty list
 */

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

