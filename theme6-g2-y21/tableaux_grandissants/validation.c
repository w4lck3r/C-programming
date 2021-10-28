#include <stdio.h>
#include <stdlib.h>
#include "libga.h" //to use set get del

int main(void){
    struct ga_s tab;
    int val;
    int i, j;
    int count=0;

    ga_new(&tab);
    while (scanf("%u\n", &val) == 1) {
        ga_set(&tab, count, val);
        count++;
    }
    
    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            int vali, valj;
            ga_get(&tab, i, &vali); 
            ga_get(&tab, j, &valj); 
            
            if (vali > valj) {         //  permute               
                ga_set(&tab, i, valj); 
                ga_set(&tab, j, vali);
            }        
        }
    }
    for (i = 0; i < count; i++) {
        ga_get(&tab, i, &val);
        printf("%u\n", val);
    }
    
    ga_del(&tab);
    exit(EXIT_SUCCESS);
}

