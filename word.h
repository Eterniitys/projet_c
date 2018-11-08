#ifndef MOT_H_
#define MOT_H_

typedef struct _Mot Mot;

struct _Mot {
  char* mot;
  char** syllabes;
  char* phonetique;
  char* phonetique_syllabes;
};

extern Mot Mot_syllabes(char Mot a);
extern Mot Mot_phonetique(char Mot b);
extern Mot Mot_rime(char Mot c);

#endif
