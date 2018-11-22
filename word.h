#ifndef MOT_H_
#define MOT_H_

typedef struct _Word Word;

struct _Word {
  
  char* mot;
  char** syllabes;
  char** phonetique;
 
};

extern Word Word_create (char* mot, char** syllabes, char** phonetique); //Constructeur pour créer un mot
/*extern Mot decoupe_Mot(char Mot a);
extern Mot Mot_rime(char Mot c);*/

#endif

