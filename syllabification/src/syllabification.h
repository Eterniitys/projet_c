/**
 * \file syllabification.h
 * \author Gregoire
 * \version 0.1
 * \date 29 november 2018
 */

#ifndef _SYLLABIFICATION_H_
#define _SYLLABIFICATION_H_

#include <stdbool.h>
#include <word.h>
#include <tree.h>

typedef struct _StringBool StringBool;
struct _StringBool {
	char* string;
	bool eow;
	int score;
};

/**
 * \fn void print_tree_j(Tree* node, int level)
 *
 * \return void; -Display a tree.
 */
void print_tree_j(Tree* node, int level);

/**
 * \fn bool valid_inside(Tree* root)
 *
 * \return bool; - Look if a word is valid in the tree.
 */
bool valid_inside(Tree* root);

/**
 * \fn Tree* clean_invalid(Tree* root)
 *
 * \return Tree; - Return a tree without syllables which didn't make a word.
 */
Tree* clean_invalid(Tree* root);

/**
 * \fn int score_tree(Tree* root)
 *
 * \return int; - Return the path which have the highest score.
 */
int score_tree(Tree* root);

/**
 * \fn char** get_better_match(Tree* root)
 *
 * \return char**; - Return a tab of words which have the highest score.
 */
char** get_better_match(Tree* root);

/**
 * \fn extern char** syllabicate(Tree* syll_tree, const char* word)
 *
 * \return char**; - Return a tab of syllables of a given word.
 */
extern char** syllabicate(Tree* syll_tree, const char* word);

/**
 * \fn void gen_syllables(Tree* node, Tree* syll_tree, const char* word)
 *
 * \return void; - Generate the syllables of a given word.
 */
void gen_syllables(Tree* node, Tree* syll_tree, const char* word);

/**
 * \fn void recursive(Tree* node, Tree* syll_tree, const char* word, int index)
 *
 * \return void; - Recursivly find valid syllables.
 */
void recursive(Tree* node, Tree* syll_tree, const char* word, int index);

#endif /* _SYLLABIFICATION_H_ */
