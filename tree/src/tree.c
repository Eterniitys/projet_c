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
 * \fn Tree * tree_new_Tree(void *struc)
 *
 * \return seed - return a new pointer of tree.
 */
Tree * tree_new_Tree(void *struc){
	Tree *seed = malloc(sizeof(Tree));
	seed->struc = struc;
	seed->children = list_new();
	return seed;
}

/**
 * \fn Tree * tree_create()
 *
 * \return seed - return a new pointer of tree.
 */
Tree * tree_create(){
	Tree *seed = malloc(sizeof(Tree));
	seed->struc = seed;
	seed->children = list_new();
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
	list_add(root->children, branch);
	return root;
}

/**
*\fn Tree * tree_get_branch(Tree *root,int nb)
*
* Allows the getter of the child 'branch' to the 'root'
*/
void * tree_get_branch(Tree *root,int nb){
	return list_get(root->children,nb);
}

//TODO
int tree_count_children();
//TODO
void* find_child(Tree tree);
