#include <assert.h>
#include <hash.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tree.h>
#include <word.h>

#include "parser.h"
#include "parser.inc"

/**
 * \fn int main(void)
 */
int main(void) {
  Tree* root;
  Tree* root_syll;
  Hashmap* map;

  parser_read("../src/invalid.csv", &root, &root_syll, &map);

  parser_destroy_generated_structures(root, root_syll, map);

  return (EXIT_SUCCESS);
}
