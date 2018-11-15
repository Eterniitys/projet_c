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
		while (b - a >= 1 && !output) {
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
		if (list->_compare(list->_data[med], object) == 0) {
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
	if (B - A <= 1)
		return;
	int watchA = A;
	int watchB = B;
	void* pivot = list->_data[(A + B) / 2];

	while (list->_data[watchA] != pivot || list->_data[watchB] != pivot) {
		if (list->_compare(list->_data[watchA], pivot) < 0)
			watchA++;
		if (list->_compare(list->_data[watchB], pivot) > 0)
			watchB--;

		if (list->_compare(list->_data[watchA], pivot) >= 0 &&
				list->_compare(list->_data[watchB], pivot) <= 0)
		{
			void* temp = list->_data[watchA];
			list->_data[watchA] = list->_data[watchB];
			list->_data[watchB] = temp;
		}
	}
	_list_qs(list, A, watchA);
	_list_qs(list, watchB, B);
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
		int new_size = list->_count > 0 ? list->_count : 1;
		void* temp = realloc(list->_data, new_size*PSIZE);

		if (temp) {
			list->_data = temp;
			list->_size = new_size;
		}
	}
	_list_qs(list, 0, list->_count-1);
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
	list->_size = 16;
	list->_data = malloc(list->_size * PSIZE);
	list->_lock = false;
	if (list->_data)
		return list;
	return NULL;
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

