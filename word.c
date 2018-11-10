include "word.h"

Mot creer_Mot (char* mot, char** syllabes, char** phonetique)
{

	Mot *mot = malloc(sizeof(Mot));

	if (mot) 
	{
	 return _fill(mot, syllabes, phonetique);
	} else {
		return NULL;
	}

}

Mot *_fill ( Mot *mot, char** syllabes, char** phonetique )
{

	mot->syllabes = syllabes;
	mot->phonetique = phonetique;
	return mot;

}


Mot decoupe_Mot(char Mot a)
{
	//TODO
	return a;
}





