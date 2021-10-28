#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *mstrdup(const char *str) {
    void *new = malloc((strlen(str) + 1)); //alocate the size of the char in mimory
    if (new == NULL) {
        return NULL; 
    }
    return (char *) memcpy(new, str, size); //Casting to char type  and return the char copied in new
}

int main(int argc, char *argv[]) {
    int i;
    for ( i = 0; i < argc; i ++) {
        char * dup = mstrdup(argv[i]); //creat the duplicate char typed in cmd
        printf(" %s \n", dup);
        free(dup); //free up the memory 
    }
    return 0;
}