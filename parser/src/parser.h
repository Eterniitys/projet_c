#ifndef _PARSER_H_
#define _PARSER_H_

#include <tree.h>
#include <word.h>
#include <hash.h>

/**
 * \fn int compare_tree_wordchar (void * node1,void * node2)
 *
 * \return cm1->character - cm2->character; - return the result of the comparation.
 */
int compare_tree_wordchar(void* node1, void* node2);

/**
 * \fn int compare_score (void* score1, void* score2)
 *
 * \return strcmp(tmp1->syllPhon, tmp2->syllPhon); - return the score of the comparation.
 */
int compare_score (void* score1, void* score2);

/**
 * \fn void fill_tree (char* word, char* string, Tree * node)
 *
 * \return void - fill the tree
 */
void fill_tree(const char* mot, char* string, Tree* node);

/**
 * \fn void reverse_string(char * word)
 *
 * \return void - reverse a string
 */
void reverse_string(char* word);

/**
 * \fn long size_file(FILE * fichier)
 *
 * \return sizeFichier - return the size of the file
 */
long size_file(FILE* fichier);

/**
 * \fn char** split_syllables(char* word)
 *
 * \return realloc(syllables, sizeof(char*)*syl_counter); - return a a char ** split word
 */
char** split_syllables(char* word);

/**
 * \fn void fill_hashmap(Hashmap* map, char** syllables, char** phon_sylls, int syll_count)
 *
 * \return void; - fill up hashmap
 */
void fill_hashmap(Hashmap* map, char** syllables, char** phon_sylls, int syll_count);

/**
 * \fn void parse_line(char* line, Hashmap* syll_phon_map, Tree* syll_tree,
 		Tree* phon_tree)
 *
 * \return void; - separate the columns , the lines, , the syllables, phoenitsation of the syllables
 */
void parse_line(char* line, Hashmap* syll_phon_map, Tree* syll_tree,Tree* phon_tree) ;

/**
 * \fn int _compare_pointers(void* a, void* b)
 *
 * \return int  - return a!=b **
 */
int _compare_pointers(void* a, void* b);

/**
 * \fn void _noop_free(void* a)
 *
 * \return void - does nothing **
 */
void _noop_free(void* a) ;

/**
 * \fn void _destroy_map_func(void* value)
 *
 * \return void - destroy list **
 */
void _destroy_map_func(void* value) ;

/**
 * \fn void parser_destroy_generated_structures(Tree* tree1, Tree* tree2, Hashmap* map)
 *
 * \return void - destroy the generated's structures **
 */
extern void parser_destroy_generated_structures(Tree* tree1, Tree* tree2,
		Hashmap* map);

/**
 * \fn void parser_read(const char* PATH, Tree** root, Tree** root_syll, Hashmap** map_syl_phon)
 *
 * \return void - read the parser **
 */
extern void parser_read(const char* PATH, Tree** root, Tree** root_syll,
		Hashmap** map_syl_phon);

#endif /* _PARSER_H_ */
