/**
 * \file word.c
 * \class word
 * \author Clément & Loïc
 * \version 0.1
 * \date 29 november 2018
 *
 * Allows the creation of a word with the structure of 'word'
 *
 */

#include <stdlib.h>
#include <string.h>

#include "word.h"

///////////////////////////////////CONSTRUCTEUR////////////////////////////////////////////
/**
 * \fn Word* word_new (char* string, char** syllables, char** phonetics)
 *
 * \return word_fill(word, string , syllables, phonetics) - return the word 
 */
Word* word_new (char* string, char** syllables, char** phonetics) 
{

	Word* word = malloc(sizeof(Word));

	if (word) 
	{
	 return word_fill(word, string , syllables, phonetics);
	} else {
		return NULL;
	}

}

/**
 * \fn Word* word_fill(Word* word, char* string, char** syllables, char** phonetics)
 *
 * \return word - return the word fill
 */
Word* word_fill(Word* word, char* string, char** syllables, char** phonetics) 
{
	word->string = string; 
	word->syllables = syllables;
	word->phonetics = phonetics;
	return word;

}

//////////////////////////////////////////SETTER////////////////////////////////////////
/**
 * \fn Word* word_fill(Word* word, char* string, char** syllables, char** phonetics)
 *
 * \return word - return the word fill
 */
void word_set_string ( Word* wordToModify, char* string ) {
	
        wordToModify->string = malloc(sizeof(char)*(strlen(string)+1));
	strcpy(wordToModify->string,string);
}

/**
 * \fn Word* word_fill(Word* word, char* string, char** syllables, char** phonetics)
 *
 * \return word - return the word fill
 */
void word_set_syllables ( Word* syllablesToModify, char** syllables ) {

	syllablesToModify->syllables = syllables;

}

/**
 * \fn Word* word_fill(Word* word, char* string, char** syllables, char** phonetics)
 *
 * \return word - return the word fill
 */
void word_set_phonetics ( Word* phoneticsToModify, char** phonetics ) {
	
	phoneticsToModify->phonetics  = phonetics;
		
}

//////////////////////////////////////////GETTER/////////////////////////////////////////
/**
 * \fn char* word_get_string (Word* wordToGet)
 *
 * \return wordToGet->string - return the the string of the word
 */
char* word_get_string (Word* wordToGet) {

return wordToGet->string;

}

/**
 * \fn char** word_get_syllables (Word* syllablesToGet)
 *
 * \return syllablesToGet->syllables - return the syllables of the word
 */
char** word_get_syllables (Word* syllablesToGet) {

return syllablesToGet->syllables;

}

/**
 * \fn char** word_get_phonetics (Word* phoneticsToGet)
 *
 * \return phoneticsToGet->phonetics - return the phonetics of the word
 */
char** word_get_phonetics (Word* phoneticsToGet) {

return phoneticsToGet->phonetics;

}

//////////////////////////////////////////FREE/////////////////////////////////////////
/**
 * \fn void word_free(Word* wordToFree)
 *
 * \return nothing - just free the allocation of the word
 */
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







