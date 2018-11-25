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


int pow(int a, int b){
	int sum=1;
	for (int i =0;i<b;i++){
		//printf("%d:%d*%d = mod:%d\n",i,sum,a,(a*sum%256+1));
		sum*=a;
		sum%=256;
	}
	return sum;
}

int hash (const char * string){
	int i;
	int tmp[strlen(string)];
	for (i=0;i<strlen(string);i++){
		tmp[i] = abs(pow(rand(),string[i])%256);
	}
	int result = 0;
	for (i=0;i<strlen(string);i++){
		result+=tmp[i];
	}
	return result%256;
	
}

