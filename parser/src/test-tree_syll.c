#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <word.h>
#include <tree.h>
#include <hash.h>

#include "parser.h"

void print_tree(Tree* node, int level) {
	char_word* struc = (char_word*)tree_get_node(node);
	if (struc) {
		for (int i = 0; i < level; i++)
			fprintf(stderr, "|  ", NULL);
		fprintf(stderr,"'%c' %u %s\n", struc->character, struc->character, (*struc).string == NULL ? "" : "->");
	}
	for (int i = 0; i < tree_child_count(node); i++) {
		print_tree(tree_get_child(node, i), level+1);
	}
}

bool is_syll_in_tree(Tree* node, char* syll) {
	if (syll[0] == '\0' && ((char_word*)tree_get_node(node))->string)
		return true;
	
	char_word search_char_word = {0};
	(&search_char_word)->character = syll[0];
	Tree* child = tree_find_child(node, &search_char_word);
	if(child)
		return is_syll_in_tree(child, syll+1);
	return false;
}

/**
* \fn int main(void)
*/
int main (void){
	
	Tree * root;
	Tree * root_syll;
	Hashmap * map;

	parser_read("../src/test.csv", &root, &root_syll, &map);

	assert(is_syll_in_tree(root_syll, "nnel"));
	assert(is_syll_in_tree(root_syll, "lai"));
	assert(is_syll_in_tree(root_syll, "la"));
	
	return(EXIT_SUCCESS);
}

