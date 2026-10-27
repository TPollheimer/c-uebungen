#include <stdio.h>
#include <stdbool.h>

//add, sub, mul, divi
double add(int,int);
double sub(int,int);
double mul(int,int);
double divi(int,int);
bool check(int);

int main(){
    double (*ops[4])(int, int) = {add, sub, mul, divi};
    int auswahl = 0;
    do{
        printf("Enter a number from 0 to 3: ");
        scanf("%d",&auswahl);
        printf("\n");
    }while(check(auswahl) == false);
    int a = 0,b = 0;
    printf("Enter 2 numbers: ");
    scanf("%d%d",&a,&b);
    printf("\nErgebnis: %.2f\n",ops[auswahl](a,b));

    

    return 0;
}

double add(int x,int y){return x + y;}
double sub(int x,int y){return x - y;}
double mul(int x,int y){return x * y;}
double divi(int x,int y){
    if(y == 0){
        printf("division durch 0 !!!");
        return -1;
    }
    return (double)x/y;
}
bool check(int x){
    if (x >= 0 && x <= 3) return true;
    return false;
}