#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tree.h>
#include <word.h>

#include "syllabification.h"
#include "syllabification.inc"

#define C_LENGTH 100
#define C_SCORE 100

bool valid_inside(Tree* root) {
  bool valid = ((StringBool*)tree_get_node(root))->eow;
  if (tree_child_count(root) == 0 && valid) {
    return true;
  }
  for (int i = 0; i < tree_child_count(root); i++) {
    valid = valid_inside(tree_get_child(root, i));
  }
  return valid;
}

Tree* clean_invalid(Tree* root) {
  int i = 0;
  while (i < tree_child_count(root)) {
    if (valid_inside(tree_get_child(root, i))) {
      clean_invalid(tree_get_child(root, i));
      i++;
    } else {
      tree_remove_child(root, i);
    }
  }
  return root;
}

int score_tree(Tree* root) {
  if (tree_child_count(root) == 1) {
    score_tree(tree_get_child(root, 0));
  }
  while (tree_child_count(root) > 1) {
    Tree* child1 = (Tree*)tree_get_child(root, 0);
    Tree* child2 = (Tree*)tree_get_child(root, 1);
    if (score_tree(child1) > score_tree(child2)) {
      tree_remove_child(root, 1);
    } else {
      tree_remove_child(root, 0);
    }
  }
  int score = 0;
  if (tree_get_node(root) != NULL) {
    StringBool* tmp = (StringBool*)tree_get_node(root);
    score = strlen(tmp->string) * C_LENGTH + tmp->score / C_SCORE;
  }
  return score;
}

char** get_better_match(Tree* root) {
  clean_invalid(root);
  score_tree(root);
  int depth = tree_get_depth(root) - 1;
  char** output = malloc(sizeof(char*) * (depth + 1));
  int i = 0;
  Tree* tmp = root;
  while (i < depth) {
    tmp = tree_get_child(tmp, 0);
    output[i] = ((StringBool*)tree_get_node(tmp))->string;
    i++;
  }
  output[i] = NULL;
  return output;
}

char** syllabicate(Tree* syll_tree, const char* word) {
  char** output = malloc(sizeof(char*) * 10);
  int index = 0;
  Tree* root = tree_new(NULL, NULL);
  gen_syllables(root, syll_tree, word);
  output = get_better_match(root);
  return output;
}

void gen_syllables(Tree* root, Tree* syll_tree, const char* word) {
  recursive(root, syll_tree, word, 0);
  int i;
  for (i = 0; i < tree_child_count(root); i++) {
    Tree* child = tree_get_child(root, i);
    StringBool* sb = (StringBool*)tree_get_node(child);
    if (!sb->eow) {
      gen_syllables(child, syll_tree, word + strlen(sb->string));
    }
  }
}

void recursive(Tree* node, Tree* syll_tree, const char* word, int index) {
  if (word[index] == '\0') return;

  char_word newWord;
  newWord.character = word[index];
  newWord.string = NULL;
  newWord.counter_syll = 0;
  Tree* child = tree_find_child(syll_tree, &newWord);

  if (!child) {
    return;
  }

  if (((char_word*)tree_get_node(child))->string) {
    StringBool* sb = malloc(sizeof(StringBool));

    sb->string = malloc(sizeof(char) * index + 2);
    strncpy(sb->string, word, index + 1);
    sb->string[index + 1] = '\0';

    sb->score = ((char_word*)tree_get_node(child))->counter_syll;

    sb->eow = word[index + 1] == '\0';
    Tree* newNode = tree_new(sb, NULL);
    tree_add_child(node, newNode);
  }
  recursive(node, child, word, index + 1);
}
