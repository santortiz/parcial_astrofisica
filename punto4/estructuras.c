#include <stdio.h>
#include <stdlib.h>


int main(){

    struct persona{
        char *firstName;
        char *lastName;
        int age;
    } persona1, persona2;

    persona1.firstName= "Jorge";

    printf("%s \n", persona1.firstName);

    typedef struct persona persona;

    persona persona3;

    persona3.firstName= "Sergio";

    printf("%s \n", persona3.firstName);

    return 0;
    
};