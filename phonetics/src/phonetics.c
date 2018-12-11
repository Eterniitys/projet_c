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
#include <string.h>

#include "phonetics.h"


/**
*\fn char ** fill_phonetics(char ** tab_phon,char **syllables,Hashmap * hashmap)
*\return tab_phon - return a fill tab with phonetics
*/
char ** fill_phonetics(char **syllables,Hashmap * hashmap){
	char **tab_phon = malloc(sizeof(char**)*15);
	int i=0;
	while(syllables[i]){
		printf("%s - ",syllables[i]);
		tab_phon[i] = (char*)hashmap_get(hashmap, syllables[i]);
		printf("%s\n",tab_phon[i]);
		i++;	
	}
	tab_phon[i]=NULL;
	return tab_phon;
}

/**
*\fn char * tab_to_string(char ** tab)
*\return string - return a string (convert string tab in only one string)
*/
char * tab_to_string(char ** tab){
	int i=0;
	char * string=malloc(sizeof(char*)*50);
	while (tab[i]){
		strcat(string,tab[i]);
		i++;
	}
	return string;	 
}


