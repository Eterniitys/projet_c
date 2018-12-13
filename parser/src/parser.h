#ifndef _PARSER_H_
#define _PARSER_H_

#include <tree.h>
#include <word.h>
#include <hash.h>

int compare_tree_wordchar(void* node1, void* node2);
void fill_tree(const char* mot, char* string, Tree* node);
void reverse_string(char* word);
long size_file(FILE* fichier);
char** split_syllables(char* word);
extern void parser_read(const char* PATH, Tree** root, Tree** root_syll, Hashmap** map_syl_phon);

#endif /* _PARSER_H_ */

