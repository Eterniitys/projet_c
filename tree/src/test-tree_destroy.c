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
#include <word.h>
#include <parseur.h>


int main(void){

	int compare_int (void * nb1,void * nb2){
		return *(int*)nb1-*(int*)nb2;
	}

	Tree *root1 = tree_create(NULL);	
	Tree *root2 = tree_create(compare_int);
	
	//assert(tree_destroy(root1) == NULL);
	//assert(tree_destroy(root2) == NULL);
	
	//printf("%p\n",root1);
	//assert(root1 == NULL);
	//assert(root2 == NULL);
	
	return 0;
}

