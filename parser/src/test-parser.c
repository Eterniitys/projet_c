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
 * \fn char** tabSyll(Tree* root_syll,char ** mySyllables,char ** syll_valid,int * count_syll)
 *
 * \return mySyllables - return a table of syllables and fill arguments
 */
char** tabSyll(Tree* root_syll,char ** mySyllables,char ** syll_valid,int * count_syll){
	static int n=0;
	static int k=0;
	static int cmtp=0;

	if (tree_get_node(root_syll) != NULL ){
		mySyllables[n][cmtp]=((char_word*)tree_get_node(root_syll))->character;
		cmtp++;
		mySyllables[n][cmtp]='\0';	

		if (((char_word*)tree_get_node(root_syll))->string != NULL){
			count_syll[k]=((char_word*)tree_get_node(root_syll))->counter_syll;
			strcpy(syll_valid[k],mySyllables[n]);
			k++;
		}
	}

	for (int i=0;i<tree_child_count(root_syll);i++){
		if (tree_get_node(root_syll)==NULL){
			cmtp=0;
		}	
		tabSyll(tree_get_child(root_syll,i),mySyllables,syll_valid,count_syll);
	}
	cmtp--;

	if (tree_child_count(root_syll)==0){
		n++;
		strcpy(mySyllables[n],mySyllables[n-1]);
	}


	return mySyllables;
}

/**
* \fn char** tabPhon(Tree *root,char ** myPhons,char ** phon_valid)
*
* \return myPhons - return a table of phonetics and fill arguments
*/
char** tabPhon(Tree *root,char ** myPhons,char ** phon_valid){
	static int n=0;
	static int k=0;
	static int cmtp=0;
	if (tree_get_node(root) != NULL ){
		myPhons[n][cmtp]=((char_word*)tree_get_node(root))->character;
		cmtp++;
		myPhons[n][cmtp]='\0';	
		if (((char_word*)tree_get_node(root))->string != NULL){
			strcpy(phon_valid[k],myPhons[n]);
			k++;
		}
	}
	for (int i=0;i<tree_child_count(root);i++){
		if (tree_get_node(root)==NULL){
			cmtp=0;
		}	
		tabPhon(tree_get_child(root,i),myPhons,phon_valid);
	}
	cmtp--;
	if (tree_child_count(root)==0){
		
		n++;
		strcpy(myPhons[n],myPhons[n-1]);
	}
	return myPhons;
}

void print_tree(Tree* node, int level) {
	char_word* struc = (char_word*)tree_get_node(node);
	if (struc) {
		for (int i = 0; i < level; i++)
			fprintf(stderr, "|  ");
		fprintf(stderr,"'%c' %u %s\n", struc->character, struc->character, (*struc).string == NULL ? "" : "->");
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
	Hashmap * map=NULL;

	parser_read("../src/test.csv", &root, &root_syll, &map);

	// Test Phonetics 
	char * hash=(char*)hashmap_get(map,"pel");
	assert(strcmp(hash,"pE")==0);

	// TreeSyll test
	char ** mySyllables= malloc (190);
	char ** syll_valid= malloc (180);
	int * count_syll=malloc(sizeof(int)*18);
	for (int i=0;i<19;i++){
		mySyllables[i]=malloc(10);
	}
	for (int i=0;i<18;i++){
		syll_valid[i]=malloc(10);
	}
//superstiteuse	sypERstisj2z	su-per-s-ti-tieu-se	sy-pER-sti-sj2z
	tabSyll(root_syll,mySyllables,syll_valid,count_syll);

	int tabInt[]={2,1,2,1,2,1,1,1,1,1,1,2,1,1,1,1,1,0};
	char* tabSyll[]={"a","anti","ca","con","la","lai","le","li","lia","ment","nnel","pel","sti","t","tio","tu","zte","s"};

	for (int i=0;i<18;i++){
		//assert(strcmp(syll_valid[i],tabSyll[i])==0);
		//assert(count_syll[i]==tabInt[i]);
		printf("%d : %s\n",count_syll[i],tabSyll[i]);
	}

	// tree phon test
	/*char ** myPhons= malloc (140);
	char ** phon_valid= malloc (140);
	for (int i=0;i<5;i++){
		myPhons[i]=malloc(10);
	}
	for (int i=0;i<4;i++){
		phon_valid[i]=malloc(10);
	}
	
	tabPhon(root,myPhons,phon_valid);
	
	
	char* tabPhon[]={"alEpaka","iaLalEpaka","tSetZ","tnemeLennOitUtiTsnociTna"};
	
	for (int i=0;i<4;i++){
		assert(strcmp(phon_valid[i],tabPhon[i])==0);
	}*/

	return(EXIT_SUCCESS);
}

