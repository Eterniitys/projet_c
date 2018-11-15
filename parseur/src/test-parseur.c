#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "parseur.h"



int main (void){

	Mot** tab=tableau();
	printf("%s\n",tab[142682]->syllabes[1]);
	//printf("%s\n",tab[3]->syllabes[0]);
	
	
	
	/*char** mesMots;
	mesMots=malloc(24);
	char * mot=malloc(13);
	*mot='c';
	*(mot+1)=' ';
	*(mot+2)='o';
	
	char* token;
	token = malloc(sizeof(char*));
	const char comp[3]="- ";
	
	token=strtok(mot,comp);
	int j=0;
	while (token != NULL){
		mesMots[j]=token;
		token=malloc(sizeof(char*));
		token=strtok(NULL,comp);
		j++;
	}

	
	printf("%s\n",mesMots[1]);
	
	*/
	return(EXIT_SUCCESS);
}

