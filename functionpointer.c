#include <stdio.h>

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }


int main(){
    int (*op)(int, int);    // op ist ein Zeiger auf eine solche Funktion (diese funktion gibt int zurück und hat (int,int) als übergabe parameter)
    op = add;               // zeigt auf add (ohne Klammern, ohne &)
    printf("%d\n", op(3, 4));   // ruft add auf → 7
    printf("%d\n", add(3, 4));   // ruft add auf → 7
    op = sub;
    printf("%d\n", op(3, 4));   // ruft sub auf → -1
    printf("%d\n", sub(3, 4));   // ruft add auf → -1

    return 0;
}
/*
int anwenden(int (*f)(int, int), int a, int b) {
    return f(a, b);          // ruft die Funktion auf, die man ihr gibt
}

int main(void) {
    printf("%d\n", anwenden(add, 3, 4));   // 7
    printf("%d\n", anwenden(sub, 3, 4));   // -1
    return 0;
}
*/