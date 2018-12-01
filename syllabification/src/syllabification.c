#include <stdlib.h>
#include <string.h>
#include <word.h>
#include <tree.h>

#include "syllabification.h"

#include <stdio.h>

char** syllabicate (Tree* tree, char* word){
	char** output = malloc(sizeof(char*)*10);
	int index = 0;
	while(*word!='\0'){
		char* syllable = recursive(tree, word, 0);
		if (syllable) {
			output[index] = syllable;
			index ++;
			word += strlen(syllable);
		} else {
			fprintf(stderr, "Could not syllabicate word\n");
			return NULL;
		}
	}
	output[index] = NULL;
	return realloc(output,sizeof(char*)*index);
}

char* recursive (Tree* node, char* match, int level){
	if(*match=='\0')
		return NULL;
	char_word* structure=malloc(sizeof(char_word));
	structure->character=match[0];
	structure->myWord=NULL;

	Tree tmpTree;
	(&tmpTree)->_struc=structure;
	
	Tree* child = tree_find_child(node,&tmpTree);
	
	if(child){
		char_word* child_struc = (char_word*)tree_get_node(child);
		char* result = recursive(child,match+1, level+1);
		if(result){
			result[level] = match[0];
			return result;
		} else {
			char_word* struc = tree_get_node(node);
			if(struc && struc->myWord){
				char* output = malloc(sizeof(char)*level+1);
				output[level]=match[0];
				output[level+1]='\0';
				return output;
			}else{
				return NULL;
			}
		}
	}else{
		char_word* struc = tree_get_node(node);
		if(struc->myWord){
			char* output = malloc(sizeof(char)*level+1);
			output[level]=match[0];
			output[level+1]='\0';
			return output;
		}else{
			return NULL;
		}
	}
}
