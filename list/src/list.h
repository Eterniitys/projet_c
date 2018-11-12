#ifndef _LIST_H_
#define _LIST_H_
#include <stdbool.h>

typedef struct _List List;
typedef int (*_compFunc)(void*, void*);

struct _List {
	int _count;
	int _size;
	bool _lock;
	_compFunc _compare;
	void** _data;
};

extern void* list_get(List* list, int index);

extern List* list_add(List* list, void* pointer);

extern int list_count(List* list);

extern void* list_find(List* list, void* pointer);

extern void list_lock(List* list);

extern void list_unlock(List* list);

extern bool list_is_locked(List* list);

extern void list_destroy(List* list);

extern List* list_new(_compFunc);

#endif /* _LIST_H_ */ 

