#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <word.h>
#include <tree.h>
#include <hash.h>

#include "parser.h"


/**
* \fn int main(void)
*/
int main (void){
	
	Tree * root;
	Tree * root_syll;
	Hashmap * map;

	Word** tab=parser_read("../src/invalid.csv", &root, &root_syll, &map);

	int index = 0;
	assert(strcmp(word_get_string(tab[index]),"a\0") == 0);


	return(EXIT_SUCCESS);
}


