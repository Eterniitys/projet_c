#include <stdio.h>
#include <stdlib.h>
#include <hash.h>
#include <syllabification.h>
#include <parser.h>

#include "phonetics.h"

int main(void){

	char* string = "test";
	
	Tree* tree_phon = NULL;
	Tree* tree_syll = NULL;
	Hashmap* hashmap = NULL;
	Word** output = parser_read("../../Lexique382.csv", &tree_phon, &tree_syll, &hashmap);
	
	char** syllables = syllabicate(tree_syll, string);
		
	char ** phonetics = malloc sizeof(char**);
	
	fille_phonetics(phonetics,syllables);
	
	printf("%s\n",phonetics[0]);
	
	hashmap_destroy(map);
	tree_destroy(tree_phon);
	tree_destroy(tree_syll);
	return EXIT_SUCCESS;
}
