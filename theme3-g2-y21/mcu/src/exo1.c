#include <stdio.h>

#define SIZE 10

/*Question 1*/
/*
int main (void) {
  int tsrc[SIZE] = {1,2,3,4,5,6,7,8,9,10};
  int tdst[SIZE];
  int i;
  for (i = 0; i < SIZE; i++) {
    tdst[i] = tsrc[i];
  }

  for  (i = 0; i < SIZE; i++){
    printf("%d\n", tdst[i]);
  }
 }
*/

int main (void) {
  int tsrc[SIZE] = {1,2,3,-1,5,6,7,8,-9,10};
  int tdst[SIZE];

  
  int i_src;
  int i_dst;
  for (i_src = 0, i_dst = 0 ; i_src < SIZE; i_src++) {
    if ((tsrc[i_src]) > 0) {
	tdst[i_dst] = tsrc[i_src];
	i_dst++;
      }
  }
  while (i_src != i_dst) {
    tdst[i_dst] = 0;
    i_dst++;
  }

  int i;
  for (i=0; i < SIZE; i++) {
    printf("%d\n", tdst[i]);
  }
}
