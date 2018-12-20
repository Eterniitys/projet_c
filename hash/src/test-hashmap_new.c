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

// void _new_tab(Hashmap* map);
void noop_free(void* a) {}

int main(void) {
  Hashmap* map = hashmap_new();
  assert(sizeof(*map) == sizeof(Hashmap));

  for (int i = 0; i < 126; i++) {
    assert(map->_table_count == i + 1);
    for (int j = 0; j < 256; j++) {
      assert(sizeof(map->_tables[i][j]) == sizeof(KeyValuePair));
      assert(map->_tables[i][j]._key == NULL);
    }
    _new_tab(map);
  }
  hashmap_destroy(map, &noop_free);

  return 0;
}
