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
Hashmap* hash;
parser_read("../src/rhym.txt",&root,&root2,hash);


Tree* noeud = coursePhon(root,'l');
printf("caractere:%c\n",((char_word*)tree_get_node(noeud))->character);
//noeud = tree_get_child(noeud,0);//coursePhon(noeud,'O');
//printf("caracsuiv:%c\n",((char_word*)tree_get_node(noeud))->character);
  return (EXIT_SUCCESS);
}
