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

char** tabPhon(Tree *root,char ** mesPhon,char ** phon_valid){
	static int n=0;
	static int k=0;
	static int cmtp=0;
	if (tree_get_node(root) != NULL ){
		mesPhon[n][cmtp]=((char_word*)tree_get_node(root))->character;
		cmtp++;
		mesPhon[n][cmtp]='\0';	
		if (((char_word*)tree_get_node(root))->myWord != NULL){
			strcpy(phon_valid[k],mesPhon[n]);
			k++;
		}
	}
	for (int i=0;i<tree_child_count(root);i++){
		if (tree_get_node(root)==NULL){
			cmtp=0;
		}	
		tabPhon(tree_get_child(root,i),mesPhon,phon_valid); 
	}
	cmtp--;
	if (tree_child_count(root)==0){
		
		n++;
		strcpy(mesPhon[n],mesPhon[n-1]);
	}
	return mesPhon;
}

void afficher(Tree * root){
	if (tree_get_node(root) != NULL ){
		printf("%c\n",((char_word*)tree_get_node(root))->character);
	}
	for (int i=0;i<tree_child_count(root);i++){
		afficher(tree_get_child(root,i)); 
	}
}
void print_tree(Tree* node, int level) {
	char_word* struc = (char_word*)tree_get_node(node);
	if (struc) {
		for (int i = 0; i < level; i++)
			fprintf(stderr, "|  ", NULL);
		fprintf(stderr,"'%c' %u %s\n", struc->character, struc->character, (*struc).myWord == NULL ? "" : "->");
	}
	for (int i = 0; i < tree_child_count(node); i++) {
		print_tree(tree_get_child(node, i), level+1);
	}
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
	//tree_lock(root_syll);
	
/*
	char ** mesSyllabes= malloc (160);
	char ** syll_valid= malloc (160);
	for (int i=0;i<16;i++){
		mesSyllabes[i]=malloc(10);
	}
	for (int i=0;i<9;i++){
		syll_valid[i]=malloc(10);
	}

	int * count_syll=malloc(sizeof(int)*9);

	printTree(root_syll,mesSyllabes,syll_valid,count_syll);

	int tabInt[]={4,2,2,1,1,1,2,1,1};
	char* tabSyll[]={"a","ca","la","lai","li","lia","pel","tes","st"};

	for (int i=0;i<9;i++){
		assert(strcmp(syll_valid[i],tabSyll[i])==0);
		assert(count_syll[i]==tabInt[i]);
	}

	// Test phon
	
	//tree_lock(root);
	
	
	
	char ** mesPhon= malloc (140);
	char ** phon_valid= malloc (140);
	for (int i=0;i<3;i++){
		mesPhon[i]=malloc(10);
	}
	for (int i=0;i<2;i++){
		phon_valid[i]=malloc(10);
	}
	
	tabPhon(root,mesPhon,phon_valid);
	
	
	char* tabPhon[]={"alEpaka","iaLalEpaka"};
	
	
	for (int i=0;i<2;i++){
		//printf("%s : %s\n",phon_valid[i],tabPhon[i]);
		//assert(strcmp(phon_valid[i],tabPhon[i])==0);
	}
*/
	print_tree(root,0);
	return(EXIT_SUCCESS);
}








