/**
 * \file tree.c
 * \class tree
 * \author Johan
 * \version 0.1
 * \date 15 november 2018
 *
 * Allows the creation of a node with the structure of 'struc'
 *
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "tree.h"
#include "tree.inc"

void *tree_get_node(Tree *root) { return root->_struc; }

Tree *tree_new(void *struc, _compFunc funct) {
  Tree *node = malloc(sizeof(Tree));
  node->_struc = struc;
  node->_funct = funct;
  node->_children = list_new(funct);
  return node;
}

void _noop_void_voidp(void *p) {}

void tree_destroy(Tree *tree, _freeFunc node_free) {
  for (int i = 0; i < tree_child_count(tree); i++) {
    tree_destroy(list_get(tree->_children, i), node_free);
  }
  list_destroy(tree->_children, &_noop_void_voidp);
  if (node_free) {
    node_free(tree->_struc);
  }
  free(tree);
}

Tree *tree_add_child(Tree *root, Tree *node) {
  node->_children->_compare = root->_funct;
  node->_funct = root->_funct;
  list_add(root->_children, node);
  return root;
}

Tree *tree_remove_child(Tree *root, int index) {
  list_remove(root->_children, index);
  return root;
}

Tree *tree_get_child(Tree *root, int nb) {
  return list_get(root->_children, nb);
}

int tree_child_count(Tree *tree) { return list_count(tree->_children); }

void tree_lock(Tree *tree) {
  for (int i = 0; i < tree_child_count(tree); i++) {
    tree_lock(list_get(tree->_children, i));
  }
  list_lock(tree->_children);
}

void tree_unlock(Tree *tree) {
  for (int i = 0; i < tree_child_count(tree); i++) {
    tree_unlock(list_get(tree->_children, i));
  }
  list_unlock(tree->_children);
}

Tree *tree_find_child(Tree *tree, void *child) {
  Tree temp = {0};
  (&temp)->_struc = child;
  if (!tree->_children) return NULL;
  return (Tree *)list_find(tree->_children, &temp);
}

int tree_get_depth(Tree *tree) {
  int max = 0;
  if (tree_child_count(tree) > 1) {
    max = tree_get_depth(tree_get_child(tree, 0));
    for (int i = 1; i < tree_child_count(tree); i++) {
      int depth = tree_get_depth(tree_get_child(tree, i));
      max = max >= depth ? max : depth;
    }
  } else if (tree_child_count(tree) == 1) {
    max = tree_get_depth(tree_get_child(tree, 0));
  }
  max++;
  return max;
}
