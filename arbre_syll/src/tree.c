#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "tree.h"


/**
* Permet la création d'un noeud avec la structure de 'struc'
*/
Tree * newTree(void *struc){
	Tree *seed;
	seed = malloc(sizeof(void *));
	seed->struc = struc;
	seed->children = list_new();
	return seed;
}

/**
* Permet l'ajout de l'enfant 'branch' à 'root'
*/
Tree * addBranch(Tree *root, Tree *branch){
	list_add(root->children, branch);
	return root;
}
