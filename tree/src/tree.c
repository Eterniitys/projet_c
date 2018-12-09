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
 * \fn void * tree_get_node(Tree *root)
 *
 * \return root->_struc - return the node.
 */
void * tree_get_node(Tree *root){
	return root->_struc;
}

/**
 * \fn Tree * tree_new(Tree *root,void *struc)
 *
 * \return node - return a new pointer of tree.
 */
Tree * tree_new(void *struc,_compare_funct funct){
	Tree *node = malloc(sizeof(Tree));
	node->_struc = struc;
	node->_funct=funct;
	node->_children = list_new(funct);
	return node;
}

/**
 * \fn Tree * tree_destroy()
 *
 * Allows Tree's structure freeing.
 */
void tree_destroy(Tree * tree){
	for (int i=0; i<tree_child_count(tree);i++){
		tree_destroy(list_get(tree->_children, i));
	}
	list_destroy(tree->_children);
	free(tree);
}

/**
 *\fn Tree * tree_add_child(Tree *root, void *node)
 *
 * Allows the addition of the child 'node' to the 'root'
 */
Tree * tree_add_child(Tree *root, Tree *node){
	node->_children->_compare=root->_funct;
	node->_funct=root->_funct;
	list_add(root->_children, node);
	return root;
}

/**
 *\fn Tree * tree_remove_child(Tree *root, void *node)
 *
 * Allows removing of child at 'index' from 'root'
 */
Tree * tree_remove_child(Tree *root, int index){
	list_remove(root->_children, index);
	return root;
}

/**
 *\fn Tree * tree_get_child(Tree *root,int nb)
 *
 * Allows the getter of the child 'branch' to the 'root'
 */
Tree * tree_get_child(Tree *root,int nb){
	return list_get(root->_children,nb);
}

/**
 *\fn int tree_child_count(Tree *tree)
 *
 *\return list_count(tree->_children) - number of children
 */
int tree_child_count(Tree *tree){
	return list_count(tree->_children);
}

/**
 *\fn void tree_lock(Tree *tree)
 *
 * Call list_lock on tree->_children
 */
void tree_lock(Tree *tree){
	for (int i=0; i<tree_child_count(tree);i++){
		tree_lock(list_get(tree->_children, i));
	}
	list_lock(tree->_children);
}

/**
 *\fn void tree_unlock(Tree *tree)
 *
 * Call list_unlock on tree->_children
 */
void tree_unlock(Tree *tree){
	for (int i=0; i<tree_child_count(tree);i++){
		tree_unlock(list_get(tree->_children, i));
	}
	list_unlock(tree->_children);
}


/**
 *\fn Tree * tree_find_child(Tree *tree)
 *
 * Call list_find on tree->_children
 * Seeking *child in list
 */
void * tree_find_child(Tree *tree,void *child){
	return list_find(tree->_children,child);
}

int tree_get_depth(Tree *tree){
	int max = 0;
	if (tree_child_count(tree)>1){
		max = tree_get_depth(tree_get_child(tree,0));
		for(int i=1; i<tree_child_count(tree) ; i++){
			int depth = tree_get_depth(tree_get_child(tree,i));
			max = max >= depth ? max : depth ;
		}
	}else if (tree_child_count(tree)==1){
		max = tree_get_depth(tree_get_child(tree,0));
	}
	max++;
	return max;
}







