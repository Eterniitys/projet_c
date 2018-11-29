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
extern Word* word_new (char* mot, char** syllabes, char** phonetique); 
Word* word_fill(Word *mot, char* string, char** syllabes, char** phonetique);
//Setter
extern void word_set_mot ( Word* motAmodifier, char* mot );
extern void word_set_syllabes ( Word* syllabesAmodifier, char** syllabes );
extern void word_set_phonetique ( Word* phonetiqueAmodifier, char** phonetique );
//Getter
extern char* word_get_mot (Word* motArecup);
extern char** word_get_syllabes (Word* syllabesArecup);
extern char** word_get_phonetique (Word* phoneArecup);
//Free
extern void word_free(Word* motAliberer);

#endif


