#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct random{
        int step;
        struct random *pointer;
    };
    
typedef struct random Random;
typedef Random *randomPointer;


int choose();
randomPointer createNewNodo();
int walk();


int main(){
    
    
    Random nodo;
    nodo.step= choose();
    
    Random *address, *tempAddress;
    address= &nodo;

    int steps, sum, lim;
    steps=0;
    sum=0;
    lim= 2;

    while (sum!=lim){
        
        tempAddress= createNewNodo(address);

        address = tempAddress;
        sum = walk(address);
        steps+=1;
    }

    printf("steps: %d \n", steps);
    
    return 0;
};

int choose(){

    int choices[]= {-1,1};

    __time_t t;

    srand((unsigned) time(&t));

    return choices[rand()%2];
};

randomPointer createNewNodo(Random  *pointer){

    Random *newPointer;


    newPointer=malloc(sizeof(Random));

    if (newPointer != NULL){
        newPointer->step = choose();
        newPointer->pointer = pointer;

        pointer->pointer=NULL;

    } else {

        printf("No hay memoria disponible");
    };
    return newPointer;
};

int walk(Random *currentPointer){
    
    int sum;

    sum=0;

    while (currentPointer!=NULL){

        sum += currentPointer->step;
        currentPointer = currentPointer->pointer;
    };

    return sum;
};