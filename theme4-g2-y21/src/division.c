#include <stdio.h>
#include "division.h"

static int put_digit(int d){
    return (d >=0 && d <=9 && putchar('0'+d) != -1) ? 0 : -1;
}

static int putdec_positive(int h){
    int chiffre=0;
    int resultat = -1;
    int flag = 0;
    int dix_puissance_i = 1000000000;
    while (dix_puissance_i>0) {
        chiffre=h / dix_puissance_i %10;
        dix_puissance_i = dix_puissance_i / 10;
        if (chiffre > 0 || flag) {
            resultat = put_digit(chiffre);
            flag = 1;
        } 
    }
    if (!flag)
        putchar('0');
    return resultat;
}


int putdec(int h) {
    if (h < 0) {
        putchar('-');
        return putdec_positive(-h);
    } else
        return putdec_positive(h);
}


void division( int dividende, int diviseur, int *q, int *r){

    *q = dividende / diviseur;
    *r = dividende % diviseur;
}

int main(void){

    int dividende, diviseur, quotient , reste;
    dividende = 20;
    diviseur = 3;
    division(dividende, diviseur, &quotient, &reste);
    printf("%d / %d\n", dividende, diviseur);
    printf("quotient = ");
    putdec(quotient);
    putchar('\n');
    printf("reste = ");
    putdec(reste);
    putchar('\n');

    return 0;
}