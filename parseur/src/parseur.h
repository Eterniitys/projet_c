#ifndef _PARSEUR_H_
#define _PARSEUR_H_

#include <stdio.h>
#include <word.h>

//extern void ajoutMotTab(Mot*);
extern long size_file(FILE * fichier);
extern int nbLignes(char* buffer,int sizeFichier);
extern Mot** tableau ();

#endif /* _PARSEUR_H_ */ 
