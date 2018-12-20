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

#include <stdbool.h>

#include "tree.h"
#include "tree.inc"

int main(void){

	Tree *root = tree_new(NULL,NULL);
	Tree *t2 = tree_new(NULL,NULL);
	Tree *t3 = tree_new(NULL,NULL);
	
	tree_add_child(root,t2);
	tree_add_child(t2,t3);

	tree_lock(root);
	
	assert(list_is_locked(root->_children)==true);
	assert(list_is_locked(t2->_children)==true);
	assert(list_is_locked(t3->_children)==true);
	
	tree_destroy(root, NULL);

	return 0;
}

