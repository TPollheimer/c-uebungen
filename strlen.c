#include <stdio.h>

void strlen1(char *str);

int main(){
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    strlen1(str);
    return 0;
}

void strlen1(char *str){
    int i = 0;
    while(str[i] != '\0'){
        ++i;
    }
    printf("Length of the string is: %d", i);
}