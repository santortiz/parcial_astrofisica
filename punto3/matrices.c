
#include <stdio.h>
#include <stdlib.h>


void suma();
void resta();
void escalar();
void matricial();

int main(){

    int id;

    printf("Este programa ejecuta las siguientes operaciones entre matrices: \n Recuerde que n es el número de filas y m el número de columnas de una matriz. \n");
    printf(" 1. Suma de matrices \n 2. Resta de matrices \n 3. Producto por un escalar \n 4. Producto matricial \n");
    printf("Por favor, diga qué operación quiere realizar: \n");
    scanf("%d", &id);

    switch (id)
    {
    case 1:
        suma();
        break;
    
    case 2:
        resta();
        break;

    case 3:
        escalar();
        break;
    
    case 4:
        matricial();
        break;
    
    default:
        printf("La operación no existe");
        break;
    }

    return 0;
}

void suma(){

    int n,m;
    printf("Introduzca las dimensiones de las matrices \n n: ");
    scanf("%d", &n);
    printf(" m: ");
    scanf("%d", &m);

    int primera[n][m];
    int segunda[n][m];
    int result[n][m];

    int i, j;

    printf("Introduzca los valores de la primera matriz \n");
    for (i=0;i<n;i++){
        for (j=0; j<m; j++){
            printf("(%d,%d): ", i, j);
            scanf("%d", &primera[i][j]);
        };
    };

    printf("Introduzca los valores de la segunda matriz \n");
    for (i=0;i<n;i++){
        for (j=0; j<m; j++){
            printf("(%d,%d): ", i, j);
            scanf("%d", &segunda[i][j]);
        };
    };

    for (i=0;i<n;i++){
        for (j=0; j<m; j++){
            result[i][j]= primera[i][j] + segunda[i][j];
        };
    };


    printf("Matriz resultante: \n");
    for (i=0;i<n;i++){
        for (j=0; j<m; j++){
            printf("%d ", result[i][j]);
        };
        printf("\n");
    };

};


void resta(){

    int n,m;
    printf("Introduzca las dimensiones de las matrices \n n: ");
    scanf("%d", &n);
    printf(" m: ");
    scanf("%d", &m);

    int primera[n][m];
    int segunda[n][m];
    int result[n][m];

    int i, j;

    printf("Introduzca los valores de la primera matriz \n");
    for (i=0;i<n;i++){
        for (j=0; j<m; j++){
            printf("(%d,%d): ", i, j);
            scanf("%d", &primera[i][j]);
        };
    };

    printf("Introduzca los valores de la segunda matriz \n");
    for (i=0;i<n;i++){
        for (j=0; j<m; j++){
            printf("(%d,%d): ", i, j);
            scanf("%d", &segunda[i][j]);
        };
    };

    for (i=0;i<n;i++){
        for (j=0; j<m; j++){
            result[i][j]= primera[i][j] - segunda[i][j];
        };
    };


    printf("Matriz resultante: \n");
    for (i=0;i<n;i++){
        for (j=0; j<m; j++){
            printf("%d ", result[i][j]);
        };
        printf("\n");
    };

};

void escalar(){

    int a;

    int n,m;
    printf("Introduzca las dimensiones de la matriz \n n: ");
    scanf("%d", &n);
    printf(" m: ");
    scanf("%d", &m);

    int matriz[n][m];
    int result[n][m];

    int i, j;

    printf("Introduzca los valores de la matriz \n");
    for (i=0;i<n;i++){
        for (j=0; j<m; j++){
            printf("(%d,%d): ", i, j);
            scanf("%d", &matriz[i][j]);
        };
    };

    printf("Dé el valor del escalar: \n");
    scanf("%d", &a);

    for (i=0; i<n; i++){
        for (j=0; j<m; j++){
            result[i][j]= a*matriz[i][j];
        };
    };

    printf("Matriz resultante: \n");
    for (i=0;i<n;i++){
        for (j=0; j<m; j++){
            printf("%d ", result[i][j]);
        };
        printf("\n");
    };
};

void matricial(){
    int n1,m1, n2, m2;

    do {
        printf("Recuerde: el número de columnas de la primera matriz debe coincidir con el número de filas de la segunda matriz. \n");
        printf("Introduzca las dimensiones de la primera matriz \n n: ");
        scanf("%d", &n1);
        printf(" m: ");
        scanf("%d", &m1);


        printf("Introduzca las dimensiones de la segunda matriz \n n: ");
        scanf("%d", &n2);
        printf(" m: ");
        scanf("%d", &m2);
    } while (m1!=n2);

    int primera[n1][m1];
    int segunda[n2][m2];
    int result[n1][m2];

    int i, j;

    printf("Introduzca los valores de la primera matriz \n");
    for (i=0;i<n1;i++){
        for (j=0; j<m1; j++){
            printf("(%d,%d): ", i, j);
            scanf("%d", &primera[i][j]);
        };
    };

    printf("Introduzca los valores de la segunda matriz \n");
    for (i=0;i<n2;i++){
        for (j=0; j<m2; j++){
            printf("(%d,%d): ", i, j);
            scanf("%d", &segunda[i][j]);
        };
    };

    int k;
    int sum;

    for (i=0; i<n1;i++){
        for (j=0; j<m2; j++){
            sum= 0;
            for (k=0; k<m1; k++){
                sum+= primera[i][k]*segunda[k][j];
            };
            result[i][j]= sum;
        };
    };

    printf("Matriz resultante: \n");
    for (i=0;i<n1;i++){
        for (j=0; j<m2; j++){
            printf("%d ", result[i][j]);
        };
        printf("\n");
    };
    
};