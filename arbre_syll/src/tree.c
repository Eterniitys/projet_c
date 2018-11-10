#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "tree.h"


/**
* Permet la création d'un noeud avec la structure de 'struc'
*/
Tree * newTree(void *struc){
	Tree *seed = malloc(sizeof(Tree));
	seed->struc = struc;
	seed->children = list_new();
	return seed;
}

Tree * createTree(){
	Tree *seed = malloc(sizeof(Tree));
	seed->struc = seed;
	seed->children = list_new();
	return seed;
}

/**
* 
*/
void * getNode(Tree *root){
	return root->struc;
}

/**
* Permet l'ajout de l'enfant 'branch' à 'root'
*/
Tree * addBranch(Tree *root, Tree *branch){
	list_add(root->children, branch);
	return root;
}

/**
* 
*/
void * getBranch(Tree *root,int nb){
	return list_get(root->children,nb);
}


