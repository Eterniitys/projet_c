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

// FONCTION DE TAILLE SUR POINTEUR DE FICHIER QUI IDENTIFIE LE FLUX
long size_file(FILE * fichier){
	long sizeFichier;
	fseek (fichier , 0 , SEEK_END); // initialise le pointeur d ecriture a la position 0 en partant de la fin ( place le curseur a la fin)
	sizeFichier = ftell (fichier); // nombre d octet du fichier

	return sizeFichier;
}

int main (void){

	// fichier = POINTEUR DE FICHIER QUI IDENTIFIE LE FLUX
	FILE * fichier;
	
	// OUVERTURE DU FLUX 
	fichier=fopen("Lexique382.csv","r");
	
	long sizeFichier;


	if(fichier == NULL){
		printf("Le fichier n'existe pas\n");
	}
	else {
		printf("le fichier existe\n");
		
		// APPEL A LA FONCTION TAILLE
		sizeFichier=size_file(fichier);

		// FERMETURE  DU FLUX
		fclose(fichier);
		
		//AFFICHAGE
		printf("%ld bytes = %ld Mio\n",sizeFichier,sizeFichier/1024/1024);
	}


	
	return(EXIT_SUCCESS);
}


