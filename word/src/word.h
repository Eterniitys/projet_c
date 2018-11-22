#ifndef MOT_H_
#define MOT_H_

typedef struct _Word Word;

struct _Word {
  
  char* mot;
  char** syllabes;
  char** phonetique;
 
};

//Constructeur pour créer un mot
extern Word* Word_create (char* mot, char** syllabes, char** phonetique); 
Word* _fill(Word *mot, char* string, char** syllabes, char** phonetique);
//Setter
extern Word* Set_mot ( Word* motAmodifier, char* mot );
extern Word** Set_syllabes ( Word** syllabesAmodifier, char** syllabes );
extern Word** Set_phonetique ( Word** phonetiqueAmodifier, char** phonetique );
//Getter
extern Word* Get_mot (Word* motArecup);
extern Word** Get_syllabes (Word** syllabesArecup);
extern Word** Get_phonetique (Word** phoneArecup);

//truc pas développer
/*extern Mot decoupe_Mot(char Mot a);
extern Mot Mot_rime(char Mot c);*/

#endif

