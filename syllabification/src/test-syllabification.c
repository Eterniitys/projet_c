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

void print_tree(Tree* node, int level) {
  char_word* struc = (char_word*)tree_get_node(node);
  if (struc) {
    for (int i = 0; i < level; i++) fprintf(stderr, "|  ", NULL);
    fprintf(stderr, "'%c' %u %s\n", struc->character, struc->character,
            (*struc).string == NULL ? "" : "->");
  }
  for (int i = 0; i < tree_child_count(node); i++) {
    print_tree(tree_get_child(node, i), level + 1);
  }
}

int main(void) {
  Tree* tree_phon = NULL;
  Tree* tree_syll = NULL;
  Hashmap* hashmap = NULL;

  parser_read("../../Lexique382.csv", &tree_phon, &tree_syll, &hashmap);

  // print_tree(tree_syll, 0);
  char** syllables = syllabicate(tree_syll, "abasourdi");
  syllables = syllabicate(tree_syll, "b");

  assert(syllables != NULL);
  int i = 0;
  while (syllables[i]) {
    fprintf(stderr, "%s\n", syllables[i]);
    i++;
  }

  return EXIT_SUCCESS;
}
