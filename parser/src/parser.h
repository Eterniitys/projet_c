#ifndef _PARSER_H_
#define _PARSER_H_

#include <tree.h>
#include <word.h>
#include <hash.h>

extern Word** parser_read(const char* PATH, Tree** root, Tree** root_syll, Hashmap** map_syl_phon);

#endif /* _PARSER_H_ */

