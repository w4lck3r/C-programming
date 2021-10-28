#include <stdio.h>
#include <stdlib.h>
#include "dicho.h"


float * search_dicho(float value, float *tab, int size){

    int middle;   

    if (size <= 0){ 
        return NULL;
    }    
    else{
        middle =  size/2;
        if (value < tab[middle]){
            return search_dicho(value, tab, middle);
        }
        else if(value == tab[middle]){
            return &tab[middle];
        }
        else{
            return search_dicho(value,  &tab[middle], size-middle-1 );
        }
    }
}

int main(void){
   float *p;
   float tab[5];
   tab[4] = 15.9f;
   tab[3]= 15.8f;
   tab[2] = 5.7f;
   tab[1] = 5.6f;
   tab[0] = 5.3f;

   p = search_dicho(5.7f, tab , 5);
   if(p){
       printf("not found !");
   }
   else{
       printf("value found somewhere uwu");
   }


   return 0;
}