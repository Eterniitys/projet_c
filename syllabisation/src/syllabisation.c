#include <stdlib.h>
#include <string.h>
#include <word.h>
#include <tree.h>

#include "syllabisation.h"

char** syllablizer (Tree* tree, char* word){
	char** output = malloc(sizeof(char*)*10);
	int index = 0;
	while(*word!='\0'){
		char* syllable = recursive(tree,word);
		output[index] = syllable;
		index ++;
		word += strlen(syllable);
	}
	output[index] = NULL;
	return realloc(output,sizeof(char*)*index);
}

char* recursive (Tree* node, char* match){
	if(*match=='\0')
		return NULL;
	char_word* structure=malloc(sizeof(char_word));
	structure->character=match[0];
	structure->myWord=NULL;
	
	Tree tmpTree;
	(&tmpTree)->_struc=structure;
	
	Tree* child = tree_find_child(node,&tmpTree);
	
	if(child){
		char* result = recursive(child,match+1);
		if(result){
			char* output = malloc(sizeof(char)*strlen(result)+2);
			strcpy(output+1,result);
			free(result);
			return output;
		} else {
			char_word* struc = tree_get_node(child);
			if(struc->myWord){
				char* output = malloc(sizeof(char)*2);
				output[0]=struc->character;
				output[1]='\0';
				return output;
			}else{
				return NULL;
			}
		}
	}else{
		char_word* struc = tree_get_node(node);
		if(struc->myWord){
			char* output = malloc(sizeof(char)*2);
			output[0]=struc->character;
			output[1]='\0';
			return output;
		}else{
			return NULL;
		}
	}
}
