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
		int *a= (int*)((Tree*)nb1)->_struc;
		int b= *(int*)((Tree*)nb2)->_struc;
		//tmp++;
		//printf("count:%d a:%d -- b:%d\n",tmp,*a,b);
		return *a-b;
	}

	Tree *root = tree_new(NULL,compare_int);
	
	for (int i=0;i<50;i++){
		int *t = malloc(sizeof(int));
		*t = rand();
		Tree *tree_t = tree_new(t,NULL);
		tree_add_child(root,tree_t);
	}
	//ref is a reference pointer with the sought value and content
	int *ref = (int*)tree_get_node(tree_get_child(root,5));//6th value
	//val is the sought content with wrong adress
	Tree* val = tree_new(ref,NULL);
	//fin have to be egals to ref
	int *fin= (int*)((Tree*)tree_find_child(root,val))->_struc;
	
	assert(ref == fin && *ref == *fin);
	
	//new value then lock
	ref = (int*)tree_get_node(tree_get_child(root,23));
	tree_destroy(val);
	val = tree_new(ref,NULL);
	tree_lock(root);
	fin= (int*)((Tree*)tree_find_child(root,val))->_struc;
	
	assert(ref == fin && *ref == *fin);
	
	//freeing zone
	for (int i=0;i<50;i++){
		free(tree_get_node(tree_get_child(root,i)));
	}
	tree_destroy(val);
	tree_destroy(root);
	

	return 0;
}

