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
#include <stdbool.h>


int main(void){

	Tree *root = tree_new_node(NULL,NULL);
	Tree *t2 = tree_new_node(NULL,NULL);
	Tree *t3 = tree_new_node(NULL,NULL);
	
	tree_add_node(root,t2);
	tree_add_node(t2,t3);

	tree_lock(root);
	
	assert(list_is_locked(root->_children)==true);
	assert(list_is_locked(t2->_children)==true);
	assert(list_is_locked(t3->_children)==true);
	
	tree_destroy(root);

	return 0;
}

