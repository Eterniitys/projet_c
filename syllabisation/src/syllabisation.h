/**
 * \file syllabisation.h
 * \author Gregoire
 * \version 0.1
 * \date 29 november 2018
 */

#ifndef _SYLLABISATION_H_
#define _SYLLABISATION_H_

#include <word.h>
#include <tree.h>

extern char** syllablizer(Tree* tree, char* word);
char* recursive(Tree* node, char* match);

#endif /* _TREE_H_ */
