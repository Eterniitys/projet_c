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
	//TODO liste dynamique de Tree
	seed->children = newList(/**/);
	return branch;
}

/**
* Permet l'ajout de l'enfant 'branch' à 'root'
*/
Tree * addBranch(Tree *root, Tree *branch){
	//TODO
	root->children/*->add(branch)*/;
	return root;
}
