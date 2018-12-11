/**
* \file test-phonetics.c
* \class phonetics
* \author Marie
* \version 0.1
* \date december 11 2018 
*
* test - determinate phonetics of words 
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <hash.h>
#include <syllabification.h>
#include <parser.h>
#include <assert.h>
#include <string.h>

#include "phonetics.h"

/**
*\fn int main(void)
*\ return EXIT_SUCCESS - return a boolean 
*/
int main(void){

	char* string = "lampadaire";
	
	Tree* tree_phon = NULL;
	Tree* tree_syll = NULL;
	Hashmap* hashmap = NULL;
	Word** output = parser_read("../../Lexique382.csv", &tree_phon, &tree_syll, &hashmap);
	
	char** syllables = syllabicate(tree_syll, string);
	char ** phonetics = fill_phonetics(phonetics,syllables,hashmap);
	
	assert(strcmp(phonetics[0],"l@")==0);
	assert(strcmp(phonetics[1],"pad")==0);
	assert(strcmp(phonetics[2],"ER")==0);
	assert(strcmp(phonetics[3],"Re")==0);
	
	hashmap_destroy(hashmap);
	tree_destroy(tree_phon);
	tree_destroy(tree_syll);
	return EXIT_SUCCESS;
}
