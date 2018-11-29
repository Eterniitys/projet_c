/**
 * \file test-hash.c
 * \class hash
 * \author Johan
 * \version 0.1
 * \date 25 november 2018
 *
 * Test the hashing of string
 *
 */
#include <stdio.h>
#include <string.h>

#include "hash.h"

 
int main(void){
	char * strings[10] = {"artyez","azerty","ytreza","azert","treza","trezya","rtez","ytreaz","azer","zerty"};
	
	for (int i=0;i<10;i++){
		printf("%s:hash:%d\n",strings[i],hash(strings[i]));
	}
	return 0;
}