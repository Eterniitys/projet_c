#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <word.h>


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

					// not use
					else if (cmtpTab==2){
						cmptindex=0;
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






