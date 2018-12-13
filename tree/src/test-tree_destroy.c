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

int compare_int (void * nb1,void * nb2){
	return *(int*)nb1-*(int*)nb2;
}

int main(void){

	int * one   = malloc(sizeof(int)); *one   = 1 ;
	int * two = malloc(sizeof(int)); *two = 2 ;


	Tree *root1 = tree_new(one,NULL);	
	Tree *root2 = tree_new(two,compare_int);
	
	tree_destroy (root1);	
	tree_destroy (root2);
	
	Tree *root3 = tree_new(one,NULL);	
	Tree *root4 = tree_new(root3,compare_int);
	
	tree_destroy (root3);	
	tree_destroy (root4);
	
	free(one);free(two);
	
	return 0;
}

