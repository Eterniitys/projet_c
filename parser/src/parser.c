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
#include <stdbool.h>
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
 * \fn void fill_tree (char* mot, char* string, Tree * node)
 *
 * \return void - fill the tree
 */
void fill_tree (char* mot, char* string, Tree * node){

	char_word *structure=malloc(sizeof(char_word));
	structure->character=mot[0];
	structure->string=NULL;
	structure->counter_syll=0;


	Tree tmpTree;
	(&tmpTree)->_struc=structure;

	Tree* child = tree_find_child(node, &tmpTree);

	if (!child) {
		child = tree_new(structure, compare_tree_wordchar);
		tree_add_child(node, child);
		if (mot[1]=='\0'){
			structure->counter_syll=1;	
		}


	}
	else if(mot[1]=='\0'){
		((char_word*)tree_get_node(child))->counter_syll++;
	}

	if (mot[1]=='\0') {
		((char_word*)tree_get_node(child))->string=string;		
	} else {
		fill_tree(mot + 1, string, child);
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
void parser_read(const char* PATH, Tree** root, Tree** root_syll, Hashmap** map_syl_phon){
	FILE* file;
	file=fopen(PATH, "r");

	if(!file){
		return;
	}
	long size = size_file(file);
	fseek(file, 0, SEEK_SET);
	char* buffer = malloc(size*sizeof(char) + 1);
	fread(buffer, size, 1, file);
	fclose(file);
	buffer[size] = '\0';

	*root = tree_new(NULL, compare_tree_wordchar);

	*root_syll = tree_new(NULL, compare_tree_wordchar);

	*map_syl_phon = hashmap_new();

	char* file_pointer = NULL;
	char* line = strtok_r(buffer, "\n", &file_pointer);
	while(line){
		//initialisation
		char* line_pointer = NULL;

		//word
		char* tmp_word = strtok_r(line, "\t", &line_pointer);
		char* word = NULL;
		if (tmp_word) {
			word = malloc(sizeof(char)*(strlen(tmp_word)+1));
			strcpy(word, tmp_word);
		}

		//phonetic
		char* tmp_phon = strtok_r(NULL, "\t", &line_pointer);
		char* phonetic = NULL;
		if (tmp_phon) {
			phonetic= malloc(strlen(tmp_phon)+1);
			strcpy(phonetic, tmp_phon);
			reverse_string(phonetic);
		}

		//syllables
		char* tmp_syllables = strtok_r(NULL, "\t", &line_pointer);
		char ** mot_tmp = NULL;
		if (tmp_syllables){
			mot_tmp=split_syllables(tmp_syllables);
		}

		//phonetic syllables
		char* tmp_syllables_phon = strtok_r(NULL, "\t", &line_pointer);
		char** phon_sylls = NULL;
		if (tmp_syllables_phon)
			phon_sylls = split_syllables(tmp_syllables_phon);

		// fill hashmap and some trees
		if (tmp_word && tmp_phon && tmp_syllables && tmp_syllables_phon) {
			int index_syll=0;
			int index_phon=0;

			while (mot_tmp[index_syll]){
				index_syll++;
			}
			while (phon_sylls[index_phon]){
				index_phon++;
			}
			
			if(index_syll==index_phon){

				fill_tree(phonetic, word, *root);
				int k=0;
				while (mot_tmp[k]){
					fill_tree(mot_tmp[k], word, *root_syll);
					k++;
				}

				int tmp_index = 0;
				while (tmp_index < index_syll) {
					hashmap_set(*map_syl_phon,
							mot_tmp[tmp_index],
							phon_sylls[tmp_index]);
					tmp_index++;
				}
			}
		} else {
			// free everything
			int i;
			if (tmp_syllables_phon) {
				i=0;
				while (phon_sylls[i]) {
					free(phon_sylls[i]);
					i++;
				}
				free(phon_sylls);
			}
			if (tmp_syllables) {
				i=0;
				while (mot_tmp[i]) {
					free(mot_tmp[i]);
					i++;
				}
				free(mot_tmp);
			}
			if (tmp_phon) {
				// freeing the stuff in the tree is too complex
			}
			if (tmp_word) {
				free(word);
			}
		}
		line = strtok_r(NULL, "\n", &file_pointer);
	}
	tree_lock(*root);
	tree_lock(*root_syll);
}

