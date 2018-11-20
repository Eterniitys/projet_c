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

	Mot ** tableau = parseur_read("../../Lexique382.csv");

	//Tree *root = (NULL);

	//tree_add_branch(t1,t2);

	assert(1 == 0);
	assert(2 == 0);
	assert(3 == 0);

	return 0;
}

