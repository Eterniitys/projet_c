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


int compare_score (void* score1, void* score2){
	ScoreSyllPhon * tmp1 = (ScoreSyllPhon*) score1;
	ScoreSyllPhon * tmp2 = (ScoreSyllPhon*) score2;

	int score = tmp1->score - tmp2->score;
	if (score == 0){
		score = strcmp(tmp1->syllPhon, tmp2->syllPhon);
	}
	return score;
}


/**
 * \fn void fill_tree (char* word, char* string, Tree * node)
 *
 * \return void - fill the tree
 */
void fill_tree(const char* mot, char* string, Tree * node){

	char_word* structure=malloc(sizeof(char_word));
	structure->character=mot[0];
	structure->string=NULL;
	structure->counter_syll=0;

	Tree* child = tree_find_child(node, structure);

	if (child) {
		free(structure);
	}

	if (!child) {
		child = tree_new(structure, compare_tree_wordchar);
		tree_add_child(node, child);
		if (mot[1]=='\0'){
			structure->counter_syll=1;
		}
	} else if(mot[1]=='\0'){
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

void fill_hashmap(Hashmap* map, char** syllables, char** phon_sylls, int syll_count) {
	int index = 0;
	while (syllables[index]) {
		List* list_phon;
		list_phon=(List*)hashmap_get(map, syllables[index]);
		if (!list_phon) {
			list_phon = list_new(&compare_score);
			hashmap_set(map, syllables[index], list_phon);
		}

		// Find phonetic in list
		ScoreSyllPhon search_score = {0};
		(&search_score)->score=0;
		(&search_score)->syllPhon = phon_sylls[index];
		ScoreSyllPhon* score = (ScoreSyllPhon*)list_find(list_phon, &search_score);

		if (!score) {
			score = malloc(sizeof(ScoreSyllPhon));
			list_add(list_phon, score);

			score->score=0;
			score->syllPhon=phon_sylls[index];
		}
		score->score++;
		index++;
	}
}

void parse_line(char* line, Hashmap* syll_phon_map, Tree* syll_tree,
		Tree* phon_tree) {
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
	char ** word_tmp = NULL;
	if (tmp_syllables){
		word_tmp=split_syllables(tmp_syllables);
	}

	//phonetic syllables
	char* tmp_syllables_phon = strtok_r(NULL, "\t", &line_pointer);
	char** phon_sylls = NULL;
	if (tmp_syllables_phon)
		phon_sylls = split_syllables(tmp_syllables_phon);

	// fill hashmap and some trees
	if (tmp_word && tmp_phon && word_tmp && phon_sylls) {
		// Check both tables have the same length, and save the count
		int index_syll=0;
		while (word_tmp[index_syll]){
			index_syll++;
		}
		int syll_count=index_syll;
		index_syll=0;
		while (phon_sylls[index_syll]){
			index_syll++;
		}

		// If both tables have same length
		if(index_syll==syll_count){
			// Fill trees
			fill_tree(phonetic, word, phon_tree);
			int k=0;
			while (word_tmp[k]){
				fill_tree(word_tmp[k], word, syll_tree);
				k++;
			}
			// Fill hashmap
			fill_hashmap(syll_phon_map, word_tmp, phon_sylls, syll_count);
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
			while (word_tmp[i]) {
				free(word_tmp[i]);
				i++;
			}
			free(word_tmp);
		}
		if (tmp_phon) {
			free(phonetic);
		}
		if (tmp_word) {
			free(word);
		}
	}
}

int _compare_pointers(void* a, void* b) {
	return a != b;
}

List* _freed_strings = NULL;

void _free_once_string(char* string) {
	char* is_freed = (char*)list_find(_freed_strings, string);
	if (is_freed == 0) {
		list_add(_freed_strings, string);
		free(string);
	}
}

void _destroy_func(void* node) {
	char_word* chwd = (char_word*)node;

	if (chwd->string) {
		_free_once_string(chwd->string);
	}
	free(chwd);
}

void _destroy_map_func(void* value) {
	List* list = (List*)value;
	for (int i=0; i<list_count(list); i++) {
		ScoreSyllPhon* score = (ScoreSyllPhon*)list_get(list, i);
		_free_once_string(score->syllPhon);
	}
	list_destroy(list, &free);
}

void _noop_free(void* a) {}

void parser_destroy_generated_structures(Tree* tree1, Tree* tree2, Hashmap* map)
		{
	_freed_strings = list_new(&_compare_pointers);

	tree_destroy(tree1, &_destroy_func);
	tree_destroy(tree2, &_destroy_func);
	hashmap_destroy(map, &_destroy_map_func);

	list_destroy(_freed_strings, &_noop_free);
	_freed_strings = NULL;
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

	char_word* root_node = (char_word*)malloc(sizeof(char_word));
	root_node->character='\0';
	root_node->string=NULL;
	root_node->counter_syll = 0;
	*root = tree_new(root_node, compare_tree_wordchar);

	char_word* root_syll_node = (char_word*)malloc(sizeof(char_word));
	root_syll_node->character='\0';
	root_syll_node->string=NULL;
	root_syll_node->counter_syll = 0;
	*root_syll = tree_new(root_syll_node, compare_tree_wordchar);

	*map_syl_phon = hashmap_new();

	char* file_pointer = NULL;
	char* line = strtok_r(buffer, "\n", &file_pointer);

	while(line){
		parse_line(line, *map_syl_phon, *root_syll, *root);
		line = strtok_r(NULL, "\n", &file_pointer);
	}
	tree_lock(*root);
	tree_lock(*root_syll);
	free(buffer);
}

