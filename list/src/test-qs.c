/**
 * \file test-lock_qs.c
 * \brief testing program 
 * \author Kilian
 * \version 0.1
 * \date 15 november 2018
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>

#include "./list.h"


int compare_int(void* a, void* b) {
	return *(int*)a - *(int*)b;
}

bool check_list_sorted(List* list) {
	int i;
	bool output = true;
	for (i=1; i < list_count(list); i++) {
		output = output && compare_int(list_get(list, i-1), list_get(list, i)) <= 0;
	}
	if (!output) {
		fprintf(stderr, "List not sorted !\n");
		for (i=0; i<list_count(list);i++) {
			fprintf(stderr, "%d\t", *(int*)list_get(list,i));
		}
		fprintf(stderr, "\n");
	}
	return output;
}

int main(void) {
	// first column is length of line
	int count = 14;
	int max_length = 10;
	int datasets[14][10] = {
		{0},		//0
		{1,1},		//1
		{2,1,2},	//2
		{2,2,1},	//3
		{3,3,2,1},	//4
		{3,3,1,2},	//5
		{3,2,3,1},	//6
		{3,2,1,3},	//7
		{3,1,2,3},	//8
		{3,1,3,2},	//9
		{2,-2,4},	//10
		{9,123,98,123,132,187,984,123,-1,0},	//11
		{9,700,68,123,123,187,984,1,-1,0},	//12
		{9,123,98,123,132,187,984,123,-1,0}	//13
	};

	List* list;

	int i;
	for (i=0; i < count; i++) {
		list = list_new(&compare_int);
		int j;
		fprintf(stderr, "List %d\n", i);
		for (j=1; j <= datasets[i][0]; j++) {
			list_add(list, &(datasets[i][j]));
		}
		assert(list_count(list) == datasets[i][0]);
		list_lock(list);
		assert(list_count(list) == datasets[i][0]);
		assert(check_list_sorted(list));
		list_destroy(list, NULL);
	}
	return EXIT_SUCCESS;
}

