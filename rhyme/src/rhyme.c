#include <stdio.h>
#include <stdlib.h>
#include "rhyme.h"

#include <tree.h>
#include <word.h>
//#include <parser.h>
#include <string.h>
#include <list.h>


//afficher un arbre
void print_tree(Tree* node, int level) {
	char_word* struc = (char_word*)tree_get_node(node);
	if (struc) {
		for (int i = 0; i < level; i++)
			fprintf(stderr, "|  ", NULL);
		fprintf(stderr,"'%c' %u %s\n", struc->character, struc->character, (*struc).string == NULL ? "" : "->");
	}
	for (int i = 0; i < tree_child_count(node); i++) {
		print_tree(tree_get_child(node, i), level+1);
	}
}


//On veut faire une fonction qui, partant du noeud vide de base, parcours chacuns de ses
//enfants jusqu'à trouver celui qui contient le dernier caractère phonétique du mot, et enfin
//nous retourner un nouvel arbre ayant pour noeud de base ce dernier caractère phonétique.
Tree*coursePhon(Tree*tree, char phon)
{
          //structure pour utiliser "phon" et le "tree_find_child()"
          char_word structure={0};
          (&structure)->character=phon;

        //on recupere le noeud avec la phonétique correspondante.
        Tree* noeud= tree_find_child(tree, &structure);
        return noeud;
}

//ranger un arbre dans une liste
List* arbreEnList(Tree* tree,List* list)
{
	//on veut parcourir tout l'arbre et recuperer chaque mots
	for (int i = 0; i < tree_child_count(tree); i++)
	{
		Tree* enfant=tree_get_child(tree,i);
		//on recupère le pointeur
		char_word* mot=(char_word*)tree_get_node(enfant);
		//on test le pointeur si il est pas NULL on ajoute le mot a la liste
		if(mot && mot->string)
		{
			list_add(list,mot->string);
		}
		arbreEnList(enfant,list);
	}
        return list;
}

//afficher la liste final en fonction d'un seuil de caractère correspondant donné
List* finalList(Tree* tree,List* list,char* word,int cpt,int threshold)
{
        //condition de fin du mot
        if(word[0]=='\0')
        {
                return list;
        }
        //trouver le caractère
        char_word structure={0};
        (&structure)->character=word[0];
        Tree* noeud= tree_find_child(tree, &structure);
        //si on trouve le caractère
        if(noeud!=NULL)
        {
                cpt++;
		//si trois caractère phonetique concordes
                if(cpt>=threshold)
                {
			//on recupère tous les enfants et on les range dans la list
			list=arbreEnList(noeud,list);
                }
                else
                {
			//on cherhce le prochain caractère de word
                        finalList(noeud,list,word+1,cpt,threshold);
                }
        }
        return list;
}

/*
//######################################
//savoir si le cactère phonetique est une voyelle
bool isVowel(char*phon)
{
  bool res=false;
  //liste de tout les carctère de voyelle
  List* list = list_new('i','y','e','E','5','2','9','1','a','Â°','u','o','O','Â§','@');

  for(int i =0;i<list_count(list);i++)
  {
    //test de comparaison des caractères
    if(phon==list_get(list,i))
    {
      res=true;
    }
  }
  return res;
}
*/
