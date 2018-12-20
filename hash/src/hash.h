/**
 * \file hash.h
 * \class hash
 * \author Johan
 * \version 0.1
 * \date 25 november 2018
 *
 * Allows the hashing of string
 *
 */
#ifndef _HASH_H_
#define _HASH_H_

typedef struct _KeyValuePair KeyValuePair;

struct _KeyValuePair {
  char* _key;
  void* _value;
};

typedef struct _Hashmap Hashmap;

struct _Hashmap {
  KeyValuePair** _tables;
  char _table_count;
};

/**
 *\fn unsigned char hash (const char * string)
 *
 *\return a hash of string between 0 and 255
 */
extern unsigned char hash(const char* string);

/**
 *\fn Hashmap* hashmap_new(void)
 *\ return newhash - return an initialized hashmap
 */
extern Hashmap* hashmap_new(void);

/**
 *\fn void hashmap_set(Hashmap* map, char* key, void* value)
 *\ add key and values into an hashmap accroding to the hashKey
 */
extern void hashmap_set(Hashmap* map, char* key, void* value);

/**
 *\fn void* hashmap_get(Hashmap* map, char* key)
 *\ return map->_tables[nbTable][hash(key)]._value || return
 *map->_tables[nbTable][(hash(key)+1)%256]._value - return values of the key
 */
extern void* hashmap_get(Hashmap* map, char* key);

/**
 *\fn void hashmap_destroy(Hashmap* map)
 *\ free the hashmap
 */
extern void hashmap_destroy(Hashmap* map, void (*freeFunc)(void*));

#endif /* _HASH_H_ */
