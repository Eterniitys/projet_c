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

	char* string = "abricot";

	Tree* tree_phon = NULL;
	Tree* tree_syll = NULL;
	Hashmap* hashmap = NULL;
	parser_read("../../Lexique382_short.csv", &tree_phon, &tree_syll, &hashmap);

	char** syllables = syllabicate(tree_syll, string);
	char ** phonetics = fill_phonetics(syllables,hashmap);
	char * string_phon=tab_to_string(phonetics);

	assert(strcmp(string_phon,"abRiko")==0);

	
	int i=0;
	while(phonetics[i]){
		free(phonetics[i]);
		i++;
	}
	
	i=0;
	while(syllables[i]){
		free(syllables[i]);
		i++;
	}
	
	free(phonetics);
	free(syllables);
	free(string_phon);
	
	parser_destroy_generated_structures(tree_phon, tree_syll, hashmap);

	return EXIT_SUCCESS;
}
