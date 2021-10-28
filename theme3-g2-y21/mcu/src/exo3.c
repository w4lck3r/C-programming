/* EXO3 */

#include <stdio.h>

#define SIZE 10

void fonction(char t1[], char t2[], int src) {
  int i;
  for (i=0; i<SIZE; i++) {
    t1[i] = t2[i];
  }
}


int main(void) {
  char csrc[SIZE] = "Hello!";
  char cdst[SIZE];

  fonction (cdst, csrc, SIZE);

  int i ;
  for (i=0; cdst[i]!=0; i++) {
    putchar( cdst[i] );
  }
  putchar('\n');
}

