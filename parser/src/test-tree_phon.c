#include <assert.h>
#include <hash.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tree.h>
#include <word.h>
#include "parser.h"
#include "parser.inc"

bool is_phon_in_tree(Tree* node, char* phon) {
  if (phon[0] == '\0' && ((char_word*)tree_get_node(node))->string) return true;
  char_word search_char_word = {0};
  (&search_char_word)->character = phon[0];
  Tree* child = tree_find_child(node, &search_char_word);
  if (child) return is_phon_in_tree(child, phon + 1);
  return false;
}

/**
 * \fn int main(void)
 */
int main(void) {
  Tree* root;
  Tree* root_syll;
  Hashmap* map;
  parser_read("../src/test.csv", &root, &root_syll, &map);
  assert(is_phon_in_tree(root, "tSetZ"));

  parser_destroy_generated_structures(root, root_syll, map);
  return (EXIT_SUCCESS);
}
