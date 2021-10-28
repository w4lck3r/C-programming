#include <stdio.h>

int compteur(){
    static int cmp=0; //init cmp
    cmp++;
    return cmp;
}

int main(){
    int i;
    for (i=0; i<10; i++ ) {
        printf("%d eme appel : %d\n", i, compteur()); // i = 0  cmp : 1
    }
    return 0;
}