/**
 * \file hash.inc
 * \class hash
 * \author Johan
 * \version 0.1
 * \date 25 november 2018
 *
 * Allows the hashing of string
 *
 */
#ifndef _HASH_INC_
#define _HASH_INC_

/**
 *\fn int xora(int a, int b)
 *
 *\return a xor operation between a and b
 */
int xora(int a, int b);

/**
 *\fn void rpl(Hashmap* map)
 *
 * Allow a tables per cent view
 */
void rpl(Hashmap* map);

/**
 *\fn void _new_tab(Hashmap* map)
 *
 *\ create a new hash table
 */
void _new_tab(Hashmap* map);

#endif /* _HASH_INC_ */
