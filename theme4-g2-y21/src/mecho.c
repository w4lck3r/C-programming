/* Ma commande echo */

#include <stdio.h>
#include <stdlib.h>

/*
Actually this main will show us what we typped in cmd exe .
*/

int main(int argc, char *argv[]){
    //index value to use it in for loop
    int i;
    //loop to recieve element after element we have in argv table
    for( i = 1; i < argc; i++ ){
        //print the values of argv
        printf("%s \t", argv[i]);
    }
    putchar('\n');
    exit(EXIT_SUCCESS);
}

