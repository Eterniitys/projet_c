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

typedef struct _Tree {
	void * _struc;
	List * _children;
	_compFunc _funct;
} Tree;

/**
 * \fn Tree * tree_new(Tree *root,void *struc)
 *
 * \return node - Return a new pointer of tree.
 */
extern Tree * tree_new(void *struc, _compFunc funct);

/**
 * \fn Tree * tree_destroy()
 *
 * \return void - Allows Tree's structure freeing.
 */
extern void tree_destroy(Tree * tree, _freeFunc free);

/**
 * \fn void * tree_get_node(Tree *root)
 *
 * \return root->_struc - Return the node.
 */
extern void * tree_get_node(Tree *root);

/**
 *\fn Tree * tree_add_child(Tree *root, void *node)
 *
 * Allows the addition of the child 'node' to the 'root'
 *\return root - Return root.
 */
extern Tree * tree_add_child(Tree *root, Tree *node);

/**
 *\fn Tree * tree_remove_child(Tree *root, void *node)
 *
 * Allows removing of child at 'index' from 'root'
 *\return root
 */
extern Tree * tree_remove_child(Tree *root, int index);

/**
 *\fn Tree * tree_get_child(Tree *root,int nb)
 *
 * Allows the getter of the child n°'nb' from 'root'
 *\return Tree * node 
 */
extern Tree * tree_get_child(Tree *root,int nb);

/**
 *\fn int tree_child_count(Tree *tree)
 *
 *\return int count - Number of tree's children.
 */
extern int tree_child_count(Tree *tree);

/**
 *\fn void tree_lock(Tree *tree)
 *
 * Call list_lock on tree->_children
 *\return void - Locks the tree recursively.
 */
extern void tree_lock(Tree *tree);

/**
 *\fn void tree_unlock(Tree *tree)
 *
 * Call list_unlock on tree->_children
 *\return void - Unlocks the tree recursively.
 */
extern void tree_unlock(Tree *tree);

/**
 *\fn Tree* tree_find_child(Tree *tree,void *child)
 *
 * Call list_find on tree->_children
 * Seeking *child in list
 * \return Tree node - The tree which contains child.
 */
extern Tree * tree_find_child(Tree *tree,void *child);

/**
 *\fn int tree_get_depth(Tree *tree)
 *
 * Call list_find on tree->_children
 * Seeking *child in list
 *\return max - Return the depth of the tree.
 */
extern int tree_get_depth(Tree *tree);

#endif /* _TREE_H_ */
