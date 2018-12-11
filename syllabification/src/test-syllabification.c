#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include <word.h>
#include <hash.h>
#include <tree.h>
#include <parser.h>

#include "syllabification.h"

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

int main(void) {
	Tree* tree_phon = NULL;
	Tree* tree_syll = NULL;
	Hashmap* hashmap = NULL;

	parser_read("../../Lexique382.csv", &tree_phon, &tree_syll, &hashmap);

	//print_tree(tree_syll, 0);
	char** syllables = syllabicate(tree_syll, "abasourdi");

	assert(syllables!=NULL);

	return EXIT_SUCCESS;
}

