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


char* para=malloc(sizeof(char)*7);
strcpy(para,"amÂ§");
reverse_string(para);
char* para2="§Â";
//printf("%c\n",para2[4] );
//tree_unlock(root);
//print_tree(tree_find_child(tree_find_child(tree_find_child(root,&para2[1]),&para2[0]),&para2[3]),0);

List* list = list_new(&compare);
List*liste1= finalList(root,list,para,0,2);
printf("%i\n",list_count(liste1));
//liste coupé
liste1=cutList(liste1);
//afficher la liste
for(int i=0 ; i < list_count(liste1) ; i++)
{
        printf("%d :\t%s\t\t",i+1,((Word*)list_get(liste1,i))->_pronunc);
        printf("%s\n",((Word*)list_get(liste1,i))->_word);
}



  return (EXIT_SUCCESS);
}
