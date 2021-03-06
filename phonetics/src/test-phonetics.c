/**
 * \file test-phonetics.c
 * \class phonetics
 * \author Marie
 * \version 0.1
 * \date december 11 2018
 *
 * test - determinate phonetics of words
 *
 */
#include <assert.h>
#include <hash.h>
#include <parser.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syllabification.h>

#include "phonetics.h"

/**
 *\fn int main(void)
 *\ return EXIT_SUCCESS - return a boolean
 */
int main(void) {
  // char* string = "abasourdi";
  char* string = "b";

  Tree* tree_phon = NULL;
  Tree* tree_syll = NULL;
  Hashmap* hashmap = NULL;
  parser_read("../../Lexique382_short.csv", &tree_phon, &tree_syll, &hashmap);

  char** syllables = syllabicate(tree_syll, string);
  char** phonetics = fill_phonetics(syllables, hashmap);
  char* string_phon = tab_to_string(phonetics);

  //	assert(strcmp(string_phon,"abRiko")==0);

  free(phonetics);
  free(syllables);
  free(string_phon);

  parser_destroy_generated_structures(tree_phon, tree_syll, hashmap);

  return EXIT_SUCCESS;
}
