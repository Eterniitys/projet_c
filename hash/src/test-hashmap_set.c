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
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "hash.h"
#include "hash.inc"

void noop_free(void* a) {}

int main(void) {
  char* strings[] = {"artyez", "azerty", "ytreza", "azerty", "treza",
                     "trezya", "rtez",   "ytreaz", "azer",   "zerty"};

  Hashmap* map = hashmap_new();

  char* testVal = "test";

  for (int i = 0; i < 10; i++) {
    hashmap_set(map, strings[i], testVal);
  }

  for (int i = 0; i < 10; i++) {
    if (i != 7) {
      assert(map->_tables[0][hash(strings[i])]._key == strings[i]);
      assert(map->_tables[0][hash(strings[i])]._value == "test");
    } else {
      assert(map->_tables[0][hash(strings[i]) + 1]._key == strings[i]);
      assert(map->_tables[0][hash(strings[i]) + 1]._value == "test");
    }
  }

  hashmap_destroy(map, &noop_free);

  return 0;
}
