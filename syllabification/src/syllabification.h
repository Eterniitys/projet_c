/**
 * \file syllabification.h
 * \author Gregoire
 * \version 0.1
 * \date 29 november 2018
 */

#ifndef _SYLLABIFICATION_H_
#define _SYLLABIFICATION_H_

#include <stdbool.h>
#include <tree.h>
#include <word.h>

/**
 * \fn extern char** syllabicate(Tree* syll_tree, const char* word)
 *
 * \return output; - Return a tab of syllables of a given word.
 */
extern char** syllabicate(Tree* syll_tree, const char* word);

#endif /* _SYLLABIFICATION_H_ */
