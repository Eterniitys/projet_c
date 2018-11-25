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

	int compare_int (void * nb1,void * nb2){
		return *(int*)nb1-*(int*)nb2;
	}

	Tree *root1 = tree_create(NULL);
	assert(sizeof(root1->_struc) == sizeof(void*));
	assert(sizeof(root1->_children) == sizeof(List*));
	assert(sizeof(root1->_funct) == sizeof(NULL));
	
	Tree *root2 = tree_create(compare_int);
	assert(sizeof(root2->_struc) == sizeof(void*));
	assert(sizeof(root2->_children) == sizeof(List*));
	assert(sizeof(root2->_funct) == sizeof(_compare_funct));
	
	tree_destroy(root1);
	tree_destroy(root2);

	return 0;
}

