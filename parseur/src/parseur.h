#ifndef _PARSEUR_H_
#define _PARSEUR_H_

#include <word.h>


extern long size_file(FILE * fichier);
extern int numbers_lines(char* buffer,int sizeFichier);
extern Mot** parseur_read(const char * PATH);

#endif /* _PARSEUR_H_ */ 

