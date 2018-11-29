#include <stdlib.h>
#include <string.h>

#include "word.h"

///////////////////////////////////CONSTRUCTEUR////////////////////////////////////////////

Word* word_new (char* mot, char** syllabes, char** phonetique) //Constructeur
{

	Word* mot = malloc(sizeof(Word));//boîte pour la struture. Alloue de l'espace pour créer insérer le mot dedans.

	if (mot) 
	{
	 return word_fill(mot, string , syllabes, phonetique);
	} else {
		return NULL;
	}

}

Word* word_fill ( Word* mot, char* string, char** syllabes, char** phonetique ) //Remplit la boîte pour la structure, c'est ça qui créer effectivement le mot.
{
	mot->mot = string; //le premier mot avant "->" représente le mot créer dans word_create ( ou plutôt la boîte pour la structure )
	mot->syllabes = syllabes;//Ce qui vient après "->" c'est les paramètres de Word_create, et on dit ensuite au programme avec le "=" : " les paramètre de mot sont égaux à ...( les paramètre de _fill )
	mot->phonetique = phonetique;
	return mot;

}

//////////////////////////////////////////SETTER////////////////////////////////////////

void word_set_mot ( Word* motAmodifier, char* mot ) {
	
        motAmodifier->mot = malloc(sizeof(char)*(strlen(mot)+1));
	strcpy(motAmodifier->mot,mot);
}


void word_set_syllabes ( Word* syllabesAmodifier, char** syllabes ) {

	syllabesAmodifier->syllabes = syllabes;

}

void word_set_phonetique ( Word* phonetiqueAmodifier, char** phonetique ) {
	
	phonetiqueAmodifier->phonetique  = phonetique;
		
}

//////////////////////////////////////////GETTER/////////////////////////////////////////

char* word_get_mot (Word* motArecup) {

return motArecup->mot;

}

char** word_get_syllabes (Word* syllabesArecup) {

return syllabesArecup->syllabes;

}

char** word_get_phonetique (Word* phoneArecup) {

return phoneArecup->phonetique;

}

//////////////////////////////////////////FREE/////////////////////////////////////////

void word_free(Word* motAliberer){
	int i=0;
	while(motAliberer->syllabes[i]){
		free(motAliberer->syllabes[i]);
		free(motAliberer->phonetique[i]);
		i++;
	}
	free(motAliberer->mot);
	free(motAliberer);

}







