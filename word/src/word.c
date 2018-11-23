#include <stdlib.h>
#include "word.h"

///////////////////////////////////CONSTRUCTEUR////////////////////////////////////////////

Word* Word_create (char* string, char** syllabes, char** phonetique) //Constructeur
{

	Word *mot = malloc(sizeof(Word));//boîte pour la struture. Alloue de l'espace pour créer insérer le mot dedans.

	if (mot) 
	{
	 return _fill(mot, string , syllabes, phonetique);
	} else {
		return NULL;
	}

}

Word* _fill ( Word *mot, char *string, char** syllabes, char** phonetique ) //Remplit la boîte pour la structure, c'est ça qui créer effectivement le mot.
{
	mot->mot = string; //le premier mot avant "->" représente le mot créer dans word_create ( ou plutôt la boîte pour la structure )
	mot->syllabes = syllabes;//Ce qui vient après "->" c'est les paramètres de Word_create, et on dit ensuite au programme avec le "=" : " les paramètre de mot sont égaux à ...( les paramètre de _fill )
	mot->phonetique = phonetique;
	return mot;

}

//////////////////////////////////////////SETTER////////////////////////////////////////

Word* Set_mot ( Word* motAmodifier, char* mot ) {

	motAmodifier->mot = mot;

	return motAmodifier;
}

Word** Set_syllabes ( Word** syllabesAmodifier, char** syllabes ) {

	syllabesAmodifier->syllabes = syllabes;

	return syllabesAmodifier;
}

Word** Set_phonetique ( Word** phonetiqueAmodifier, char** phonetique ) {

	phonetiqueAmodifier->phonetique  = phonetique;		

	return phonetiqueAmodifier;
}

//////////////////////////////////////////GETTER/////////////////////////////////////////

char* Get_mot (Word* motArecup) {

return motArecup->mot;

}

char** Get_syllabes (Word** syllabesArecup) {

return syllabesArecup->syllabes;

}

char** Get_phonetique (Word** phoneArecup) {

return phoneArecup->phonetique;

}







