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

extern List* cutList(List* list);

extern List* arbreEnList(Tree* tree,List* list, int stage);

extern List* finalList(Tree* tree,List* list,char* word,int cpt,int threshold);

#endif /* _RIME_H_ */
