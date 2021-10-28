#define T (65+1)
extern int putchar(int c);


#include <stdio.h>
int put_digit(int digit){
  if (((digit < 0) || (digit >9)) & (putchar(digit + '0')==EOF)){
    return -1;
  }
  return 0;
}


int putdec(int nombre) {
  int nbchiffres = 0;
  int fact=1;
  int subst=nombre;
  while (subst != 0) {
    subst = subst / 10;
    nbchiffres++;
    fact = fact * 10;
  }
  fact = fact / 10;
  while (nbchiffres != 0){
    if (put_digit((nombre / fact) % 10) == -1) return -1;
    fact = fact / 10;
    nbchiffres--;
  }
  return 0;
}
