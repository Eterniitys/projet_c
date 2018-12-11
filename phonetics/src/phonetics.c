/**
* \file test-phonetics.c
* \class phonetics
* \author Marie
* \version 0.1
* \date december 11 2018 
*
* fonction - determinate phonetics of words 
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <hash.h>
#include <syllabification.h>

#include "phonetics.h"


/**
*\fn char ** fill_phonetics(char ** tab_phon,char **syllables,Hashmap * hashmap)
*\return tab_phon - return a fill tab with phonetics
*/
char ** fill_phonetics(char ** tab_phon,char **syllables,Hashmap * hashmap){
	tab_phon = malloc(sizeof(char**));
	int i=0;
	while(syllables[i]){
		printf("%s - ",syllables[i]);
		tab_phon[i] = (char*)hashmap_get(hashmap, syllables[i]);
		printf("%s\n",tab_phon[i]);
		i++;	
	}
	return tab_phon;
}

