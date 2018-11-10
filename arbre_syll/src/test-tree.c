#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "tree.h"
#include "../../word.h"


int main(void){
	
	//test sur les arbre, valider les listes avant de valider les arbre
	
	int * un   = malloc(sizeof(int)); *un   = 1 ;
	int * deux = malloc(sizeof(int)); *deux = 2 ;
	int * tro  = malloc(sizeof(int)); *tro  = 3 ;
	int * qua  = malloc(sizeof(int)); *qua  = 4 ;
	int * cin  = malloc(sizeof(int)); *cin  = 5 ;
	int * sic  = malloc(sizeof(int)); *sic  = 6 ;
	int * sept = malloc(sizeof(int)); *sept = 7 ;
	
	Tree *root = createTree();
	Tree *t1 = newTree(un);
	Tree *t2 = newTree(deux);
	Tree *t3 = newTree(tro);
	
	addBranch(t1,t2);
	addBranch(t1,t3);
	addBranch(root,t1);
	
	assert(*(int*)getNode(t1)==*un);
	assert(getBranch(root,0)==t1);
	assert(*(int*)getNode(getBranch(getBranch(root,0),1))==3);
	
}

