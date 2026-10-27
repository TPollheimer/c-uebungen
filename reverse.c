#include <stdio.h>

void reverse(int *arr, int n);
void print_array(int *arr, int n);

int main(){
    int arr[] = {10,9,8,7,6,5,4,3,2,1,0};
    int sizeofarray = sizeof(arr) / sizeof(arr[0]);
    //char  c[10];      // sizeof(c) = 10, sizeof(c[0]) = 1  → 10 Elemente
    //double d[5];      // sizeof(d) = 40, sizeof(d[0]) = 8  → 5 Elemente
    reverse(arr,sizeofarray);
    print_array(arr,sizeofarray);
    return 0;
}

void reverse(int *arr, int n){
    int x = 0;
    for(int i = 0; i < n/2; i++){
        x = arr[n-i-1];
        arr[n-i-1] = arr[i];
        arr[i] = x;
    }
}

void print_array(int *arr, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}