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

bool is_syll_in_tree(Tree* node, char* syll) {
  if (syll[0] == '\0' && ((char_word*)tree_get_node(node))->string) return true;

  char_word search_char_word = {0};
  (&search_char_word)->character = syll[0];
  Tree* child = tree_find_child(node, &search_char_word);
  if (child) return is_syll_in_tree(child, syll + 1);
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

  assert(is_syll_in_tree(root_syll, "nnel"));
  assert(is_syll_in_tree(root_syll, "lai"));
  assert(is_syll_in_tree(root_syll, "la"));

  // print_tree(root_syll, 0);
  parser_destroy_generated_structures(root, root_syll, map);

  return (EXIT_SUCCESS);
}
