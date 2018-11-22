#include "word.h"

Word Word_create (char* string, char** syllabes, char** phonetique) //Constructeur
{

	Word *mot = malloc(sizeof(Word));//boîte pour la struture.

	if (mot) 
	{
	 return _fill(mot, string , syllabes, phonetique);
	} else {
		return NULL;
	}

}

Word *_fill ( Word *mot, char *string, char** syllabes, char** phonetique )
{
	mot->mot = string;
	mot->syllabes = syllabes;
	mot->phonetique = phonetique;
	return mot;

}








