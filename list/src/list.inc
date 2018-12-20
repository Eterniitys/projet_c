/**
 * \file test-lock.c
 * \struct List list.h "Définition"
 * \author Kilian
 * \version 0.1
 * \date 15 november 2018
 */

#ifndef _LIST_INC_
#define _LIST_INC_
#include <stdbool.h>

/**
 * \fn void _list_qs(List* list, int A, int B)
 *
 * \return  - if the list is lock, sort it in its place
 */
void _list_qs(List* list, int A, int B);

/**
 * \fn static List* _list_init(List* list)
 *
 * \return list - init the list (variable, malloc the list)
 */
static List* _list_init(List* list);

#endif /* _LIST_INC_ */
