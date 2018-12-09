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
	void * _struc;
	List * _children;
	_compare_funct _funct;
} Tree;

extern Tree * tree_new(void *struc,_compare_funct funct);

extern void tree_destroy(Tree * tree);

extern void * tree_get_node(Tree *root);

extern Tree * tree_add_child(Tree *root, Tree *node);

extern Tree * tree_remove_child(Tree *root, int index);

extern Tree * tree_get_child(Tree *root,int nb);

extern int tree_child_count(Tree *tree);

extern void tree_lock(Tree *tree);

extern void tree_unlock(Tree *tree);

extern void * tree_find_child(Tree *tree,void *child);

extern int tree_get_depth(Tree *tree);

#endif /* _TREE_H_ */
