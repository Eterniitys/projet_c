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

/**
 * Function to compare int (local)
 */
int compare_int (void * nb1,void * nb2){
	return *(int*)nb1-*(int*)nb2;
}

int main(void){

	int * un   = malloc(sizeof(int)); *un   = 1 ;
	int * deux = malloc(sizeof(int)); *deux = 2 ;
	int * tro  = malloc(sizeof(int)); *tro  = 3 ;
	int * qua  = malloc(sizeof(int)); *qua  = 4 ;


	Tree *root = tree_new(un,compare_int);
	Tree *t2 = tree_new(deux,NULL);
	Tree *t3 = tree_new(tro,NULL);
	Tree *t4 = tree_new(qua,NULL);

	tree_add_child(root,t2);
	tree_add_child(t2,t3);
	tree_add_child(t2,t4);

	assert(tree_get_node(tree_get_child(root,0))==deux);
	assert(tree_get_node(tree_get_child(tree_get_child(root,0),0))==tro);
	assert(tree_get_node(tree_get_child(tree_get_child(root,0),1))==qua);
	
	free(un);free(deux);free(tro);free(qua);
	tree_destroy(root);

	return 0;
}

