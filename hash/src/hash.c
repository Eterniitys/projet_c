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

void rpl(Hashmap* map){
	int som=0;
	for (int i = 0; i<map->_table_count;i++){
		int inc=0;
		for (int j = 0; j<256;j++){
			if (map->_tables[i][j]._key != NULL){
				inc++;
			}
		}
		printf("\nTable %d remplie a %4.1f%\n",i,((float)inc/256)*100);
		som+=inc;
	}
	printf("<==> Tables remplie à %4.1f% <==>\n\n",((float)som/(256*map->_table_count))*100);
}

unsigned char hash (const char * string){
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

void _new_tab(Hashmap* map){
	map->_table_count++;
	char nbTable = map->_table_count;
	map->_tables = realloc(map->_tables,sizeof(KeyValuePair*)*nbTable);
	map->_tables[nbTable-1] = malloc(sizeof(KeyValuePair)*256);
	for (int i = 0; i<256;i++){
		map->_tables[nbTable-1][i]._key=NULL;
	}
}

Hashmap* hashmap_new(void){
	Hashmap* newhash = malloc(sizeof(Hashmap));
	newhash->_table_count=0;
	_new_tab(newhash);
	return newhash;
}



void hashmap_set(Hashmap* map, char* key, void* value){
	int nbTable = 0;
	int place = false;
	//printf("-Hash::%d\n",hash(key));
	while (nbTable<map->_table_count && !place){
		
		if (map->_tables[nbTable][hash(key)]._key == NULL){
			//printf("-La Place est Libre %s\n",map->_tables[nbTable][hash(key)]._key);
			map->_tables[nbTable][hash(key)]._key = key;
			map->_tables[nbTable][hash(key)]._value = value;
			place = true;
		}else if (strcmp(map->_tables[nbTable][hash(key)]._key,key)==0){
			//printf("-Contient déjà %s\n",map->_tables[nbTable][hash(key)]._key);
			place = true;
		}else{
			//printf("-La Place est prise par %s\n",map->_tables[nbTable][hash(key)]._key);
			nbTable++;
		}
	}
	if(nbTable>=map->_table_count){
		rpl(map);//TODO
		printf("\n Nouvelle Table !! - %d -\n\n",nbTable);
		_new_tab(map);
		map->_tables[nbTable][hash(key)]._key = key;
		map->_tables[nbTable][hash(key)]._value = value;
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
