#include <stdio.h>
#include<stdlib.h>
#include <assert.h>
#include<string.h>

#include "rhyme.h"
#include <tree.h>
#include<parser.h>
#include <word.h>

int main(void) {

Tree *root= NULL;
Tree *root2= NULL;
Hashmap* hash= NULL;
parser_read("../../Lexique382.csv",&root,&root2,&hash);


Tree* noeud = coursePhon(root,'l');
print_tree(noeud,0);
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
printf("caracsuiv:%c\n",((char_word*)tree_get_node(noeud))->character);
  return (EXIT_SUCCESS);
}
