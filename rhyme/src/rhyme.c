#include <stdio.h>
#include <stdlib.h>
#include "rhyme.h"

#include <tree.h>
#include <word.h>
#include <parser.h>
#include <string.h>
#include <list.h>



//On veut faire une fonction qui, partant du noeud vide de base, parcours chacuns de ses
//enfants jusqu'à trouver celui qui contient le dernier caractère phonétique du mot, et enfin
//nous retourner un nouvel arbre ayant pour noeud de base ce dernier caractère phonétique.
Tree*coursePhon(Tree*tree, char phon)
{
          //structure pour utiliser "phon" et le "tree_find_child()"
          char_word* structure=malloc(sizeof(char_word));
          structure->character=phon;
          structure->myWord=NULL;
          Tree * phonetic = tree_new(structure,NULL);

        //on recupere le noeud avec la phonétique correspondante.
        Tree* noeud= (Tree*)tree_find_child(tree,phonetic);

        return noeud;
}





/*char **parcours(Tree*tree, char phon)
{
  //List* list = list_new(NULL);

  //structure pour utiliser "phon" et le "tree_find_child()"
  char_word* structure=malloc(sizeof(char_word));
  structure->character=phon;
  structure->myWord=NULL;
  Tree phonetic;
(&phonetic)->_struc=structure;

//recuperer le noeud avec toutes les correspondances
  noeud=(Tree*)tree_find_child(tree,phonetic);
  //si le caractère du noeud est egale au denier caractère de notre mot
  if(noeud==phon)
  {
    //creation d'un arbre avec pour noeud phon et pour enfant les mots recupere de noeud
        Tree arbre=tree_new(noeud,//enfants);

  }
    else
  {
    for (int i = 0; i < tree_count_children(noeud); i++)
    {
      Tree* enfant=tree_get_child(noeud,i);
      char mot=tree_get_node(enfant);
      if(mot!=NULL)
      {
        list_add(list,mot);
      }
      //parcours(enfant,,w)
    }
  }

    return NULL;
}

//savoir si le cactère phonetique est une voyelle
bool isVowel(char**phon)
{
  bool res=false;
  //liste de tout les carctère de voyelle
  List* list = list_new('i','y','e','E','5','2','9','1','a','Â°','u','o','O','Â§','@');

  for(int i =0;i<list.size();i++)
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
