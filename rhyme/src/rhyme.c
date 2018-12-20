#include <stdio.h>
#include <stdlib.h>
#include "rhyme.h"

#include <tree.h>
#include <word.h>
//#include <parser.h>
#include <string.h>
#include <list.h>

/**
 *use in arbreEnList
 */
char tab[40];

/**
 *use in compare()
 */
char *wordCompar;

/**
 *afficher un arbre
 */
void print_tree(Tree* node, int level) {
	char_word* struc;
	if(node){
		struc = (char_word*)tree_get_node(node);
	}else{
		fprintf(stderr, "%s\n","C nule s'mér !" );
	}
	if (struc) {
		for (int i = 0; i < level; i++)
			fprintf(stderr, "|  ", NULL);
		fprintf(stderr,"'%c' %u %s\n", struc->character, struc->character, (*struc).string == NULL ? "" : "->");
	}
	for (int i = 0; i < tree_child_count(node); i++) {
		print_tree(tree_get_child(node, i), level+1);
	}
}

/**
 * \fn void reverse_string(char * word)
 *
 * \return void - reverse a string
 */
void reverse_string(char * word){
	int i=0;
	int len = strlen(word);
	char temp;
	for (i=0 ; i<len/2 ; i++) {
		temp = word[len-i-1];
		word[len-i-1] = word[i];
		word[i] = temp;
	}
}

/**
 *conpare 2 list
 */
int compare (void* word1, void*word2)
{
	char* un = ((Word*)word1)->_pronunc;
	char* two = ((Word*)word2)->_pronunc;
	int score=0;
	int i=0;
	//wordCompar
	while (un[i]==wordCompar[i] && wordCompar[i]!='\0' && un[i]!='\0') {
		score--;
		i++;
	}
	i=0;
	while (two[i]==wordCompar[i] && wordCompar[i]!='\0' && two[i]!='\0') {
		score++	;
		i++;
	}
	return score == 0 ? strcmp(un, two) : score ;
}

/**
 *limit to 20 values
 */
List* cutList(List* list, int count)
{
	List * aList=list_new(NULL);
	int i=0;
	while(i<count && list_count(list)>i)
	{
		list_add(aList,((Word*)list_get(list,i))->_word);
		i++;
	}
	return aList;
}

/**
 *put tree in list
 */
 /*
List* arbreEnList(Tree* tree,List* list, int stage)
{
	//on veut parcourir tout l'arbre et recuperer chaque mots

	for(int i =0; i< tree_child_count(tree); i++ )
	{
		Tree* enfant=tree_get_child(tree,i);
		//on recupère le pointeur
		char_word* mot=(char_word*)tree_get_node(enfant);
		tab[stage]=mot->character;
		tab[stage+1]='\0';
		//on test le pointeur si il est pas NULL on ajoute le mot a la liste
		if(mot && mot->string)
		{
			Word* bidon=malloc(sizeof(Word));
			bidon->_word= mot->string;
			bidon->_pronunc = malloc(sizeof(char)*strlen(tab)+1);
			strcpy(bidon->_pronunc , tab);
			list_add(list,bidon);
		}
		arbreEnList(enfant,list,stage+1);
	}
	return list;
}*/
List* treeToList(Tree* tree,List* list, int stage)
{
	//browse all of the tree to get every word

	for(int i =0; i< tree_child_count(tree); i++ )
	{
		Tree* child=tree_get_child(tree,i);
		//get pointer
		char_word* aWord=(char_word*)tree_get_node(child);
		tab[stage]=aWord->character;
		tab[stage+1]='\0';
		//if pointer not NULL add word in the list
		if(aWord && aWord->string)
		{
			Word* word1=malloc(sizeof(Word));
			word1->_word= aWord->string;
			word1->_pronunc = malloc(sizeof(char)*strlen(tab)+1);
			strcpy(word1->_pronunc , tab);
			list_add(list,word1);
		}
		treeToList(child,list,stage+1);
	}
	return list;
}

/**
 *afficher la liste final en fonction d'un seuil de caractère correspondant donné
 */
void finalList(Tree* tree, List* list, char* word, int cpt, int threshold)
{
	if(cpt==0) {
		wordCompar=word;
	}

	//condition de fin du mot
	if(word[0]=='\0') {
		return;
	}

	//trouver le caractère
	char_word structure={0};
	(&structure)->character=word[0];
	Tree* noeud= tree_find_child(tree, &structure);

	tab[cpt]=word[0];
	tab[cpt+1]='\0';
	//si on trouve le caractère
	if(noeud!=NULL) {
		cpt++;
		//si le nombre de  caractère phonetique concordes
		if(cpt>=threshold) {
			//on recupère tous les childs et on les range dans la list
			treeToList(noeud,list,cpt);
		} else {
			//on cherhce le prochain caractère de word
			finalList(noeud,list,word+1,cpt,threshold);
		}
	}
	list_lock(list);
	return;
}

List* match_word(Tree* tree, int count, char* word) {
	List* output = list_new(&compare);
	finalList(tree, output, word, 0, 2);
	return cutList(output, count);
}
