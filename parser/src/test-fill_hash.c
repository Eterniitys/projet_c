#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <word.h>
#include <list.h>
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
	parser_read("../src/test.csv", &root, &root_syll, &map);
	
	
	List * list_phon;
	list_phon = (List*)hashmap_get(map,"pel");
	
	ScoreSyllPhon* score = (ScoreSyllPhon*)list_get(list_phon,0);
	ScoreSyllPhon* score1 = (ScoreSyllPhon*)list_get(list_phon,1);

	
	assert(list_count(list_phon)==2);
	assert(strcmp(score->syllPhon,"pE")==0);
	assert(score->score == 1);
	
	assert(strcmp(score1->syllPhon,"PE")==0);
	assert(score1->score == 1);
	
	parser_destroy_generated_structures(root, root_syll, map);
	return(EXIT_SUCCESS);
}
