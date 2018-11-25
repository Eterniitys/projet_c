/**
 * \file hash.c
 * \class hash
 * \author Johan
 * \version 0.1
 * \date 25 november 2018
 *
 * Allows the hashing of string
 *
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int xor(int a, int b){
	return a^b;
}

int hash (const char * string){
	int val[] = {19,46,7,123};
	int i;
	int tmp[strlen(string)];
	for (i=0;i<strlen(string);i++){
		tmp[i] = xor(val[i%3],string[i]);
	}
	int result = 0;
	for (i=0;i<strlen(string);i++){
		result+=tmp[i];
	}
	return result%256;
	
}

