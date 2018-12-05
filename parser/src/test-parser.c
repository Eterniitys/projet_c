#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <word.h>
#include <tree.h>
#include <hash.h>

#include "parser.h"

char** printTree(Tree* root_syll,char ** mesSyllabes,char ** syll_valid){
	static int n=0;
	static int k=0;
	static int cmtp=0;

	if (tree_get_node(root_syll) != NULL ){
		mesSyllabes[n][cmtp]=((char_word*)tree_get_node(root_syll))->character;
		cmtp++;
		mesSyllabes[n][cmtp]='\0';	
		
		if (((char_word*)tree_get_node(root_syll))->myWord != NULL){
			syll_valid[k]=mesSyllabes[n];
			k++;
		}
	}

	for (int i=0;i<tree_child_count(root_syll);i++){
		if (tree_get_node(root_syll)==NULL){
			cmtp=0;
		}	
		printTree(tree_get_child(root_syll,i),mesSyllabes,syll_valid); 
	}

	cmtp--;

	if (tree_child_count(root_syll)==0){
		n++;
		strcpy(mesSyllabes[n],mesSyllabes[n-1]);
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
	char ** syll_valid= malloc (150);
	for (int i=0;i<14;i++){
		mesSyllabes[i]=malloc(10);
	}

	printTree(root_syll,mesSyllabes,syll_valid);


	char* Tab[]={"a","bel","bem","bet","la","li","lia","lidf","lioe","loe","lu","pel","queux","qz"};
	for (int i=0;i<14;i++){
		//assert(strcmp(mesSyllabes[i],Tab[i])==0);
		printf("%d.%s=%s\n",i+1,Tab[i],syll_valid[i]);
	}




	return(EXIT_SUCCESS);
}






