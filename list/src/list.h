#ifndef _LIST_H_
#define _LIST_H_

typedef struct _List List;

struct _List {
	int _count;
	int _size;
	void** _data;
};

extern void* list_get(List* list, int index);

extern List* list_add(List* list, void* pointer);

extern int list_count(List* list);

extern void list_destroy(List* list);

extern List* list_new();

#endif /* _LIST_H_ */ 

