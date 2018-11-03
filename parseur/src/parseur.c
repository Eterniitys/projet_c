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
	sizeFichier = ftell (fichier); // donne la position actuel du curseur / pointeur : <->pointeur a la fin --> la taille du fichier

	return sizeFichier;
}

void afficherFichier(char * nom){
	
	
	// fichier = POINTEUR DE FICHIER QUI IDENTIFIE LE FLUX
	FILE * fichier;
	
	// OUVERTURE DU FLUX 
	fichier=fopen(nom,"r");
	
	
	long sizeFichier;


	if(fichier == NULL){
		printf("Le fichier n'existe pas\n");
	}
	else {
		printf("le fichier existe\n");
		
		// APPEL A LA FONCTION TAILLE
		sizeFichier=size_file(fichier);

		
		
		//AFFICHAGE
		printf("%ld bytes = %ld Mio\n",sizeFichier,sizeFichier/1024/1024);
		
		
  		
       char buffer[sizeFichier]; // tableau qui contiendra tout le texte 
  
       fseek(fichier, 0, SEEK_SET); // placement du curseur/pointeur au debut
       
       // on lit le fichier Lexique avec le flux fichier, 
       //on indique le nombre de caractere avec la taille du fichier => 1 caractere = 1 octet 
       // on place tout ca dans le buffer       
       fread(buffer,sizeFichier,1,fichier); 
       

        
        // ici on print le fichier dans le terminal 
        // TODO : stocker les mots et leur forme dans la structure de mot 
        // TODO : a capella	: mot akapEla : prononciation	a ca-pel-la : syllabe	a-ka-pE-la : phonetique
        // TODO : syllabe et phonetique sont a stocké dans des char ** pour recuperer les syllables : [[a][ca][pel][la]] / [[a][ka][pE][la]] 
        
        /* FORME de la structure : 
        	char * mot;
       		char * prononciation;
       		char ** syllabe;
       		char ** phonetique;
       	*/
        
        int i=0;
        // forme= premier element de la strucuture : mot 
        
        // on parcours tout le fichier
       	 while (i!=sizeFichier-1){
       	 
       	 	// change pas de mot 
       	 	if (buffer[i] != '\n'){
       	 	
       	 		// change de forme de mot
       	 		if (buffer[i]=='\t'){
       	 		
       	 			// si forme==mot -> forme = prononciation
      				// si forme==prononciation -> forme = syllabe
      				// si forme == syllabe -> forme = phonetique
      				
      				printf("%cform suivante : ",buffer[i]);
      				// valeur a stocké dans le forme adequat de la structure

     			 }
     			// on est sur la meme forme de mot
       	 		else {	
       	 			if(i==0){
		   	 			printf("Premiere forme : %c", buffer[i]);
						// valeur a stocké dans le forme adequat de la structure
		   	 		}
       	 			else {
       	 				printf("%c", buffer[i]);  
       	 				// valeur a stocké dans le forme adequat de la structure 			
       	 			}
       	 		}
       	 	}
       	 	// change de mot 
       	 	else {
       	 		printf("\nMot suivant : ");
       	 		// valeur a stocké dans le forme adequat de la structure
       	 	}

       		
      	 	i++;
       		
       	 }
       	 printf("\n");

	 	// FERMETURE  DU FLUX
		fclose(fichier);
	
	}
}



