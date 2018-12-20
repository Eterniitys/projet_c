#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <hash.h>
#include <parser.h>
#include <tree.h>
#include <word.h>

#include "syllabification.h"
#include "syllabification.inc"

int main(void) {
  Tree* tree_phon = NULL;
  Tree* tree_syll = NULL;
  Hashmap* hashmap = NULL;

  parser_read("../../Lexique382_short.csv", &tree_phon, &tree_syll, &hashmap);

  char** syllables = syllabicate(tree_syll, "abasourdi");
  syllables = syllabicate(tree_syll, "b");

  assert(syllables != NULL);

  return EXIT_SUCCESS;
}
