#include "rhyme.h"
#include <stdio.h>
#include <stdlib.h>

#include <tree.h>
#include <word.h>
//#include <parser.h>
#include <list.h>
#include <string.h>

/**
 *use in arbreEnList
 */
char tab[40];

/**
 *use in compare()
 */
char* wordCompar;

void print_tree(Tree* node, int level) {
  char_word* struc;
  if (node) {
    struc = (char_word*)tree_get_node(node);
  }
  if (struc) {
    for (int i = 0; i < level; i++) fprintf(stderr, "|  ", NULL);
    fprintf(stderr, "'%c' %u %s\n", struc->character, struc->character,
            (*struc).string == NULL ? "" : "->");
  }
  for (int i = 0; i < tree_child_count(node); i++) {
    print_tree(tree_get_child(node, i), level + 1);
  }
}

void reverse_string(char* word) {
  int i = 0;
  int len = strlen(word);
  char temp;
  for (i = 0; i < len / 2; i++) {
    temp = word[len - i - 1];
    word[len - i - 1] = word[i];
    word[i] = temp;
  }
}

int compare(void* word1, void* word2) {
  char* un = ((Word*)word1)->_pronunc;
  char* two = ((Word*)word2)->_pronunc;
  int score = 0;
  int i = 0;
  // wordCompar
  while (un[i] == wordCompar[i] && wordCompar[i] != '\0' && un[i] != '\0') {
    score--;
    i++;
  }
  i = 0;
  while (two[i] == wordCompar[i] && wordCompar[i] != '\0' && two[i] != '\0') {
    score++;
    i++;
  }
  return score == 0 ? strcmp(un, two) : score;
}

List* cutList(List* list, int count) {
  List* aList = list_new(NULL);
  int i = 0;
  while (i < count && list_count(list) > i) {
    list_add(aList, ((Word*)list_get(list, i))->_word);
    i++;
  }
  return aList;
}

List* treeToList(Tree* tree, List* list, int stage) {
  // browse all of the tree to get every word

  for (int i = 0; i < tree_child_count(tree); i++) {
    Tree* child = tree_get_child(tree, i);
    // get pointer
    char_word* aWord = (char_word*)tree_get_node(child);
    tab[stage] = aWord->character;
    tab[stage + 1] = '\0';
    // if pointer not NULL add word in the list
    if (aWord && aWord->string) {
      Word* word1 = malloc(sizeof(Word));
      word1->_word = aWord->string;
      word1->_pronunc = malloc(sizeof(char) * strlen(tab) + 1);
      strcpy(word1->_pronunc, tab);
      list_add(list, word1);
    }
    treeToList(child, list, stage + 1);
  }
  return list;
}

void finalList(Tree* tree, List* list, char* word, int cpt, int threshold) {
  if (cpt == 0) {
    wordCompar = word;
  }

  // condition end of word
  if (word[0] == '\0') {
    return;
  }

  char_word structure = {0};
  (&structure)->character = word[0];
  Tree* noeud = tree_find_child(tree, &structure);

  tab[cpt] = word[0];
  tab[cpt + 1] = '\0';

  if (noeud != NULL) {
    cpt++;
    // if the matching of caracter is equal
    if (cpt >= threshold) {
      // recuperation of all childs and put  them in list
      treeToList(noeud, list, cpt);
    } else {
      // research the next caracter of the word
      finalList(noeud, list, word + 1, cpt, threshold);
    }
  }
  list_lock(list);
  return;
}

List* match_word(Tree* tree, int count, char* word) {
  List* output = list_new(&compare);
  finalList(tree, output, word, 0, 2);
  return cutList(output, count);
}
