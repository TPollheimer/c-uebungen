#include <stdio.h>
#include <string.h>

struct student {
    int age;
    int grade;
    char name[40];
};

typedef struct {
    int id;
    char title[40];
    float hours; 
} course;

typedef struct {
  int x;
  int y;
} point;

typedef struct {
  float radius;
  point center;
} circle; 


// Student Structure Definition
struct student1 {
    char name[50];
    int number;
    int age;
};

// Struct pointer as a function parameter
void showStudentData(struct student1 *st) {
    printf("\nStudent:\n");
    printf("Name: %s\n", st->name);
    printf("Number: %d\n", st->number);
    printf("Age: %d\n", st->age);
}

struct Point {
  int x;
  int y;
} p1;

void pointerzuweisung(struct Point *ptr1){
    ptr1 = &p1;
    ptr1->x = 3;
    ptr1->y = 4;
}
union Daten {
    unsigned int  zahl;        // als eine ganze Zahl
    unsigned char byte[4];     // dieselben Bytes einzeln
};

int main() {
    /* declare two variables */
    struct student s1;
    struct student s2;
    
    s1.age = 19;
    s1.grade = 9;
    sprintf(s1.name, "John Bighimer");
    
    s2.age = 22;
    s2.grade = 10;
    sprintf(s2.name, "Batman Jokerson"); // wir speicher "" in s2.name
    
    printf("\nStudent: %s, %d\n", s1.name, s1.age);
    printf("Student: %s, %d\n\n", s2.name, s2.age);
    /**********************************************/

    course cs1;
    course cs2;

    cs1.id = 123456;
    strcpy(cs1.title, "JavaScript Basics");
    cs1.hours = 12.30;

    /* initialize cs2 */
    cs2.id = 341281;
    strcpy(cs2.title, "Advanced C++");
    cs2.hours = 14.25;
       
    /* display course info */
    printf("\n%d\t%s\t%4.2f\n", cs1.id, cs1.title, cs1.hours);
    printf("%d\t%s\t%4.2f\n\n", cs2.id, cs2.title, cs2.hours);
    /**********************************************/

    point p;
    p.x = 3;
    p.y = 4;
    
    circle c;
    c.radius = 3.14;
    c.center = p;
    
    printf("\nCircle radius is %.2f, center is at (%d, %d)\n", c.radius, c.center.x, c.center.y);
    /**********************************************/

    // New Student Record Creation
    struct student1 st1;
    struct student1 st2;
    
    // Filling Student 1 Details
    strcpy(st1.name, "Krishna");
    st1.number = 5;
    st1.age = 21;
    // Filling Student 2 Details
    strcpy(st2.name, "Max");
    st2.number = 9;
    st2.age = 15;

    // Displaying Student 1 Details
    showStudentData(&st1);
    
    // Displaying Student 2 Details
    showStudentData(&st2);
    /**********************************************/

    struct Point *ptr1 = &p1;
    pointerzuweisung(ptr1);

    printf("\n%d\t%d\n",ptr1->x,ptr1->y);
    
    /**********************************************/
    // Zahl vor dem Punkt (%8.2f): Mindestbreite, es wird links mit Leerzeichen aufgefüllt, nie etwas abgeschnitten.
    // Zahl nach dem Punkt (%8.2f): Anzahl der Nachkommastellen, es wird gerundet.
    /**********************************************/
    union Daten d;
    d.zahl = 123456;

    for (int i = 0; i < 4; i++) {
        sende_byte(d.byte[i]);     // jedes Byte einzeln senden
    }
    //Du schreibst die Zahl hinein und liest die Bytes heraus, ohne zu kopieren oder zu rechnen. Genauso geht es umgekehrt, wenn du 4 empfangene Bytes zu einer Zahl zusammensetzen willst.
    /**********************************************/
    /**********************************************/
    /**********************************************/   
    return 0;
}