#include <stdio.h>

#define MAXLINE 80

int readl(int line[]){
  int i = 0;
  int c;

  do {
    c = getchar();
    line[i] = c;
    i++;
  } while (c != '\n');

  line[i] = 0;
  return i;
  

}
