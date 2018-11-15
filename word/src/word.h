#ifndef MOT_H_
#define MOT_H_

typedef struct _Mot Mot;

struct _Mot {
  
  char* mot;
  char** syllabes; //Cette structure n'est actuellement pas utilisé par le parseur.
  char** phonetique;
 
};

extern Mot creer_Mot (char* mot, char** syllabes, char** phonetique);
extern Mot decoupe_Mot(char Mot);
extern Mot Mot_rime(char Mot);

#endif

