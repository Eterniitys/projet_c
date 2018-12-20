#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <list.h>
#include <parser.h>
#include <tree.h>
#include <word.h>
#include "rhyme.h"

int main(void) {
  Tree* root = NULL;
  Tree* root2 = NULL;
  Hashmap* hash = NULL;
  parser_read("../../Lexique382_short.csv", &root, &root2, &hash);

  char* para = malloc(sizeof(char) * 7);
  strcpy(para, "be");
  reverse_string(para);
  char* para2 = "§Â";

  List* liste1 = match_word(root, 20, para);
  printf("%i\n", list_count(liste1));
  // afficher la liste
  for (int i = 0; i < list_count(liste1); i++) {
    printf("%d :\t%s\t\t\n", i + 1, (char*)list_get(liste1, i));
    // printf("%s\n",((Word*)list_get(liste1,i))->_word);
  }

  return (EXIT_SUCCESS);
}
