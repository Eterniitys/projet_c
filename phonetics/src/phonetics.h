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

#ifndef _PHONETICS_H_
#define _PHONETICS_H_

/**
*\fn char ** fill_phonetics(char ** tab_phon,char **syllables,Hashmap * hashmap)
*\return tab_phon - return a fill tab with phonetics
*/
extern char ** fill_phonetics(char **syllables,Hashmap * hashmap);

/**
*\fn char * tab_to_string(char ** tab)
*\return string - return a string (convert string tab in only one string)
*/
extern char * tab_to_string(char ** tab);

/**
*\fn char*  height_score_phon ( List * list)
*\return score.syllPhon - return the structure with the max score
*/
extern char* height_score_phon ( List * list);

#endif /*_PHONETICS_H_*/
