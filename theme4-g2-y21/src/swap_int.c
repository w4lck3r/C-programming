#include <stdio.h>
#include "swap_int.h"

void swap_int(int* x, int* y){
    int temp; 
    temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    int x ,y;

    printf("Entrer x : ");
    scanf("%d \n",&x);


    printf("Entrer y : ");
    scanf("%d \n",&y);

    
    printf("x = %d,  y = %d\n\n",x,y);
     
    swap_int(&x , &y);

    printf("x vaut à présent %d \n\n",x);
    printf("y vaut à présent %d \n",y);
    
    return 0;

}