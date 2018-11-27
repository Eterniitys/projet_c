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
	char * strings[10] = {"artyez","azerty","ytreza","azerty","treza","trezya","rtez","ytreaz","azer","zerty"};
	
	Hashmap* map = hashmap_new();
	
	char * testVal = "test";
	
	for (int i=0;i<10;i++){
		hashmap_set(map,strings[i],testVal);
	}
	
	hashmap_destroy(map);
	
	return 0;
}
