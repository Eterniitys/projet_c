/**
 * \file tree.c
 * \class tree
 * \author Johan
 * \version 0.1
 * \date 15 november 2018
 *
 * Allows the creation of a node with the structure of 'struc'
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "tree.h"

/**
 * \fn Tree * tree_create(int (*_compare_funct)(void*,void*))
 *
 * \return seed - return a new pointer of tree.
 */
Tree * tree_create(_compare_funct funct){
	Tree *seed = malloc(sizeof(Tree));
	seed->struc = seed;
	seed->children = list_new(funct);
	return seed;
}

/**
 * \fn Tree * tree_destroy()
 *
 * Allows Tree's structure freeing.
 */
void tree_destroy(Tree * tree){
	list_destroy(tree->children);
	free(tree->struc);
	free(tree);
}

/**
 * \fn Tree * tree_new_node(void *struc)
 *
 * \return seed - return a new pointer of tree.
 */
Tree * tree_new_node(void *struc){
	Tree *seed = malloc(sizeof(Tree));
	seed->struc = struc;
	seed->children = list_new(NULL);
	return seed;
}

/**
 * \fn void * tree_get_node(Tree *root)
 *
 * \return root->struc - return the node.
 */
void * tree_get_node(Tree *root){
	return root->struc;
}

/**
*\fn Tree * tree_add_branch(Tree *root, Tree *branch)
*
* Allows the addition of the child 'branch' to the 'root'
*/
Tree * tree_add_branch(Tree *root, Tree *branch){
	branch->funct = root->funct;
	list_add(root->children, branch);
	return root;
}

/**
*\fn Tree * tree_get_branch(Tree *root,int nb)
*
* Allows the getter of the child 'branch' to the 'root'
*/
Tree * tree_get_branch(Tree *root,int nb){
	return list_get(root->children,nb);
}

/**
 *\fn int tree_count_children(Tree *tree)
 *
 *\return list_count(tree->children) - number of children
 */
int tree_count_children(Tree *tree){
	return list_count(tree->children);
}

/**
 *\fn void tree_lock(Tree *tree)
 *
 * Call list_lock on tree->children
 */
void tree_lock(Tree *tree){
	list_lock(tree->children);
}

/**
 *\fn void tree_unlock(Tree *tree)
 *
 * Call list_unlock on tree->children
 */
void tree_unlock(Tree *tree){
	list_unlock(tree->children);
}


/**
 *\fn Tree * find_child(Tree *tree)
 *
 *
 */
void * find_child(Tree *tree,void *child){
	return list_find(tree->children,child);
}






