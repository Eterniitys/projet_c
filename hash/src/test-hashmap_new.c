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
#include <assert.h>

#include "hash.h"

 
int main(void){
	
	Hashmap* map = hashmap_new();
	
	assert(sizeof(map)==sizeof(Hashmap));
	assert(sizeof(map->_table_count) == sizeof(char));
	assert(sizeof(map->_tables[0]) == sizeof(KeyValuePair*));
	
	hashmap_destroy(map);
		
	return 0;
}
