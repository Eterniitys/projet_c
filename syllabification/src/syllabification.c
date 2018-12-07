#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <word.h>
#include <tree.h>

#include "syllabification.h"

void print_tree_j(Tree* node, int level) {
	StringBool* struc = (StringBool*)tree_get_node(node);
	if (struc) {
		for (int i = 0; i < level; i++)
			fprintf(stderr, "|      ");
		fprintf(stderr,"'%s' \\%d/ %s\n", struc->string,struc->score, struc->eow ? "+" : "");
	}
	for (int i = 0; i < tree_child_count(node); i++) {
		print_tree_j(tree_get_child(node, i), level+1);
	}
}

bool valid_inside(Tree* root){
	bool valid = ((StringBool*)tree_get_node(root))->eow;
	if (tree_child_count(root) == 0 && valid){
		return true;
	}
	for (int i = 0 ; i< tree_child_count(root);i++){
		valid = valid_inside(tree_get_child(root,i));
	}
	return valid;
}

Tree* clean_invalide(Tree* root){
	int i = 0 ;
	while( i< tree_child_count(root)){
		if(valid_inside(tree_get_child(root,i))){
			clean_invalide(tree_get_child(root,i));
			i++;
		}else{
			tree_remove_child(root,i);
		}
	}
	return root;
}

int score_tree(Tree* root){
	while(tree_child_count(root) > 1){
		Tree* child1 = (Tree*)tree_get_child(root,0);
		Tree* child2 = (Tree*)tree_get_child(root,1);
		if(score_tree(child1) > score_tree(child2)){
			tree_remove_child(root,1);
		}else{
			tree_remove_child(root,0);
		}
	}

	int score = 0;
	if (tree_get_node(root) != NULL){
		score = ((StringBool*)tree_get_node(root))->score;
	}
	if (tree_child_count(root) >= 1){
		Tree* node= (Tree*)tree_get_child(root,0);
		score += score_tree(tree_get_child(root,0));
	}
	return score;
}

char** get_better_match(Tree* root){
	int profondeur = 0;
	clean_invalide(root);
	score_tree(root);
	char** output = malloc(sizeof(char*));
	printf("size = %d\n", profondeur);
	
	print_tree_j(root,0);
	return output;
}

char** syllabicate(Tree* syll_tree,char* word) {
	char** output = malloc(sizeof(char*)*10);
	int index = 0;
	Tree* root = tree_new(NULL, NULL);
	gen_syllables(root, syll_tree, word);
	//TODO parcours de l'arbre pour générer la liste de syllabes avec le plus de poids
	output = get_better_match(root);
	return output;
}



void gen_syllables(Tree* root, Tree* syll_tree, char* word) {
	//fprintf(stderr, "%s\n", word);
	recursive(root, syll_tree, word, 0);
	int i;
	for (i = 0; i < tree_child_count(root); i++) {
		Tree* child = tree_get_child(root, i);
		StringBool* sb = (StringBool*)tree_get_node(child);
		//fprintf(stderr, "Syllabe %s (mot %s)\n", sb->string, word);
		if (!sb->eow) {
			//fprintf(stderr, "\tRécursion sur %s (%s)\n", sb->string, word + strlen(sb->string));
			gen_syllables(child, syll_tree, word + strlen(sb->string));
		}
	}
}

void recursive(Tree* node, Tree* syll_tree, char* word, int index) {
	//fprintf(stderr, "\t%d-%c\n",index,word[index]);
	if (word[index]=='\0')
		return;

	char_word newWord;
	newWord.character = word[index];
	Tree* newTree = tree_new(&newWord, NULL);
	Tree* child = tree_find_child(syll_tree, newTree);

	if (!child) {
		//fprintf(stderr, "pas d'enfants pour %s\n", word+index);
		return;
	}

	if(((char_word*)tree_get_node(child))->myWord){
		StringBool* sb = malloc(sizeof(StringBool));

		sb->string = malloc(sizeof(char)*index+2);
		strncpy(sb->string, word, index+1);
		sb->string[index+1] = '\0';
		
		sb->score = ((char_word*)tree_get_node(child))->counter_syll;

		sb->eow = word[index+1] == '\0';
		//fprintf(stderr, "%s : %s %s\n", word, sb->string, sb->eow ? "fin":"-");
		//fprintf(stderr, "\t^^ fin de syllabe\n");
		Tree * newNode = tree_new(sb,NULL);
		tree_add_child(node, newNode);
	}
	recursive(node, child, word, index + 1);
}

