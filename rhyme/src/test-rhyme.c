#include <stdio.h>
#include<stdlib.h>
#include <assert.h>

#include "rhyme.h"
#include <tree.h>
#include <word.h>

int main(void) {

  char * char1= "p e t R O l";
  char * char2="pRotokOl";
//construction mot protocole
char* test = "l";
char* test2 = "O";
char* test3 = "k";
char* test4 = "o";
char* test5 = "t";
char* test6 = "o";
char* test7 = "R";
char* test8 = "p";
//construction mot petrol
char* mot1="l";
char* mot2="O";
char* mot3="R";
char* mot4="t";
char* mot5="e";
char* mot6="p";


Tree *root= tree_new(NULL,NULL);
Tree *prot0 = tree_new(test,NULL);
Tree *prot1 = tree_new(test2,NULL);
Tree *prot2 = tree_new(test3,NULL);
Tree *prot3 = tree_new(test4,NULL);
Tree *prot4 = tree_new(test5,NULL);
Tree *prot5 = tree_new(test6,NULL);
Tree *prot6 = tree_new(test7,NULL);
Tree *prot7 = tree_new(test8,NULL);

Tree *pet0 = tree_new(mot1,NULL);
Tree *pet1 = tree_new(mot2,NULL);
Tree *pet2 = tree_new(mot3,NULL);
Tree *pet3 = tree_new(mot4,NULL);
Tree *pet4 = tree_new(mot5,NULL);
Tree *pet5 = tree_new(mot6,NULL);

//debut arbre
tree_add_child(root,prot0); //node l
tree_add_child(prot0,prot1); //node O
tree_add_child(prot1,prot2);//protocole node k
tree_add_child(prot1,pet2);//petrol node r
//fin de larbre protocol
tree_add_child(prot2,prot3);//protocol node o
tree_add_child(prot3,prot4);//protocol node t
tree_add_child(prot4,prot5);//protocol node o
tree_add_child(prot5,prot6);//protocol node R
tree_add_child(prot6,prot7);//protocol node p
//fin de larbre petrol
tree_add_child(pet2,pet3);//petrol node t
tree_add_child(pet3,pet4);//petrol node e
tree_add_child(pet4,pet5);//petrol node p

//rhyme_find(char2,);

/*
 //pointeur de l'arbre
  printf("pointeur charT :%p  \n",charT );
//ajout d'une node a root
  tree_add_child(root,charT);
  //pointeur de la nouvelle node
  printf("pointeur charT 2 :%p  \n",tree_get_child(root,0) );
  //pointeur de test
  printf("pointeur test :%p  \n",tree_get_node(charT) );
  //transtipage
  printf("val test :%c  \n",*(char*)tree_get_node(charT) );
*/



  return (EXIT_SUCCESS);
}
