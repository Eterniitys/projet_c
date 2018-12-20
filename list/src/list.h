/**
 * \file test-lock.c
 * \struct List list.h "Définition" 
 * \author Kilian
 * \version 0.1
 * \date 15 november 2018
 */

#ifndef _LIST_H_
#define _LIST_H_
#include <stdbool.h>

typedef struct _List List;
typedef int (*_compFunc)(void*, void*);
typedef void (*_freeFunc)(void*);

struct _List {
	int _count;
	int _size;
	bool _lock;
	_compFunc _compare;
	void** _data;
};

typedef struct _ScoreSyllPhon ScoreSyllPhon;
struct _ScoreSyllPhon {
	char * syllPhon;
	int score;
};

/**
 * \fn void* list_get(List* list, int index)
 *
 * \return seed - return the list who has 'index' position.
 */
extern void* list_get(List* list, int index);

/**
 * \fn List* list_add(List* list, void* pointer)
 *
 * \return list - add 'pointer' at the end of the list unless the list is lock
 */
extern List* list_add(List* list, void* pointer);

/**
 * \fn List* list_remove(List* list, int index)
 *
 * \return list - remove an element of the list
 */
extern List* list_remove(List* list, int index);

/**
 * \fn int list_count(List* list)
 *
 * \return list->count - return the counter
 */
extern int list_count(List* list);

/**
 * \fn void* list_find(List* list, void* object)
 *
 * \return output - return a list who contain 'object' type.
 */
extern void* list_find(List* list, void* pointer);

/**
 * \fn void list_lock(List* list)
 *
 * \return  - lock the list size to his actual size
 */
extern void list_lock(List* list);

/**
 * \fn void list_unlock(List* list)
 *
 * \return  - unlock the list size
 */
extern void list_unlock(List* list);

/**
 * \fn bool list_is_locked(List* list)
 *
 * \return list->lock - return true if the the list is lock and false if not
 */
extern bool list_is_locked(List* list);

/**
 * \fn void list_destroy(List* list, _freeFunc elm_free)
 *
 * \return  - free the list
 */
extern void list_destroy(List* list, _freeFunc free);

/**
 * \fn sList* list_new(_compFunc function)
 *
 * \return list - return pointer on empty list
 */
extern List* list_new(_compFunc comp);


#endif /* _LIST_H_ */

