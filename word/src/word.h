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

typedef struct _char_word char_word;
struct _char_word {
  char character;
  char* string;
  int counter_syll;
};

#endif
