#include <stdio.h>

int my_strlen(char *str);

int main(){
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    printf("Length of the string is: %d\n", my_strlen(str));
    return 0;
}

//fgets liest auch das Enter mit ein und hängt \n an den Text. 
// Gibst du Hallo ein, steht im Array H a l l o \n \0. 
// Dein Programm zählt 6 statt 5.

//Nein, mit scanf("%s", ...) hast du das \n-Problem im Text nicht, dafür zwei andere.
int my_strlen(char *str){
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
        i++;
    }
    return i;
}