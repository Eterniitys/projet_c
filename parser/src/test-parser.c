#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <word.h>
#include <tree.h>
#include <hash.h>

#include "parser.h"



int main (void){
	
	Tree * root;
	Tree * root_syll;
	Hashmap * map;

	Word** tab=parser_read("../../Lexique382.csv", root, root_syll, map);

	// Test Mot 
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
	assert(tab[rand()%140000]->string != NULL);

	return(EXIT_SUCCESS);
}


