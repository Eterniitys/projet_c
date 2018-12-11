#ifndef _RIME_H_
#define _RIME_H_
#include<stdbool.h>
#include <tree.h>


//extern char **parcours(Tree*tree, char phon)
extern void print_tree(Tree* node, int level) ;

extern Tree*coursePhon(Tree*tree, char phon);

extern List* arbreEnList(Tree* tree,List* list);

extern List* finalList(Tree* tree,List* list,char* word,int threshold);

#endif /* _RIME_H_ */
