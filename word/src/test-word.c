#include <stdio.h>
#include "word.h"

int main(int argc, char *argv[]) {

Word* testmot; //On indique que on créer une "boite" vide ( struture a remplir pour mot ). C'est une classe. équivalent à java quand on écrit par exemple : NomDeLaClasse nomdelavariable.

testmot = Word_new("blabla",argv,argv); //argv sont des tableaux de string utilisé pour le test. Ceci est l'équivalent d'un new objet, on remplis la boîte précédente.
printf("test mot : %s\n", testmot->mot);//testmot->mot, ici mot représente le premier paramètre de word_create (blabla), on pourrait donc techniquement obtenir les syllabes et phonétique de la même façon en faisant testmot->syllabes ( si ils étaient remplis )

Set_mot(testmot, "bloublou");
printf("test mot setter : %s\n", testmot->mot);

printf("test du getter\n");
printf(Get_mot(testmot));//s'affiche derrière votre prompt normalement.

return 0;


}
