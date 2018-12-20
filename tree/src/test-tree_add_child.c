
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
#include "tree.inc"

/**
 * Fonection to compare int (local)
 */
int compare_int (void * nb1,void * nb2){
	return *(int*)nb1-*(int*)nb2;
}

int main(void){

	int * one   = malloc(sizeof(int)); *one   = 1 ;
	int * two = malloc(sizeof(int)); *two = 2 ;
	int * three  = malloc(sizeof(int)); *three  = 3 ;
	int * four  = malloc(sizeof(int)); *four  = 4 ;



	Tree *root = tree_new(one,compare_int);
	Tree *t2 = tree_new(two,NULL);
	Tree *t3 = tree_new(three,NULL);
	Tree *t4 = tree_new(four,NULL);

	tree_add_child(root,t2);
	tree_add_child(t2,t3);
	tree_add_child(t2,t4);

	assert(root->_struc==one);
	assert(t2->_struc==two);
	assert(t3->_struc==three);
	assert(t4->_struc==four);
	
	assert(list_get(root->_children,0)==t2);
	assert(list_get(t2->_children,0)==t3);
	assert(list_get(t2->_children,1)==t4);

	tree_destroy(root, &free);

	return 0;
}




