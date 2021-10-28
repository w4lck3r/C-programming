#include "libga.h"
#include <stdio.h>
#include <stdlib.h>

/* def ga_set */
int ga_set(struct ga_s *ga, unsigned int index, int val){  
    if (index >= ga -> ga_size) {
        int i;
        if (ga == NULL) { 
            return -1;
        }
        int *elements = malloc((index + 1) * sizeof(int));  
        if (elements == NULL) {
            return -1;
        }
        for (i = 0; i < ga -> ga_size; i ++) {
            elements[i] = ga -> ga_elements[i];
        }
        free(ga -> ga_elements); 
        ga -> ga_elements = elements;
        ga -> ga_size = index + 1;
    }
    ga -> ga_elements[index] = val;
    return 0;
}

int ga_get(struct ga_s *ga, unsigned int index, int *val){
    if ( index <= ga -> ga_size ) {
        *val = ga -> ga_elements[index];
        return 0;
    }
    else{
        return -1;
    }
}

int ga_new(struct ga_s *ga){
    int i;
    ga -> ga_size = 3;
    ga -> ga_elements = malloc((ga -> ga_size) * sizeof(int));
    if ( ga -> ga_elements  == NULL ) { 
        return -1; 
    }
    for (i = 0; i < (ga -> ga_size); i ++) { 
        ga -> ga_elements[i] = 0; 
    }
    return 0;
}

int ga_del(struct ga_s *ga){   
    if (ga != NULL) {
        free(ga -> ga_elements); 
        return 0;
    }
    else{
        return -1;
    }
}

