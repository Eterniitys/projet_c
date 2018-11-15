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
#include "../../word/src/word.h"


int main(void){

	//test on the trees, validate the lists before validating the tree

	int * un   = malloc(sizeof(int)); *un   = 1 ;
	int * deux = malloc(sizeof(int)); *deux = 2 ;
	int * tro  = malloc(sizeof(int)); *tro  = 3 ;
	int * qua  = malloc(sizeof(int)); *qua  = 4 ;
	int * cin  = malloc(sizeof(int)); *cin  = 5 ;
	int * sic  = malloc(sizeof(int)); *sic  = 6 ;
	int * sept = malloc(sizeof(int)); *sept = 7 ;

	Tree *root = tree_create(NULL);
	Tree *t1 = tree_new_node(un);
	Tree *t2 = tree_new_node(deux);
	Tree *t3 = tree_new_node(tro);

	tree_add_branch(t1,t2);
	tree_add_branch(t1,t3);
	tree_add_branch(root,t1);

	assert(*(int*)tree_get_node(t1)==*un);
	assert(tree_get_branch(root,0)==t1);
	assert(*(int*)tree_get_node(tree_get_branch(tree_get_branch(root,0),1))==3);

	assert(tree_count_children(t1)==2);

	return 0;
}







