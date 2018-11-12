#ifndef MOT_H_
#define MOT_H_

typedef struct _Mot Mot;

struct _Mot {
  
  char* mot;
  char* syllabes;
  char* phonetique;
 
};
//extern void afficherMot(Mot* motstruct);
/*
extern Mot creer_Mot (char* mot, char** syllabes, char** phonetique);
extern Mot decoupe_Mot(char Mot a);
extern Mot Mot_rime(char Mot c);
*/
#endif

