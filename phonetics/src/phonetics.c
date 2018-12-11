#include <stdio.h>
#include <stdlib.h>
#include <hash.h>
#include <syllabification.h>

#include "phonetics.h"

// mot --> syllabification --> hash

char ** fille_phonetics(char ** tab_phon,char **syllables){

	int i=0;
	while(syllables[i]){
		phonetics[i] = (char*)hashmap_get(hashmap, syllables[i]);
	}
	return phonetics;
}

