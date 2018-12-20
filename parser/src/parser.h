#ifndef _PARSER_H_
#define _PARSER_H_

#include <hash.h>
#include <tree.h>
#include <word.h>

/**
 * \fn void parser_destroy_generated_structures(Tree* tree1, Tree* tree2,
 * Hashmap* map)
 *
 * \return void - destroy the generated's structures **
 */
extern void parser_destroy_generated_structures(Tree* tree1, Tree* tree2,
                                                Hashmap* map);

/**
 * \fn void parser_read(const char* PATH, Tree** root, Tree** root_syll,
 * Hashmap** map_syl_phon)
 *
 * \return void - read the parser **
 */
extern void parser_read(const char* PATH, Tree** root, Tree** root_syll,
                        Hashmap** map_syl_phon);

#endif /* _PARSER_H_ */
