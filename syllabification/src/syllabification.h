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
};

extern char** syllabicate(Tree* syll_tree, char* word);
void gen_syllables(Tree* node, Tree* syll_tree, char* word);
void recursive(Tree* node, Tree* syll_tree, char* word, int index);

#endif /* _SYLLABIFICATION_H_ */
