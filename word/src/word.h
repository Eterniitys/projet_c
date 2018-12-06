/**
 * \file word.h
 * \class word
 * \author Clément & Loïc
 * \version 0.1
 * \date 29 november 2018
 *
 * Allows the creation of a word with the structure of 'word'
 *
 */

#ifndef MOT_H_
#define MOT_H_

typedef struct _Word Word;

struct _Word {

	char* string;
	char** syllables;
	char** phonetics;

};
typedef struct _char_word char_word;
struct _char_word {

	char character;
	Word * myWord;
	int counter_syll;
};

//Constructor
extern Word* word_new (char* string, char** syllables, char** phonetics); 
Word* word_fill(Word* word, char* string, char** syllables, char** phonetics);
//Setter
extern void word_set_string ( Word* stringToModify, char* string );
extern void word_set_syllables ( Word* syllablesToModify, char** syllables );
extern void word_set_phonetics ( Word* phoneticsToModify, char** phonetics );
//Getter
extern char* word_get_string (Word* stringToGet);
extern char** word_get_syllables (Word* syllablesToGet);
extern char** word_get_phonetics (Word* phoneticsToGet);
//Free
extern void word_destroy(Word* wordToFree);

#endif


