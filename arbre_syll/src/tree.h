#ifndef _TREE_H_
#define _TREE_H_

#include <list.h>

typedef struct _Tree Tree;
struct _Tree {
	void * struc;
	List * children;
};

#endif
