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


int main(void){

	/**
	 * Function to compare int (local)
	 */
	int compare_int (void * nb1,void * nb2){
		//static int tmp= 0;
		int *a= (int*)((Tree*)nb1)->struc;
		int b= *(int*)((Tree*)nb2)->struc;
		//tmp++;
		//printf("count:%d a:%d -- b:%d\n",tmp,*a,b);
		return *a-b;
	}

	Tree *root = tree_new_node(NULL,compare_int);
	
	for (int i=0;i<50;i++){
		int *t = malloc(sizeof(int));
		*t = rand();
		Tree *tree_t = tree_new_node(t,NULL);
		tree_add_node(root,tree_t);
	}
	//ref is a reference pointer with the sought value and content
	int *ref = (int*)tree_get_node(tree_get_branch(root,5));//6th value
	//val is the sought content with wrong adress
	Tree* val = tree_new_node(ref,NULL);
	//fin have to be egals to ref
	int *fin= (int*)((Tree*)tree_find_child(root,val))->struc;
	
	assert(ref == fin && *ref == *fin);
	
	//new value then lock
	ref = (int*)tree_get_node(tree_get_branch(root,23));
	val = tree_new_node(ref,NULL);
	tree_lock(root);
	fin= (int*)((Tree*)tree_find_child(root,val))->struc;
	
	assert(ref == fin && *ref == *fin);

	return 0;
}

