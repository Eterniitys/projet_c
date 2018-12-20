#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <word.h>
#include <tree.h>
#include <hash.h>

#include "parser.h"
#include "parser.inc"


/**
* \fn int main(void)
*/
int main (void){
	
	Tree * root;
	Tree * root_syll;
	Hashmap * map;

	parser_read("../src/invalid.csv", &root, &root_syll, &map);

	parser_destroy_generated_structures(root, root_syll, map);

	return(EXIT_SUCCESS);
}


