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
#include "hash.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.inc"

int xora(int a, int b) { return a ^ b; }

unsigned char hash(const char* string) {
  int val[] = {19, 46, 7, 123};
  int i;
  for (i = 0; i < strlen(string); i++) {
    val[i % 4] = xora(val[i % 4], string[(i + 1) % 4]);
  }
  int result = 0;
  for (i = 0; i < 4; i++) {
    result += val[i];
  }
  return result % 256;
}

void _new_tab(Hashmap* map) {
  map->_table_count++;
  char nbTable = map->_table_count;
  map->_tables = realloc(map->_tables, sizeof(KeyValuePair*) * nbTable);
  map->_tables[nbTable - 1] = malloc(sizeof(KeyValuePair) * 256);
  memset(map->_tables[nbTable - 1], 0, sizeof(KeyValuePair));
  for (int i = 0; i < 256; i++) {
    map->_tables[nbTable - 1][i]._key = NULL;
    map->_tables[nbTable - 1][i]._value = NULL;
  }
}

Hashmap* hashmap_new(void) {
  Hashmap* newhash = malloc(sizeof(Hashmap));
  newhash->_table_count = 0;
  newhash->_tables = NULL;
  _new_tab(newhash);
  return newhash;
}

void hashmap_set(Hashmap* map, char* key, void* value) {
  int nbTable = 0;
  int place = false;
  unsigned char key_hash = hash(key);
  while (nbTable < map->_table_count && !place) {
    if (map->_tables[nbTable][key_hash]._key == NULL) {
      map->_tables[nbTable][key_hash]._key = key;
      map->_tables[nbTable][key_hash]._value = value;
      place = true;
    } else if (strcmp(map->_tables[nbTable][key_hash]._key, key) == 0) {
      place = true;
    } else if (map->_tables[nbTable][(key_hash + 1) % 256]._key == NULL) {
      map->_tables[nbTable][(key_hash + 1) % 256]._key = key;
      map->_tables[nbTable][(key_hash + 1) % 256]._value = value;
      place = true;
    } else if (strcmp(map->_tables[nbTable][(key_hash + 1) % 256]._key, key) ==
               0) {
      place = true;
    } else {
      nbTable++;
    }
  }
  if (nbTable >= map->_table_count) {
    _new_tab(map);
    map->_tables[nbTable][key_hash]._key = key;
    map->_tables[nbTable][key_hash]._value = value;
  }
}

void* hashmap_get(Hashmap* map, char* key) {
  int nbTable = 0;
  if (map && key) {
    while (nbTable < map->_table_count) {
      if (map->_tables[nbTable][hash(key)]._key != NULL &&
          strcmp(map->_tables[nbTable][hash(key)]._key, key) == 0) {
        return map->_tables[nbTable][hash(key)]._value;
      } else if (map->_tables[nbTable][(hash(key) + 1) % 256]._key != NULL &&
                 strcmp(map->_tables[nbTable][(hash(key) + 1) % 256]._key,
                        key) == 0) {
        return map->_tables[nbTable][(hash(key) + 1) % 256]._value;
      } else {
        nbTable++;
      }
    }
  }
  return NULL;
}

void hashmap_destroy(Hashmap* map, void (*freeFunc)(void*)) {
  for (int i = 0; i < map->_table_count; i++) {
    for (int j = 0; j < 255; j++) {
      if (map->_tables[i][j]._value) freeFunc(map->_tables[i][j]._value);
    }
    free(map->_tables[i]);
  }
  free(map->_tables);
  free(map);
}
