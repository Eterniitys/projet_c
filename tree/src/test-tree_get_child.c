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

	assert(tree_get_child(root,0)->_struc==two);
	assert(tree_get_child(tree_get_child(root,0),0)->_struc==three);
	assert(tree_get_child(tree_get_child(root,0),1)->_struc==four);

	free(one);free(two);free(three);free(four);
	tree_destroy(root);

	return 0;
}

