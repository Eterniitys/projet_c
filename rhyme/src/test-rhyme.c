#include <stdio.h>
#include<stdlib.h>
#include <assert.h>
#include<string.h>

#include "rhyme.h"
#include <tree.h>
#include<parser.h>
#include <word.h>
#include<list.h>

int main(void) {

Tree *root= NULL;
Tree *root2= NULL;
Hashmap* hash= NULL;
parser_read("../../Lexique382.csv",&root,&root2,&hash);


Tree* noeud = coursePhon(root,'l');
//afficher l'abre
//print_tree(noeud,0);
printf("caracsuiv:%c\n",((char_word*)tree_get_node(noeud))->character);
List* list = list_new(NULL);
List*liste1= finalList(root,list,"lORtep",0,3);
//afficher la liste
for(int i=0 ; i < list_count(liste1) ; i++)
{
        printf("%s\n",(char*)list_get(liste1,i));
}
//nombre de mot dans la liste
printf("%i\n",list_count(liste1));


  return (EXIT_SUCCESS);
}
