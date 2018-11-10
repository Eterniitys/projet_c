#ifndef _TREE_H_
#define _TREE_H_

#include <list.h>

typedef struct _Tree Tree;
struct _Tree {
	void * struc;
	List * children;
};

extern Tree * newTree(void *struc);

extern Tree * createTree();

extern void * getNode(Tree *root);

extern Tree * addBranch(Tree *root, Tree *branch);

extern void * getBranch(Tree *root,int nb);

#endif /* _TREE_H_ */
