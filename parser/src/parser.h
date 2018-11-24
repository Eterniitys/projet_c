#ifndef _PARSER_H_
#define _PARSER_H_

#include <tree.h>
#include <word.h>

extern long size_file(FILE * fichier);
extern Word** parser_read(const char * PATH);
extern int compare_tree_wordchar(void * node1,void * node2);
extern void fill_tree (char* mot, Word * monMot,Tree * node);
extern void reverse_string(char * word);
extern char** split_syllables(char* word);

#endif /* _PARSER_H_ */ 

