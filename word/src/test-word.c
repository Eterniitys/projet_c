#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "word.h"

int main(int argc, char *argv[]) {

	Word* testword; 

	char** test = malloc(sizeof(char*)*2);
	test[0]= malloc(sizeof(char)*2);
	strcpy(test[0],"a\0");
	test[1]=NULL;

	char** t = malloc(sizeof(char*)*2);
	t[0]= malloc(sizeof(char)*2);
	strcpy(t[0],"d\0");
	t[1]=NULL;

	char** troll = malloc(sizeof(char*)*2);
	t[0]= malloc(sizeof(char)*2);
	strcpy(t[0],"t\0");
	t[1]=NULL;

	assert(testword = word_new("blabla",test,t));

	Word* tab;

	assert(tab = word_new("test",troll,troll));

	word_set_string(tab, testword->string);

	assert(strcmp(word_get_string(tab),word_get_string(testword))==0);


	word_set_syllables(tab, testword->syllables);
	int cpt = 0;
	while(tab->syllables[cpt]){
		assert(strcmp(tab->syllables[cpt],testword->syllables[cpt])==0);
		cpt++;
	}

	word_set_phonetics(tab, testword->phonetics);
	cpt = 0;
	while(tab->phonetics[cpt]){
		assert(strcmp(tab->phonetics[cpt],testword->phonetics[cpt])==0);
		cpt++;
	}

	word_destroy(testword);

	return 0;
}
