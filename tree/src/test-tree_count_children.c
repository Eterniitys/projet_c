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

	Tree *root = tree_new_node(NULL,compare_int);
	Tree *t1 = tree_new_node(un,compare_int);
	Tree *t2 = tree_new_node(deux,compare_int);
	Tree *t3 = tree_new_node(tro,compare_int);
	Tree *t4 = tree_new_node(qua,compare_int);
	Tree *t5 = tree_new_node(cin,compare_int);
	Tree *t6 = tree_new_node(six,compare_int);
	Tree *t7 = tree_new_node(sept,compare_int);

	tree_add_node(root,t1);//root-1
	tree_add_node(t1,t2);//root-1-2
	tree_add_node(t1,t3);//root-1-3
	tree_add_node(t1,t4);//root-1-4
	tree_add_node(t4,t5);//root-1-4-5
	tree_add_node(t4,t6);//root-1-4-6
	tree_add_node(t5,t7);//root-1-4-5-7
	
	assert(tree_count_children(root)==1);//root
	assert(tree_count_children(t1)==3);//1
	assert(tree_count_children(t2)==0);//2
	assert(tree_count_children(t3)==0);//3
	assert(tree_count_children(t4)==2);//4
	assert(tree_count_children(t5)==1);//5
	assert(tree_count_children(t6)==0);//6
	assert(tree_count_children(t7)==0);//7
	
	//free(un);free(deux);free(tro);free(qua);free(cin);free(six);free(sept);
	tree_destroy(root);

	return 0;
}

