/* EXO2 */

#include <stdio.h>

#define SIZE 10

void fonction(int tdst[], int tsrc[], int src) {
  int i;
  for (i=0; i<SIZE; i++) {
    tdst[i] = tsrc[i];
  }
}


int main(void) {
  int tsrc[SIZE] = {1,2,3,-4,5,6,0,-8,9,10};
  int tdst[SIZE];

  fonction (tdst, tsrc, SIZE);

  int i ;
  for (i=0; i<SIZE; i++) {
    printf("%d\n", tdst[i]);
  }
}
