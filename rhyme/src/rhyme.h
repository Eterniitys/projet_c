#ifndef _RIME_H_
#define _RIME_H_
#include<stdbool.h>
#include <tree.h>


//extern char **parcours(Tree*tree, char phon)
extern void print_tree(Tree* node, int level) ;
//extern bool isVowel(char**phon);
extern Tree*coursePhon(Tree*tree, char phon);
#endif /* _RIME_H_ */
