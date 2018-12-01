/**
 * \file syllabification.h
 * \author Gregoire
 * \version 0.1
 * \date 29 november 2018
 */

#ifndef _SYLLABIFICATION_H_
#define _SYLLABIFICATION_H_

#include <word.h>
#include <tree.h>

extern char** syllabicate(Tree* tree, char* word);
char* recursive(Tree* node, char* match, int level);

#endif /* _SYLLABIFICATION_H_ */
