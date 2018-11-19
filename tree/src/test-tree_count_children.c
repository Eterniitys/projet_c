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

	int * un   = malloc(sizeof(int)); *un   = 1 ;
	int * deux = malloc(sizeof(int)); *deux = 2 ;
	int * tro  = malloc(sizeof(int)); *tro  = 3 ;
	int * qua  = malloc(sizeof(int)); *qua  = 4 ;
	int * cin  = malloc(sizeof(int)); *cin  = 5 ;
	int * six  = malloc(sizeof(int)); *six  = 6 ;
	int * sept = malloc(sizeof(int)); *sept = 7 ;
	
	/**
	 * Function to compare int (local)
	 */
	int compare_int (void * nb1,void * nb2){
		return *(int*)nb1-*(int*)nb2;
	}

	Tree *root = tree_create(compare_int);

	tree_add_node(root,un);//root-1
	tree_add_node(tree_get_branch(root,0),deux);//root-1-2
	tree_add_node(tree_get_branch(root,0),tro);//root-1-3
	tree_add_node(tree_get_branch(root,0),qua);//root-1-4
	tree_add_node(tree_get_branch(tree_get_branch(root,0),2),cin);//root-1-4-5
	tree_add_node(tree_get_branch(tree_get_branch(root,0),2),six);//root-1-4-6
	tree_add_node(tree_get_branch(tree_get_branch(tree_get_branch(root,0),2),0),sept);//root-1-4-5-7
	
	assert(tree_count_children(root)==1);//root
	assert(tree_count_children(tree_get_branch(root,0))==3);//1
	assert(tree_count_children(tree_get_branch(tree_get_branch(root,0),0))==0);//2
	assert(tree_count_children(tree_get_branch(tree_get_branch(root,0),1))==0);//3
	assert(tree_count_children(tree_get_branch(tree_get_branch(root,0),2))==2);//4
	assert(tree_count_children(tree_get_branch(tree_get_branch(tree_get_branch(root,0),2),0))==1);//5
	assert(tree_count_children(tree_get_branch(tree_get_branch(tree_get_branch(root,0),2),1))==0);//6
	assert(tree_count_children(tree_get_branch(tree_get_branch(tree_get_branch(tree_get_branch(root,0),2),0),0))==0);//7
	
	free(un);free(deux);free(tro);free(qua);free(cin);free(six);free(sept);
	tree_destroy(root);

	return 0;
}

