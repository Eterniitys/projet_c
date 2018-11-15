#ifndef MOT_H_
#define MOT_H_

typedef struct _Mot Mot;

struct _Mot {
  
  char* mot;
  char** syllabes; //Cette structure n'est actuellement pas utilisé par le parseur.
  char** phonetique;
 
};
/*
extern Mot *creer_Mot (char* mot, char** syllabes, char** phonetique);
extern Mot *word_fill ( Mot *mot, char** syllabes, char** phonetique );
extern Mot *decoupe_Mot(Mot *a);
extern Mot Mot_rime(Mot *m);
*/
#endif

