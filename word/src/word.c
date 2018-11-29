#include <stdlib.h>
#include <string.h>

#include "word.h"

///////////////////////////////////CONSTRUCTEUR////////////////////////////////////////////

Word* word_new (char* string, char** syllables, char** phonetics) //Constructeur
{

	Word* word = malloc(sizeof(Word));//boîte pour la struture. Alloue de l'espace pour créer insérer le word dedans.

	if (word) 
	{
	 return word_fill(word, string , syllables, phonetics);
	} else {
		return NULL;
	}

}

Word* word_fill(Word* word, char* string, char** syllables, char** phonetics) //Remplit la boîte pour la structure, c'est ça qui créer effectivement le word.
{
	word->string = string; //le premier word avant "->" représente le word créer dans word_create ( ou plutôt la boîte pour la structure )
	word->syllables = syllables;//Ce qui vient après "->" c'est les paramètres de Word_create, et on dit ensuite au programme avec le "=" : " les paramètre de word sont égaux à ...( les paramètre de _fill )
	word->phonetics = phonetics;
	return word;

}

//////////////////////////////////////////SETTER////////////////////////////////////////

void word_set_string ( Word* wordToModify, char* string ) {
	
        wordToModify->string = malloc(sizeof(char)*(strlen(string)+1));
	strcpy(wordToModify->string,string);
}


void word_set_syllables ( Word* syllablesToModify, char** syllables ) {

	syllablesToModify->syllables = syllables;

}

void word_set_phonetics ( Word* phoneticsToModify, char** phonetics ) {
	
	phoneticsToModify->phonetics  = phonetics;
		
}

//////////////////////////////////////////GETTER/////////////////////////////////////////

char* word_get_string (Word* wordToGet) {

return wordToGet->string;

}

char** word_get_syllables (Word* syllablesToGet) {

return syllablesToGet->syllables;

}

char** word_get_phonetics (Word* phoneticsToGet) {

return phoneticsToGet->phonetics;

}

//////////////////////////////////////////FREE/////////////////////////////////////////

void word_free(Word* wordToFree){
	int i=0;
	while(wordToFree->syllables[i]){
		free(wordToFree->syllables[i]);
		free(wordToFree->phonetics[i]);
		i++;
	}
	free(wordToFree->string);
	free(wordToFree);

}







