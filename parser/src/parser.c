/**
* \file parser.c
* \class parser
* \version 0.1 \author Marie
* \version 0.2 \author Gregoire
* \date 24 november 2018
*
* Allow the parse of the file and fill the tree
*
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <word.h>
#include <tree.h>
#include <hash.h>

#include "parser.h"

/**
* \fn int compare_tree_wordchar (void * node1,void * node2)
*
* \return cm1->character - cm2->character; - return the result of the comparation.
*/
int compare_tree_wordchar (void * node1,void * node2){
	char_word *cm1 = (char_word*)tree_get_node((Tree*)node1);
	char_word *cm2 = (char_word*)tree_get_node((Tree*)node2);
	return cm1->character - cm2->character;
}

/**
* \fn void fill_tree (char* mot,Word * monMot,Tree * node)
*
* \return void - fill the tree
*/
void fill_tree (char* mot, Word * monMot,Tree * node){

	char_word *structure=malloc(sizeof(char_word));
	structure->character=mot[0];
	structure->myWord=NULL;
	structure->counter_syll=0;


	Tree tmpTree;
	(&tmpTree)->_struc=structure;

	Tree* child = tree_find_child(node, &tmpTree);

	if (!child) {
		child = tree_new(structure, compare_tree_wordchar);
		tree_add_child(node, child);
		structure->counter_syll=1;
	}
	else if(mot[1]=='\0'){
		((char_word*)tree_get_node(child))->counter_syll++;
	}

	if (mot[1]=='\0') {
		((char_word*)tree_get_node(child))->myWord=monMot;		
	} else {
		fill_tree(mot + 1, monMot, child);
	}
}



/**
* \fn void reverse_string(char * word)
*
* \return void - reverse a string
*/
void reverse_string(char * word){
	int i=0;
	int len = strlen(word);
	char temp;
	for (i=0 ; i<len/2 ; i++) {
		temp = word[len-i-1];
		word[len-i-1] = word[i];
		word[i] = temp;
	}
}

/**
* \fn long size_file(FILE * fichier)
*
* \return sizeFichier - return the size of the file
*/
long size_file(FILE * fichier){
	long sizeFichier;
	fseek (fichier , 0 , SEEK_END);
	sizeFichier = ftell (fichier);
	return sizeFichier;
}


/**
* \fn char** split_syllables(char* word)
*
* \return realloc(syllables, sizeof(char*)*syl_counter); - return a a char ** split word
*/
char** split_syllables(char* word) {
	// Count first syllable, and add room for terminating NULL pointer
	int counter = 2;

	char* temp_index = word;
	while (*temp_index) {
		if (*temp_index==' ' || *temp_index=='-')
			counter++;
		temp_index++;
	}

	int syl_counter = 0;
	char** syllables = malloc(sizeof(char*)*counter);
	char* syl_point = NULL;
	char* syllable = strtok_r(word, " -", &syl_point);


	while(syllable){
		char* tmp_syl = malloc(strlen(syllable) + 1);
		strcpy(tmp_syl, syllable);
		syllables[syl_counter] = tmp_syl;
		syl_counter++;
		syllable = strtok_r(NULL," -", &syl_point);
	}
	syllables[syl_counter] = NULL;

	return syllables;
}

/**
* \fn Word** parser_read(const char* PATH)
*
* \return words - return a tabs of Word **
*/
Word** parser_read(const char* PATH, Tree** root, Tree** root_syll, Hashmap* map_syl_phon){

	FILE* file;
	file=fopen(PATH, "r");

	if(!file){
		return NULL;
	}
	long size = size_file(file);
	fseek(file, 0, SEEK_SET);
	char* buffer = malloc(size*sizeof(char) + 1);
	fread(buffer, size, 1, file);
	fclose(file);
	buffer[size] = '\0';

	int counter = 0;
	char* pointer = buffer;
	while(pointer - buffer < size) {
		if (*pointer == '\n')
			counter++;
		pointer++;
	}

	*root = tree_new(NULL, compare_tree_wordchar);

	*root_syll = tree_new(NULL, compare_tree_wordchar);

	map_syl_phon = hashmap_new();

	Word** words = malloc(sizeof(Word*)*counter);

	char* file_pointer = NULL;
	counter = 0;
	char* line = strtok_r(buffer, "\n", &file_pointer);
	while(line){
		//initialisation
		char* line_pointer = NULL;
		Word* my_word = malloc(sizeof(Word));
		my_word->string=NULL;
		//word
		char* tmp_word = strtok_r(line, "\t", &line_pointer);
		if (tmp_word) {
			word_set_string(my_word, tmp_word);
		}

		//phonetic
		char* tmp_phon = strtok_r(NULL, "\t", &line_pointer);
		char* phonetic;
		if (tmp_phon) {
			phonetic= malloc(strlen(tmp_phon)+1);
			strcpy(phonetic, tmp_phon);
			reverse_string(phonetic);
			
		}

		//syllables
		char* tmp_syllables = strtok_r(NULL, "\t", &line_pointer);
		char ** mot_tmp;
		if (tmp_syllables){
			mot_tmp=split_syllables(tmp_syllables);
			word_set_syllables(my_word, mot_tmp);
		}

		//phonetic syllables
		char* tmp_syllables_phon = strtok_r(NULL, "\t", &line_pointer);
		if (tmp_syllables_phon)
			word_set_phonetics(my_word, split_syllables(tmp_syllables_phon));

		//fill hashmap
		if (tmp_syllables && tmp_syllables_phon) {
			
			fill_tree(phonetic, my_word, *root);
			
			int k=0;
			while (mot_tmp[k]){
				fill_tree(mot_tmp[k], my_word, *root_syll);
				k++;
			}
				
			int index_syll=0;
			int index_phon=0;

			while (my_word->syllables[index_syll]){
				index_syll++;
			}
			while (my_word->phonetics[index_phon]){
				index_phon++;
			}

			if(index_syll==index_phon){
				int tmp_index = 0;
				while (my_word->syllables[tmp_index]) {
					hashmap_set(map_syl_phon,
						my_word->syllables[tmp_index],
						my_word->phonetics[tmp_index]);
					tmp_index++;
				}
			}

		}

		// word insertion into table
		if (tmp_word && tmp_phon && tmp_syllables && tmp_syllables_phon) {
			words[counter] = my_word;
			counter++;
		} else {
			// free everything
			int i;
			if (tmp_syllables_phon) {
				i=0;
				while (my_word->phonetics[i]) {
					free(my_word->phonetics[i]);
					i++;
				}
				free(my_word->phonetics);
			}
			if (tmp_syllables) {
				i=0;
				while (my_word->syllables[i]) {
					free(my_word->syllables[i]);
					i++;
				}
				free(my_word->syllables);
			}
			if (tmp_phon) {
				// freeing the stuff in the tree is too complex
			}
			if (tmp_word) {
				free(my_word->string);
			}
			free(my_word);
		}
		line = strtok_r(NULL, "\n", &file_pointer);
	}
	tree_lock(*root);
	tree_lock(*root_syll);
	words[counter] = NULL;
	words = realloc(words, sizeof(Word) * (counter+1));
	return words;
}
