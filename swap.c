#include <stdio.h>

void swap(int* x, int* y);

int main(){
    int x,y;
    scanf("%d %d", &x,&y);

    printf("x is %d, y is %d\n", x, y); 
    swap(&x,&y);

    printf("SWAP x is %d, y is %d\n", x, y); 
    return 0;
}

void swap(int* x, int* y){
    int z = *x;
    *x = *y;
    *y = z;
}