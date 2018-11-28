/**
 * \file hash.h
 * \class hash
 * \author Johan
 * \version 0.1
 * \date 25 november 2018
 *
 */
#ifndef _HASH_
#define _HASH_

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

extern Hashmap* hashmap_new(void);
extern void* hashmap_get(Hashmap* map, char* key);
extern void hashmap_set(Hashmap* map, char* key, void* value);
extern void hashmap_destroy(Hashmap* map);

extern unsigned char hash (const char * string);

#endif /* _HASH_ */
