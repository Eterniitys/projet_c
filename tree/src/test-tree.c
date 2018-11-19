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

	assert(1!=0);

	return 0;
}







