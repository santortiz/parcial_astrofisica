#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct random{
        int step;
        struct random *pointer;
    };
    
typedef struct random Random;
typedef Random *pointerRandom; 


int choose();
void createNewNodo();
int walk();


int main(){

    Random nodo;
    nodo.step= choose();

    int sum, lim;

    sum = walk(&nodo);

    printf("%d", sum);

    return 0;
};


//choose() devuelve aleatoriamente -1 o 1.

int choose(){

    int choices[]= {-1,1};

    __time_t t;

    srand((unsigned) time(&t));

    return choices[rand()%2];
};

void createNewNodo(pointerRandom *pointer){

    pointerRandom newPointer;
    pointerRandom previousPointer;
    pointerRandom currentPointer;


    newPointer = malloc(sizeof(Random));

    if (newPointer != NULL){
        newPointer-> step = choose();
        newPointer->pointer = NULL;

        previousPointer = NULL;
        currentPointer = *pointer;

        if (previousPointer == NULL){
            newPointer->pointer= *pointer;
            *pointer = newPointer;

        } else{
            previousPointer->pointer = newPointer;
            newPointer->pointer= currentPointer;
        };
    } else {

        printf("No hay memoria disponible");
    };
};

int walk(pointerRandom currentPointer){
    
    int sum;
    sum= 0;

    while (currentPointer!= NULL){
        sum+= currentPointer->step;
    };

    return sum;
};