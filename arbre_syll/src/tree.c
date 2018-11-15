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
 * \fn Tree * newTree(void *)
 *
 * \return seed - return a new pointer of tree.
 */
Tree * newTree(void *struc){
	Tree *seed = malloc(sizeof(Tree));
	seed->struc = struc;
	seed->children = list_new();
	return seed;
}

/**
 * \fn Tree * createTree()
 *
 * \return seed - return a new pointer of tree.
 */
Tree * createTree(){
	Tree *seed = malloc(sizeof(Tree));
	seed->struc = seed;
	seed->children = list_new();
	return seed;
}

/**
 * \fn Tree * createTree()
 *
 * \return root->struc - return the node.
 */
void * getNode(Tree *root){
	return root->struc;
}

/**
*\fn Tree * addBranch(Tree *, Tree *)
*
* Allows the addition of the child 'branch' to the 'root'
*/
Tree * addBranch(Tree *root, Tree *branch){
	list_add(root->children, branch);
	return root;
}

/**
*\fn Tree * getBranch(Tree *,int)
*
* Allows the getter of the child 'branch' to the 'root'
*/
void * getBranch(Tree *root,int nb){
	return list_get(root->children,nb);
}


