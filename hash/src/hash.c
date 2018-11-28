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
#include <stdbool.h>
#include "hash.h"


int xor(int a, int b){
	return a^b;
}

int hash (const char * string){
	int val[] = {19,46,7,123};
	int i;
	for (i=0;i<strlen(string);i++){
		val[i%4] = xor(val[i%4],string[(i+1)%4]);
	}
	int result = 0;
	for (i=0;i<strlen(string);i++){
		result+=val[i];
	}
	return result%256;
	
}

Hashmap* hashmap_new(void){
	Hashmap* newhash = malloc(sizeof(Hashmap));
	newhash->_table_count=1;	
	//First hashMap
	KeyValuePair **tab = malloc(sizeof(KeyValuePair*)*10);
	tab[0] = malloc(sizeof(KeyValuePair)*256);
	for (int i = 0; i<256;i++){
		tab[0][i]._key=NULL;
	}
	newhash->_tables = tab;
	return newhash;
}

void hashmap_set(Hashmap* map, char* key, void* value){
	int nbTable = 0;
	int place = false;
	while (nbTable<map->_table_count && !place){
		if (map->_tables[nbTable][hash(key)]._key == NULL){
			map->_tables[nbTable][hash(key)]._key = key;
			map->_tables[nbTable][hash(key)]._value = value;
			place = true;
		}else if (strcmp(map->_tables[nbTable][hash(key)]._key,key)){
			place = true;
		}else{
			nbTable++;
		}
	}
	if(nbTable>=map->_table_count){
		map->_tables[nbTable] = malloc(sizeof(KeyValuePair)*256);
		map->_tables[nbTable][hash(key)]._key = key;
		map->_tables[nbTable][hash(key)]._value = value;
		map->_table_count++;
	}
}

void* hashmap_get(Hashmap* map, char* key){
	int nbTable = 0;
	while (nbTable<map->_table_count){
		if (strcmp(map->_tables[nbTable][hash(key)]._key,key)==0){
			return map->_tables[nbTable][hash(key)]._value;
		}else{
			nbTable++;
		}
	}
}

void hashmap_destroy(Hashmap* map){
	for (int i=0;i<map->_table_count;i++){
		free(map->_tables[i]);
	}
	free(map->_tables);
	free(map);	 
}
