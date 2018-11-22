#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <word.h>
#include <tree.h>

// TODO 4 buffer

/**
 * 
 */
int compare_char (void * node1,void * node2){
	char_mot *cm1 = ((Tree*)node1)->struc;
	char_mot *cm2 = ((Tree*)node2)->struc;
	return cm1->caractere-cm2->caractere;
}

/**
 * function fill_tree
 */
void fill_tree (char* mot,Mot * monMot,Tree * node){

	char_mot *structure=malloc(sizeof(char_mot));
	structure->caractere=mot[0];
	structure->monMot=NULL;
	
	
	Tree tmpTree;
	(&tmpTree)->struc=structure;
	
	Tree * nodeBis=tree_find_child(node,&tmpTree); // null si y a pas 
	
	if (nodeBis==NULL){
		nodeBis= tree_new_node(structure,compare_char);
		tree_add_node(node, nodeBis);
	}
	
	
	if (mot[1]=='\0'){
		structure->monMot=monMot;
	}
	else {		
		fill_tree(mot+1,monMot,nodeBis);
	}
}


/**
 * function reverse
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
 * function who return the size of ths stream file (Bytes)
 */ 
long size_file(FILE * fichier){
	long sizeFichier;
	fseek (fichier , 0 , SEEK_END); 
	sizeFichier = ftell (fichier);
	return sizeFichier;
}

// function who return the number of line of a buffer
int numbers_lines(char* buffer,int sizeFichier){ 
	int i = 0;
	int cpt = 0;
	while (i != sizeFichier-1){
		if ( buffer[i] == '\n') {
			cpt = cpt+1;
		}		
		i++;
	}
	return cpt;
}

/**
 * Function who read and sort in a structure a file
 */
Mot** parseur_read(const char * PATH){

	FILE * fichier;
	fichier=fopen(PATH,"r");

	long sizeFichier;
	sizeFichier=size_file(fichier);


	if(fichier == NULL){
		return NULL;
	}
	else {

		/* READ FILE */ 
		char buffer[sizeFichier];
		fseek(fichier, 0, SEEK_SET);
		fread(buffer,sizeFichier,1,fichier); 

		/* COUNTER */

		// counter of ligne of the file 
		int i=0;
		// counter of tab in a line
		int cmtpTab=0;
		// counter of index for a word in locurence motLex
		int cmptindex=0;
		// counter of index for tabs of results 
		int compteurTableau=0;

		/* DECLARATION */ 
		// word who will be copy in the structure word->mot
		char* motLex;
		motLex=malloc(sizeof(char)*30);

		// char ** who will be copy in the structure word->syllabes
		char** motSyllabes;
		motSyllabes=malloc(50);

		// char ** who will be copy in the structure word->phonetique
		char** motPhonetiques;
		motPhonetiques=malloc(50);

		// from strtok -> explode a word whith delim 
		char * token;
		// delim
		char comp[3]="- ";

		

		// word structure 
		Mot* monMot;
		monMot=malloc(sizeof(Mot));


		// Big tab who will contain all the word structure of the file
		Mot** Tab;
		Tab=malloc(sizeof(Mot)*numbers_lines(buffer,sizeFichier)+1);

		// tree 
		Tree *root=tree_new_node(NULL,compare_char);
		

		/* CROSS THE FILE */
		while (i!=sizeFichier){

			// new lign <-> new word 
			if (buffer[i] != '\n'){

				// new tabulation <-> new type of word 
				if (buffer[i]=='\t'){

					cmtpTab++;

					// mot 
					if (cmtpTab==1){

						motLex[cmptindex]='\0';
						cmptindex=0;

						monMot->mot=motLex; // TODO : fonction qui stock les mots dans la structure
						motLex=malloc(sizeof(char)*30);
					}

					// phonetique
					else if (cmtpTab==2){
						
						motLex[cmptindex]='\0';
						cmptindex=0;

						reverse_string(motLex);
						fill_tree(motLex,monMot,root);
						
						motLex=malloc(sizeof(char)*30);
					}

					// syllabes
					else if (cmtpTab==3){

						motLex[cmptindex]='\0';
						cmptindex=0;

						int j=0;
						token=malloc(sizeof(char*));

						token=strtok(motLex,comp);
						while (token != NULL){
							motSyllabes[j]=token;
							token=malloc(sizeof(char*));
							token=strtok(NULL,comp);
							j++;
						}

						monMot->syllabes=motSyllabes; // TODO : fonction qui stock les mots dans la structure
						motLex=malloc(sizeof(char)*30);

					}
				}
				else {	
					// word who cross the file
					motLex[cmptindex]=buffer[i];
					cmptindex++;
				}
			}
			// other word 
			else {

				// phonetique
				int j=0;
				token=malloc(sizeof(char*));	

				token=strtok(motLex,comp);
				while (token != NULL){
					motPhonetiques[j]=token;
					token=malloc(sizeof(char*));
					token=strtok(NULL,comp);
					j++;
				}

				monMot->phonetique=motPhonetiques; // TODO : fonction qui stock les mots dans la structure
				motLex=malloc(sizeof(char)*30);


				cmtpTab=0;
				cmptindex=0;


				// stock the structure monMot in the big tab
				Tab[compteurTableau]=monMot;
				compteurTableau++;

				// reset
				monMot=malloc(sizeof(Mot));
				motSyllabes=malloc(sizeof(motSyllabes));
				motPhonetiques=malloc(sizeof(motPhonetiques));
			}
			i++;
		}

		/* CLOSE THE STREAM */

		fclose(fichier);
		return Tab;
	}
}








