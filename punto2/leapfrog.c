

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//prototipo

void calculo(int numero_puntos);

int main(){
    int i, numero_puntos;
    
    double altura, vel_ini, g=9.8; // no usar mas de 31 caracteres para nombrar una variable.
    double energia, masa, x, y, vx, vy, t, dt;
    double tiempo_caida;

    x = 0.0;
    y = altura = 10.0;
    vx = vel_ini = 1.0;
    vy = 0.0;
    t = 0.0;
    masa = 1.0;
    energia  = masa * g * altura;
    tiempo_caida = sqrt( 2.0*altura / g );

    printf("Inserte el número de puntos:\n");
    scanf("%d", &numero_puntos);

    dt = tiempo_caida / numero_puntos;

    char title[100];
    sprintf(title, "leapfrog%d.dat", numero_puntos);
    FILE *leapfrog= fopen(title, "w");
    fprintf(leapfrog,"%lf\t%lf\t%lf\t%lf\t%lf\n", t, x , y, vy, energia);

    //leapfrog integration

    for (t=0.0; t<=tiempo_caida; t += dt){

        vy= vy - g*dt;

        x = x + vx*dt;
        y= y + vy*dt + 0.5*g*(dt*dt);

        if (y>= 0.0)
            fprintf(leapfrog,"%lf\t%lf\t%lf\t%lf\t%lf\n", t, x , y, vy, energia);
        else
            break;
        
    };

    fclose(leapfrog);

    return 0;

};