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

	tree_lock(root);
	
	assert(list_is_locked(root->children)==true);

	return 0;
}

