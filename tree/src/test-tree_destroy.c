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

	int * un   = malloc(sizeof(int)); *un   = 1 ;
	int * deux = malloc(sizeof(int)); *deux = 2 ;


	Tree *root1 = tree_new(un,NULL);	
	Tree *root2 = tree_new(deux,compare_int);
	
	tree_destroy (root1);	
	tree_destroy (root2);
	
	Tree *root3 = tree_new(un,NULL);	
	Tree *root4 = tree_new(root3,compare_int);
	
	tree_destroy (root3);	
	tree_destroy (root4);
	
	free(un);free(deux);
	
	return 0;
}

