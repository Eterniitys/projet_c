/**
 * \file test-tree_find_child.c
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

		/**
	 * Function to compare int (local)
	 */
	int compare_int (void * nb1,void * nb2){
		return *(int*)nb1-*(int*)nb2;
	}

	Tree *root = tree_new_node(NULL,compare_int);
	
	for (int i=0;i<50;i++){
		int *t = malloc(sizeof(int));
		*t = rand();
		Tree *tree_t = tree_new_node(t,NULL);
		tree_add_node(root,tree_t);
	}
	int *ref = (int*)tree_get_node(tree_get_branch(root,42));
	int val = *ref;
	
	printf("ref = %p -- %d\n",ref,*ref) ;
	printf("val = %p -- %d\n",&val,val) ;
	
	int *fin= (int*)tree_find_child(root,&val);

	printf("fin = %p -- %d\n",&fin,fin) ;
	//assert(1 == 0);
	//assert(2 == 0);
	//assert(3 == 0);

	return 0;
}

