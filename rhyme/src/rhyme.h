#ifndef _RIME_H_
#define _RIME_H_
#include <stdbool.h>
#include <tree.h>

typedef struct _Word Word;

struct _Word {
  char* _pronunc;
  char* _word;
};

/**
 * \fn void print_tree(Tree* node, int level)
 *
 * \return void - Print a tree.
 */
extern void print_tree(Tree* node, int level);

/**
 * \fn void reverse_string(char * word)
 *
 * \return void - Reverse a string.
 */
extern void reverse_string(char* word);

/**
 * \fn int compare (void* word1, void*word2)
 *
 * \return score - Compare 2 list.
 */
extern int compare(void* word1, void* word2);

/**
 * \fn List* cutList(List* list, int count)
 *
 * \return aList - Limit to 20 values.
 */
extern List* cutList(List* list, int count);

/**
 * \fn List* treeToList(Tree* tree,List* list, int stage)
 *
 * \return list - Allow to make a list from tree.
 */
extern List* treeToList(Tree* tree, List* list, int stage);

/**
 * \fn void finalList(Tree* tree,List* list,char* word,int cpt,int threshold)
 *
 * \return void - Display the final list based on a given matching character
 * threshold.
 */
extern void finalList(Tree* tree, List* list, char* word, int cpt,
                      int threshold);

/**
 * \fn List* match_word(Tree* tree, int count, char* word)
 *
 * \return List* - Return a cut list.
 */
extern List* match_word(Tree* tree, int count, char* word);

#endif /* _RIME_H_ */
