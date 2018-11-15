/**
 * \file tree.h
 * \struct Tree tree.h "Definition"
 * \author Johan
 * \version 0.1
 * \date 15 november 2018
 */

#ifndef _TREE_H_
#define _TREE_H_

#include <list.h>

typedef int (*_compare_funct)(void*,void*);

typedef struct _Tree {
	void * struc;
	List * children;
	_compare_funct funct;
} Tree;

extern Tree * tree_create(_compare_funct);

extern void tree_destroy(Tree * tree);

extern Tree * tree_new_node(void *struc);

extern void * tree_get_node(Tree *root);

extern Tree * tree_add_branch(Tree *root, Tree *branch);

extern Tree * tree_get_branch(Tree *root,int nb);

extern int tree_count_children(Tree *tree);

extern void tree_lock(Tree *tree);

extern void tree_unlock(Tree *tree);

extern void * find_child(Tree *tree,void *child);

#endif /* _TREE_H_ */
