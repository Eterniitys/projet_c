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
//parser_read("../src/rhym.txt",&root,&root2,&hash);


Tree* noeud = coursePhon(root,'l');
//afficher l'abre
//print_tree(noeud,0);
printf("caracsuiv:%c\n",((char_word*)tree_get_node(noeud))->character);
List* list = list_new(NULL);
List*liste1= finalList(root,list,"lORtep",0);

for(int i=0 ; i < list_count(liste1) ; i++)
{
        printf("%s\n",(char*)list_get(liste1,i));
}
printf("%i\n",list_count(liste1));

//on parcours le nouvelle arbre  noeud

/*void* test0=tree_get_node(noeud);
char_word* test=(char_word*)test0;
if(test0==NULL)
{
        printf("ya rien !\n" );
}
else{
                printf("caractere:%c\n",test->character);
}*/

//noeud = tree_get_child(noeud,0);//coursePhon(noeud,'O');

  return (EXIT_SUCCESS);
}
