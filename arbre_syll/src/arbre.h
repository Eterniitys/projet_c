#ifndef _ARBRE_H_
#define _ARBRE_H_

#include <stdbool.h>

struc Arbre {
	char letter;
	bool end;
	Arbre **childs;
};

#endif
