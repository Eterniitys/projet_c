#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <word.h>
#include <tree.h>
#include <hash.h>

#include "parser.h"
#include "parser.inc"

void print_tree(Tree* node, int level) {
	char_word* struc = (char_word*)tree_get_node(node);
		for (int i = 0; i < level; i++)
			fprintf(stderr, "|  ", NULL);
		fprintf(stderr, "%p - ", struc);
		fprintf(stderr,"'%c' %u %s\n", struc->character, struc->character, struc->string == NULL ? "" : "->");
	for (int i = 0; i < tree_child_count(node); i++) {
		print_tree(tree_get_child(node, i), level+1);
	}
}

/**
* \fn int main(void)
*/
int main (void){
	
	Tree * root;
	Tree * root_syll;
	Hashmap * map;

	parser_read("../../Lexique382_short.csv", &root, &root_syll, &map);

	print_tree(root_syll, 0);
	parser_destroy_generated_structures(root, root_syll, map);

	return(EXIT_SUCCESS);
}
