
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


int main(void){

	int * un   = malloc(sizeof(int)); *un   = 1 ;
	int * deux = malloc(sizeof(int)); *deux = 2 ;
	int * tro  = malloc(sizeof(int)); *tro  = 3 ;
	int * qua  = malloc(sizeof(int)); *qua  = 4 ;

	/**
	 * Function to compare int (local)
	 */
	int compare_int (void * nb1,void * nb2){
		return *(int*)nb1-*(int*)nb2;
	}

	Tree *root = tree_new_node(un,compare_int);
	Tree *t2 = tree_new_node(deux,NULL);
	Tree *t3 = tree_new_node(tro,NULL);
	Tree *t4 = tree_new_node(qua,NULL);

	tree_add_node(root,t2);
	tree_add_node(t2,t3);
	tree_add_node(t2,t4);

	assert(root->struc==un);
	assert(t2->struc==deux);
	assert(t3->struc==tro);
	assert(t4->struc==qua);
	
	assert(list_get(root->children,0)==t2);
	assert(list_get(t2->children,0)==t3);
	assert(list_get(t2->children,1)==t4);

	//free(un);free(deux);free(tro);
	tree_destroy(root);

	return 0;
}




