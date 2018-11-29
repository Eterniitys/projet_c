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
	assert(strcmp(tab[3]->mot,"a capella")==0);

	// Test Syllables
	assert(strcmp(tab[3]->syllabes[0],"a")==0);
	assert(strcmp(tab[3]->syllabes[1],"ca")==0);
	assert(strcmp(tab[3]->syllabes[2],"pel")==0);
	assert(strcmp(tab[3]->syllabes[3],"la")==0);
	
	// Test Phon
	assert(strcmp(tab[3]->phonetique[0],"a")==0);
	assert(strcmp(tab[3]->phonetique[1],"ka")==0);
	assert(strcmp(tab[3]->phonetique[2],"pE")==0);
	assert(strcmp(tab[3]->phonetique[3],"la")==0);

	// Test word not include 
	assert(strcmp(tab[13]->mot,"ab absurdo")==0);
	
	// Test random word
	assert(tab[rand()%140000]->mot != NULL);

	return(EXIT_SUCCESS);
}


