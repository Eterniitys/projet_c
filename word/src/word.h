#ifndef MOT_H_
#define MOT_H_

typedef struct _Word Word;

struct _Word {

	char* mot;
	char** syllabes;
	char** phonetique;

};
typedef struct _char_mot char_mot;
struct _char_mot {
	char caractere;
	Word * monMot;
};
//Constructeur pour créer un mot
extern Word* Word_new (char* mot, char** syllabes, char** phonetique); 
Word* _fill(Word *mot, char* string, char** syllabes, char** phonetique);
//Setter
extern void Set_mot ( Word* motAmodifier, char* mot );
extern void Set_syllabes ( Word* syllabesAmodifier, char** syllabes );
extern void Set_phonetique ( Word* phonetiqueAmodifier, char** phonetique );
//Getter
extern char* Get_mot (Word* motArecup);
extern char** Get_syllabes (Word* syllabesArecup);
extern char** Get_phonetique (Word* phoneArecup);

//truc pas développer
/*extern Mot decoupe_Mot(char Mot a);
  extern Mot Mot_rime(char Mot c);*/

#endif


