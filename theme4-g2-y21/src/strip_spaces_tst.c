#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

 char * skip_spaces( char s[]){

    int i=0;

    while(s[i] == ' '){
        i++;
    }
    
    return &s[i];

}


int main(int argc, char *argv[]){
    char * strip;
    int i; 
    assert(argc == 2);

    printf("argv  : %s\n", argv[1]);
    strip = skip_spaces(argv[1]);
    printf("strip : %s\n", strip);
    
    for (i=0 ; strip[i]; i++)
        strip[i] = toupper(strip[i]);
    
    printf("strip : %s\n", strip);
    printf("argv  : %s\n", argv[1]);
    // res : "FOO BAR"
    exit(EXIT_SUCCESS);
}