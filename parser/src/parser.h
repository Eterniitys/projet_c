#ifndef _PARSEUR_H_
#define _PARSEUR_H_

#include <word.h>

typedef struct _char_mot char_mot;

struct _char_mot{
    
    char caractere;
    Mot* monMot;
    
};

extern long size_file(FILE * fichier);
extern Mot** parser_read(const char * PATH);
extern compare_tree_wordchar(void * node1,void * node2);
extern void fill_tree (char* mot,Mot * monMot,Tree * node);
extern void reverse_string(char * word);
extern char** split_syllables(char* word);

#endif /* _PARSEUR_H_ */ 

