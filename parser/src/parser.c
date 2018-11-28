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
* \return cm1->caractere - cm2->caractere; - return the result of the comparation.
*/
int compare_tree_wordchar (void * node1,void * node2){
	char_mot *cm1 = (char_mot*)tree_get_node((Tree*)node1);
	char_mot *cm2 = (char_mot*)tree_get_node((Tree*)node2);
	return cm1->caractere - cm2->caractere;
}

/**
* \fn void fill_tree (char* mot,Word * monMot,Tree * node)
*
* \return void - fill the tree
*/
void fill_tree (char* mot, Word * monMot,Tree * node){

	char_mot *structure=malloc(sizeof(char_mot));
	structure->caractere=mot[0];
	structure->monMot=NULL;

	Tree tmpTree;
	(&tmpTree)->_struc=structure;

	Tree * nodeBis=tree_find_child(node,&tmpTree); // null si y a pas 

	if (nodeBis==NULL) {
		nodeBis= tree_new_node(structure,compare_tree_wordchar);
		tree_add_node(node, nodeBis);
	}

	if (mot[1]=='\0') {
		structure->monMot=monMot;
	} else {
		fill_tree(mot+1,monMot,nodeBis);
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
Word** parser_read(const char* PATH){
	
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
	
	int counter = 0;
	char* pointer = buffer;
	while(*pointer) {
		if (*pointer == '\n')
			counter++;
		pointer++;
	}
	
	Tree* root = tree_new_node(NULL, compare_tree_wordchar);

	Hashmap* map_syl_phon = hashmap_new();
	
	Word** words = malloc(sizeof(Word*)*counter);

	char* file_pointer = NULL;
	counter = 0;
	char* line = strtok_r(buffer, "\n", &file_pointer);
	while(line){
		//initialisation
		char* line_pointer = NULL;
		Word* my_word = malloc(sizeof(Word));
		
		//word
		char* tmp_word = strtok_r(line, "\t", &line_pointer);
		if (tmp_word) {
			char* word = malloc(strlen(tmp_word)+1);
			strcpy(word, tmp_word);
			my_word->mot=word;
		}

		//phonetique
		char* tmp_phon = strtok_r(NULL, "\t", &line_pointer);
		if (tmp_phon) {
			char* phonetique = malloc(strlen(tmp_phon)+1);
			strcpy(phonetique, tmp_phon);
			reverse_string(phonetique);
			fill_tree(phonetique, my_word, root);
		}

		//syllables
		char* tmp_syllables = strtok_r(NULL, "\t", &line_pointer);
		if (tmp_syllables)
			my_word->syllabes = split_syllables(tmp_syllables);

		//syllables phonetique
		char* tmp_syllables_phon = strtok_r(NULL, "\t", &line_pointer);
		if (tmp_syllables_phon)
			my_word->phonetique = split_syllables(tmp_syllables_phon);

		//fill hashmap
		if (tmp_syllables && tmp_syllables_phon) {
			int tmp_index = 0;
			while (my_word->syllabes[tmp_index]) {
				fprintf(stderr, "Ajout de %s -> %s\n",my_word->syllabes[tmp_index], my_word->phonetique[tmp_index]);
				hashmap_set(map_syl_phon,
					my_word->syllabes[tmp_index],
					my_word->phonetique[tmp_index]);
				tmp_index++;
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
				while (my_word->phonetique[i]) {
					free(my_word->phonetique[i]);
					i++;
				}
				free(my_word->phonetique);
			}
			if (tmp_syllables) {
				i=0;
				while (my_word->syllabes[i]) {
					free(my_word->syllabes[i]);
					i++;
				}
				free(my_word->syllabes);
			}
			if (tmp_phon) {
				// freeing the stuff in the tree is too complex
			}
			if (tmp_word) {
				free(my_word->mot);
			}
			free(my_word);
		}
		line = strtok_r(NULL, "\n", &file_pointer);
	}
	return words;
}
