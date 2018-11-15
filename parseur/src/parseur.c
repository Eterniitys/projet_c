// fonction de lecture : fopen --> déclaration : FILE* fopen (const char *filename, const char *mode)
// filename : nom du fichier a ouvrir 
// mode : type d ouverture : "r"->read (le fichier doit exister) "w"->cree un fichier vide pour ecriture (ecrase si fichier deja existant)
// "a"-> ajout de donnée a la fin d un fichier celui ci est creee si il nexiste pas 
// "r+"-> ouvre fichier en ecriture + lecture (le fichier doit exister)
// "w+"-> creer un fichier vide en lecture + ecriture
// "a+"->  ouvre fichier en lecture + modification
// DOC : http://www.tutorialspoint.com/c_standard_library/c_function_ftell.htm
// fscanf
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <word.h>
// FONCTION DE TAILLE SUR POINTEUR DE FICHIER QUI IDENTIFIE LE FLUX
long size_file(FILE * fichier){
	long sizeFichier;
	fseek (fichier , 0 , SEEK_END); // initialise le pointeur d ecriture a la position 0 en partant de la fin ( place le curseur a la fin)
	sizeFichier = ftell (fichier); // donne la position actuel du curseur / pointeur : <->pointeur a la fin --> la taille du fichier
	return sizeFichier;
}
int nbLignes(char* buffer,int sizeFichier){
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
	
Mot** tableau (){
		// fichier = POINTEUR DE FICHIER QUI IDENTIFIE LE FLUX
	FILE * fichier;
	// OUVERTURE DU FLUX 
	fichier=fopen("Lexique382.csv","r");
	long sizeFichier;
	// APPEL A LA FONCTION TAILLE
	sizeFichier=size_file(fichier);
	if(fichier == NULL){
		return NULL;
	}
	else {
		char buffer[sizeFichier]; // tableau qui contiendra tout le texte 
		fseek(fichier, 0, SEEK_SET); // placement du curseur/pointeur au debut
			// on lit le fichier Lexique avec le flux fichier, 
		//on indique le nombre de caractere avec la taille du fichier => 1 caractere = 1 octet 
		// on place tout ca dans le buffer       
		fread(buffer,sizeFichier,1,fichier); 
			// compteur de ligne du fichier
		int i=0;
			// compteur de tabulation au sein d une ligne
		int cmtpTab=0;
			// compteur de l index du mot à copier --> index des char du mot
		int cmptindex=0;
			// compteur d indice du tableau 
		int compteurTableau=0;
			// declaration du mot qui sera copié dans la structure
		char* motLex;
		motLex=malloc(sizeof(char)*30);
		// declaration du mot 
		
		char** motSyllabes;
		motSyllabes=malloc(50);
		char** motPhonetiques;
		motPhonetiques=malloc(50);
		
		char * token;
		char comp[3]="- ";
		
		Mot* monMot;
		monMot=malloc(sizeof(Mot));
			// declaration du tableau de Mot* qui contiendra toutes les structures de mot du fichier
		Mot** Tab;
		Tab=malloc(sizeof(Mot)*nbLignes(buffer,sizeFichier)+1);
			// on parcours tout le fichier
		while (i!=sizeFichier){
			// nouvelle ligne
		if (buffer[i] != '\n'){
			// nouvelle tab
			if (buffer[i]=='\t'){
				cmtpTab++;
				if (cmtpTab==1){
					// on rajoute le caractere de fin de mot 
				motLex[cmptindex]='\0';
				// reinitialisation du compteur
				cmptindex=0;
					// la valeur : mot de la structure prend une taille de la taille du mot a y mettre + 1 -> '\0'
				monMot->mot=malloc(strlen(motLex)+1);
				// on copie dans la structure->mot le mot
				strcpy(monMot->mot,motLex);
				// reinitialise le mot à copier
					// sans malloc
				motLex=malloc(sizeof(char)*30);
					// avec malloc 
				//motLex=malloc(sizeof(char)*30);
			}
			else if (cmtpTab==2){
			// on ne recupere pas la prononciation
				cmptindex=0;
				motLex=malloc(sizeof(char)*30);
			}
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
				
				monMot->syllabes=motSyllabes;
				
				
				//snprintf(motLex,sizeof(char)*30,"%s","");
				motLex=malloc(sizeof(char)*30);
				
			}
		}
		// on est sur la meme forme de mot
		else {	
			// on donne au mot a copier les cara un par un
			motLex[cmptindex]=buffer[i];
			cmptindex++;
			}
		}
		// change de mot 
		else {
			
			int j=0;
			
			token=malloc(sizeof(char*));	
			
			token=strtok(motLex,comp);
			while (token != NULL){
				motPhonetiques[j]=token;
				token=malloc(sizeof(char*));
				token=strtok(NULL,comp);
				j++;
			}
			monMot->phonetique=motPhonetiques;
		
			motLex=malloc(sizeof(char)*30);
			
			
			cmtpTab=0;
			cmptindex=0;
			
			
			
				// on stock dans un taleau de Mot* le mot
			Tab[compteurTableau]=monMot;
			compteurTableau++;
			// on malloc a nouveau le mot pour ne pas ecraser les anciennes valeurs
			monMot=malloc(sizeof(Mot));
			motSyllabes=malloc(sizeof(motSyllabes));
			motPhonetiques=malloc(sizeof(motPhonetiques));
			}
			i++;
		}
			// FERMETURE  DU FLUX
			
			fclose(fichier);
			return Tab;
		}
	}
