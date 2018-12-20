#ifndef _RIME_H_
#define _RIME_H_
#include<stdbool.h>
#include <tree.h>

typedef struct _Word Word;

struct _Word {
	char* _pronunc;
        char* _word;
};

extern void print_tree(Tree* node, int level) ;

extern void reverse_string(char * word);

extern int compare (void* word1, void*word2);

extern List* cutList(List* list, int count);

extern List* treeToList(Tree* tree,List* list, int stage);

extern void finalList(Tree* tree,List* list,char* word,int cpt,int threshold);

extern List* match_word(Tree* tree, int count, char* word);

#endif /* _RIME_H_ */
