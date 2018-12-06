#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "word.h"

int main(int argc, char *argv[]) {

Word* testword; 

char** test = malloc(sizeof(char*)*2);
test[0]= malloc(sizeof(char)*2);
strcpy(test[0],"a\0");
test[1]=NULL;

char** t = malloc(sizeof(char*)*2);
t[0]= malloc(sizeof(char)*2);
strcpy(t[0],"d\0");
t[1]=NULL;

assert(testword = word_new("blabla",test,t));

word_set_string(testword, "bloublou");

assert(strcmp(testword->string,"bloublou")==0);

word_free(testword);

return 0;


}
