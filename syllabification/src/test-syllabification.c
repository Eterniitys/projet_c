#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include <word.h>
#include <hash.h>
#include <tree.h>
#include <parser.h>

#include "syllabification.h"

int main(void) {
	Tree* tree_phon = NULL;
	Tree* tree_syll = NULL;
	Hashmap* hashmap = NULL;

	Word** output = parser_read("../../Lexique382.csv", &tree_phon, &tree_syll, hashmap);

	char** syllables = syllabicate(tree_syll, "a capella");

	assert(syllables!=NULL);

	if (syllables) {
		int i=0;
		while (syllables[i]) {
			fprintf(stderr, "%s\n", syllables[i]);
			i++;
		}
	}

	return EXIT_SUCCESS;
}

