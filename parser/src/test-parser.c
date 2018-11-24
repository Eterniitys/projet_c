#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <word.h>

#include "parser.h"



int main (void){

	Word** tab=parser_read("../../Lexique382.csv");

	// test 
	

	printf("Mot : %s\n",tab[3]->mot);
	printf("Syllabes : \n%s\n",tab[3]->syllabes[0]);
	printf("%s\n",tab[3]->syllabes[1]);
	printf("%s\n",tab[3]->syllabes[2]);
	printf("%s\n",tab[3]->syllabes[3]);
	printf("Phonétique : \n%s\n",tab[3]->phonetique[0]);
	printf("%s\n",tab[3]->phonetique[1]);
	printf("%s\n",tab[3]->phonetique[2]);
	printf("%s\n",tab[3]->phonetique[3]);
	
	// TODO : assert 
	
	//assert(tab[3]->mot== "a cappela");
	return(EXIT_SUCCESS);
}


