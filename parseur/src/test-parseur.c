#include <stdlib.h>
#include <stdio.h>

#include "parseur.h"



int main (void){

	Mot** tab=tableau();
	
	printf("%s\n",tab[0]->mot);
	

	return(EXIT_SUCCESS);
}

