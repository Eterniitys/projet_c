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
	seed->funct=funct;
	return seed;
}

/**
 * \fn Tree * tree_destroy()
 *
 * Allows Tree's structure freeing.
 */
void tree_destroy(Tree * tree){
	for (int i=0; i<tree_count_children(tree);i++){
		free(list_get(tree->children, i));
	}
	list_destroy(tree->children);
	free(tree);
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
 * \fn Tree * _tree_new_node(Tree *root,void *struc)
 *
 * \return node - return a new pointer of tree.
 */
Tree * _tree_new_node(Tree *root,void *struc){
	Tree *node = malloc(sizeof(Tree));
	node->struc = struc;
	node->children = list_new(root->funct);
	return node;
}

/**
 *\fn Tree * tree_add_node(Tree *root, void *node)
 *
 * Allows the addition of the child 'node' to the 'root'
 */
Tree * tree_add_node(Tree *root, void *node){
	Tree *branch = _tree_new_node(root,node);
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
 * Call list_find on tree->children
 * Seeking *child in list
 */
void * find_child(Tree *tree,void *child){
	return list_find(tree->children,child);
}







