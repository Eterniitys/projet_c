
/**
 * \file test-tree.c
 * \brief testing program
 * \author Johan
 * \version 0.1
 * \date 15 november 2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "tree.h"
#include <word.h>
#include <parseur.h>


int main(void){

	int * un   = malloc(sizeof(int)); *un   = 1 ;
	int * deux = malloc(sizeof(int)); *deux = 2 ;
	int * tro  = malloc(sizeof(int)); *tro  = 3 ;

	/**
	 * Function to compare int (local)
	 */
	int compare_int (void * nb1,void * nb2){
		return *(int*)nb1-*(int*)nb2;
	}

	Tree *root = tree_create(compare_int);

	tree_add_node(root,un);
	tree_add_node(tree_get_branch(root,0),deux);
	tree_add_node(tree_get_branch(root,0),tro);

	assert(tree_get_node(tree_get_branch(root,0))==un);
	assert(tree_get_node(tree_get_branch(tree_get_branch(root,0),0))==deux);
	assert(tree_get_node(tree_get_branch(tree_get_branch(root,0),1))==tro);

	free(un);free(deux);free(tro);
	tree_destroy(root);

	return 0;
}




