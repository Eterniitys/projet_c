#ifndef _PARSEUR_H_
#define _PARSEUR_H_

#include <word.h>

typedef struct _char_mot char_mot;

struct _char_mot{
    
    char caractere;
    Mot* monMot;
    
};

extern long size_file(FILE * fichier);
extern int numbers_lines(char* buffer,int sizeFichier);
extern Mot** parseur_read(const char * PATH);
extern Mot** parser_read(const char * PATH);

#endif /* _PARSEUR_H_ */ 

