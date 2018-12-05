#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <word.h>
#include <tree.h>
#include <hash.h>

#include "parser.h"
/*
char_word* get_struct(int profondeur,Tree* root_syll){
	while (profondeur != 0){
		root_syll=tree_get_child(root_syll,0);  
		profondeur--;  
	}
	return (char_word*)tree_get_node(root_syll);
}*/

char** printTree(Tree* root_syll,char ** mesSyllabes){
	static int n=0;
	static int cmtp=0;

		
	if (tree_get_node(root_syll) != NULL){
		mesSyllabes[n][cmtp]=((char_word*)tree_get_node(root_syll))->character;
		cmtp++;
		mesSyllabes[n][cmtp]='\0';		
	}
	
	/*else if (tree_child_count(root_syll)>1){
		mesSyllabes[n][cmtp]=((char_word*)tree_get_node(root_syll))->character;
		cmtp++;
		for (int j=0;j<tree_child_count(root_syll);j++){
			//mesSyllabes[n][cmtp]=((char_word*)tree_get_node(tree_get_child(root_syll,j)))->character;
			//cmtp++;
		}	
		mesSyllabes[n][cmtp]='\0';
	}*/
	if (tree_child_count(root_syll) == 0){
		cmtp=0;
		n++;
	}
	
	for (int i=0;i<tree_child_count(root_syll);i++){
		//if (tree_child_count(tree_get_child(root_syll,i))>1){
			//printTree(root_syll,mesSyllabes);
		//}
	//	else {
			printTree(tree_get_child(root_syll,i),mesSyllabes);
		//}   
	}
	return mesSyllabes;
}

int main (void){
	
	Tree * root = NULL;
	Tree * root_syll = NULL;
	Hashmap * map;

	Word** tab=parser_read("../src/test.csv", &root, &root_syll, map);

	/*// Test Mot 
	assert(strcmp(tab[3]->string,"a capella")==0);

	// Test Syllables
	assert(strcmp(tab[3]->syllables[0],"a")==0);
	assert(strcmp(tab[3]->syllables[1],"ca")==0);
	assert(strcmp(tab[3]->syllables[2],"pel")==0);
	assert(strcmp(tab[3]->syllables[3],"la")==0);
	
	// Test Phon
	assert(strcmp(tab[3]->phonetics[0],"a")==0);
	assert(strcmp(tab[3]->phonetics[1],"ka")==0);
	assert(strcmp(tab[3]->phonetics[2],"pE")==0);
	assert(strcmp(tab[3]->phonetics[3],"la")==0);

	// Test word not include 
	assert(strcmp(tab[13]->string,"ab absurdo")==0);
	
	// Test random word
	assert(tab[rand()%140000]->string != NULL);*/
	
	// fill_tree_syll 
	tree_lock(root_syll);
	
	char ** mesSyllabes= malloc (150);
	for (int i=0;i<7;i++){
		mesSyllabes[i]=malloc(10);
	}
	
	printTree(root_syll,mesSyllabes);
	printf("%s\n",mesSyllabes[4]);
		
	return(EXIT_SUCCESS);
}


