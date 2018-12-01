#include <stdio.h>
#include <stdlib.h>
#include "rhyme.h"

#include <tree.h>
#include <word.h>
#include <parseur.h>
#include <string.h>
#include <list.h>


char **parcours(Tree*tree, char*phon,word**w)
{
  List* list = list_new(NULL);
  noeud=tree_find_child(tree,phon[i]);
  if(noeud)
  {

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
