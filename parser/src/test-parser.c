/**
* \file test-parser.c
* \class parser
* \version \author Marie / Clément / Kévin
* \date 6 december 2018
*
* Allow the parse of the file and fill the tree
*
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <word.h>
#include <tree.h>
#include <hash.h>

#include "parser.h"

/**
* \fn char** printTree(Tree* root_syll,char ** mesSyllabes,char ** syll_valid,int * count_syll)
*
* \return mesSyllabes - return a table of syllables and fill arguments
*/
char** printTree(Tree* root_syll,char ** mesSyllabes,char ** syll_valid,int * count_syll){
	static int n=0;
	static int k=0;
	static int cmtp=0;

	if (tree_get_node(root_syll) != NULL ){
		mesSyllabes[n][cmtp]=((char_word*)tree_get_node(root_syll))->character;
		cmtp++;
		mesSyllabes[n][cmtp]='\0';	

		if (((char_word*)tree_get_node(root_syll))->myWord != NULL){
			count_syll[k]=((char_word*)tree_get_node(root_syll))->counter_syll;
			strcpy(syll_valid[k],mesSyllabes[n]);
			k++;
		}
	}

	for (int i=0;i<tree_child_count(root_syll);i++){
		if (tree_get_node(root_syll)==NULL){
			cmtp=0;
		}	
		printTree(tree_get_child(root_syll,i),mesSyllabes,syll_valid,count_syll); 
	}
	cmtp--;

	if (tree_child_count(root_syll)==0){
		n++;
		strcpy(mesSyllabes[n],mesSyllabes[n-1]);
	}


	return mesSyllabes;
}

/**
* \fn int main(void)
*/
int main (void){

	Tree * root = NULL;
	Tree * root_syll = NULL;
	Hashmap * map;

	Word** tab=parser_read("../src/test.csv", &root, &root_syll, map);

	// Test Mot 
	assert(strcmp(tab[1]->string,"a capella")==0);

	// Test Syllables
	assert(strcmp(tab[1]->syllables[0],"a")==0);
	assert(strcmp(tab[1]->syllables[1],"ca")==0);
	assert(strcmp(tab[1]->syllables[2],"pel")==0);
	assert(strcmp(tab[1]->syllables[3],"la")==0);

	// Test Phon
	assert(strcmp(tab[1]->phonetics[0],"a")==0);
	assert(strcmp(tab[1]->phonetics[1],"ka")==0);
	assert(strcmp(tab[1]->phonetics[2],"pE")==0);
	assert(strcmp(tab[1]->phonetics[3],"la")==0);


	// Test TreeSyll 
	tree_lock(root_syll);

	char ** mesSyllabes= malloc (140);
	char ** syll_valid= malloc (140);
	for (int i=0;i<14;i++){
		mesSyllabes[i]=malloc(10);
	}
	for (int i=0;i<14;i++){
		syll_valid[i]=malloc(10);
	}
	
	int * count_syll=malloc(sizeof(int)*7);
	
	printTree(root_syll,mesSyllabes,syll_valid,count_syll);
	
	int tabInt[]={2,2,2,1,1,1,2};
	char* Tab[]={"a","ca","la","lai","li","lia","pel"};
	
	for (int i=0;i<7;i++){
		assert(strcmp(syll_valid[i],Tab[i])==0);
		assert(count_syll[i]==tabInt[i]);
	}

	return(EXIT_SUCCESS);
}







