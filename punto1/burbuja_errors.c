/*
Ultima modificacion : 19 de febrero de 2010

Este codigo implementa el algoritmo de la burbuja para encontrar
los primeros n vecinos a cada punto en una distribucion de puntos
aleatoria
 */

// Librerias de C
#include<stdio.h>
#include<stdlib.h> //1. #include<stdlib,h> --> la coma
#include<math.h>

// Variables globales
int puntoConVecinos;
double limDistancia = 100.0; //2. double limDistancia 100.0; --> el igual

// prototipos de funciones
int inicializa_posiciones(const int ,double *, double *, double *);
int calcula_distancia(const int nPuntos, double x[], double y[], double z[], const int nVecinos, int indices_ordenados[][nVecinos]);
int calcula_primeros_vecinos_burbuja(const int nPuntos, double distancia[], const int nVecinos, int indices_ordenados[][nVecinos], int indices[], int punto);

// Funcion principal
int main() //3. int main(voids) --> la función principal no tomar ese argumento
{
  int i,j;
  int nPuntos, nVecinos;
  
  // Obteniendo el numero de elementos del arreglo
  printf("Ingrese el numero de puntos:\n");
  scanf("%d",&nPuntos); //4. scanf("%d",nPuntos); --> le falta el &
  printf("Ingrese el numero de vecinos:\n");
  scanf("%d",&nVecinos);
  printf("Ingrese el id del punto que quiere ver:\n");
  scanf("%d", &puntoConVecinos); //5. scanf("%d", puntoConVecinos); --> le falta el &

  // definiendo los arreglos
  double x[nPuntos], y[nPuntos], z[nPuntos];
  int  indices_ordenados[nPuntos][nVecinos];

  // inicializa los arreglos de posicion
  inicializa_posiciones(nPuntos, x, y, z);
  
  // calcula distancia y los primeros n vecinos
  calcula_distancia(nPuntos, x, y, z, nVecinos, indices_ordenados);
  //6. calcula_distancia(nPuntos, x, z, nVecinos, indices_ordenados); --> le falta dar 'y' como argumento

  // imprime matriz de primeros vecinos y vecinos en archivo
  FILE *fMatrizVecinos = fopen("matriz_vecinos.dat", "w");
  for( i=0; i<nPuntos; i++ )
    {
      fprintf(fMatrizVecinos,"%d : ", i);
      for( j=0; j<nVecinos; j++ )
	      fprintf(fMatrizVecinos,"%d ",indices_ordenados[i][j]); //19.IDENTACIÓN
      fprintf(fMatrizVecinos,"\n");// 7. fprintf(fMatrizVecinos,"\m"); --> es n en lugar de m
    }
  fclose(fMatrizVecinos);  
  
  FILE *fVecinos = fopen("vecinos.dat", "w");
  for( i=0; i<nVecinos; i++ )
    fprintf(fVecinos," %d %lf %lf %lf\n",
	    indices_ordenados[puntoConVecinos][i],
	    x[indices_ordenados[puntoConVecinos][i]],
	    y[indices_ordenados[puntoConVecinos][i]],
	    z[indices_ordenados[puntoConVecinos][i]]);
  fclose(fVecinos);  
  
  return 0;
} // fin de la funcion principal

// Esta funcion inicializa las coordenadas x, y e z de cada punto usando 
// numeros aleatorios obtenidos con drand48 entre 0 y limDistancia

//8. inicializa_posiciones no devuelve un entero aunque fue declarada como una función que devuelve un entero
int inicializa_posiciones(const int nPuntos, double x[], double y[], double z[])
{
  int i;

  FILE *fPuntos = fopen("posiciones.dat","w");

  // inicializa con numeros aleatorios
  for( i=0; i<nPuntos; i++)
    {
      x[i] = drand48()*limDistancia;
      y[i] = drand48()*limDistancia;
      z[i] = drand48()*limDistancia;
      // graba en un archivo los puntos
      fprintf(fPuntos,"%d %lf %lf %lf\n",i,x[i],y[i],z[i]);
    }

  fclose(fPuntos);

  return 0;
}

// Esta funcion calcula las distancias punto a punto del sistema
//y hace un llamado a la funcion que hace el ordenamiento de burbuja //9. --> hizo falta las barras de comentado
// para ordenar la distancia de menor a mayor respecto al punto 
// etiquetado como puntoConVecinos

//10. faltan los corchetes para el argumento y
int calcula_distancia(const int nPuntos, double x[], double y[], double z[], const int nVecinos, int indices_ordenados[][nVecinos])
{
  int i, j, indices[nPuntos];
  double distancia[nPuntos];
  
  // calcula la distancia a cada punto
  for( i=0; i<nPuntos; i++ )
    {
      for( j=0; j<nPuntos; j++ )
	{
	  if( i!=j)
	    {
        //11. el índice de distancia debe ser un entero
	      distancia[j] = sqrt( (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) + (z[i]-z[j])*(z[i]-z[j]));
	    }
	  else
	    distancia[j] = 0.0;
	  
	}

  if( i==puntoConVecinos) //13. if tiene que llevar doble igual.
	{
	  // imprime la distancia ordenada de menor a mayor a puntoConVecinos
	  printf("inicial\n"); //14. Están truncados los prints.
	  for( j=0; j<nPuntos; j++ ) //15. el contador lleva doble igual
	    printf("%d %lf\n",indices[j],distancia[j]);
	  // imprime la etiqueta de los primeros n vecinos a puntoConVecinos
	  printf("\nprimeros vecinos al punto %d:\n",puntoConVecinos);
	  for( j=0; j<nVecinos; j++ )
	    printf("%d",indices_ordenados[puntoConVecinos][j]); //16. pone doble %d pero solo imprime una variable
	  printf("\n");
	}
  
  // ordena las distancias con algoritmo de burbuja 

  calcula_primeros_vecinos_burbuja(nPuntos, distancia, nVecinos, indices_ordenados, indices, i); 

    // imprime las distancias a puntoConVecinos
    if( i==puntoConVecinos )
	{
	  printf("\nfinal\n");
	  for( j=0; j<nPuntos; j++ ) 
	    printf("%d %lf \n",j,distancia[j]); //12. no es %l, sino %lf
	} 

  }
  
  return 0;
}

// Esta funcion ordena de mayor a menor un vector de distancias
// y almacena los indices de los primeros n vecinos en una matriz de vecinos

//17. n puntos no tiene const en la definición de la función pero sí en el prototipo.
int calcula_primeros_vecinos_burbuja(const int nPuntos, double distancia[], const int nVecinos, int indices_ordenados[][nVecinos], int indices[], int punto) 
{
  int i, j, almacena_indice;
  double almacena_distancia;
  
  // inicializa los indices
  for( i=0; i<nPuntos; i++ )
    indices[i] = i;
  
  //18. los argumentos del for se separan con ; no con ,
  for( i=0; i<nPuntos; i++ ) // ciclo que controla el numero de veces que se recorre el vector
    for( j=0; j<nPuntos-1; j++ ) // ciclo que recorre el arreglo
      {
	// compara los elementos adyasentes y los intercambia
	// si el primero es mayor que el segundo
	if( distancia[j] > distancia[j+1]  ) //19.doble mayor que
	  {
	    // ordenamiento burbuja
	    almacena_distancia = distancia[j];
	    distancia[j] = distancia[j+1];
	    distancia[j+1] = almacena_distancia;
	    
	    // ordena indices
	    almacena_indice = indices[j];
	    indices[j] = indices[j+1]; //20. el arreglo es indices, no indice.
	    indices[j+1] = almacena_indice;        
	  }
      }
  
  // llena matriz de vecinos
  for( i=0; i<nVecinos; i++ ) 
    indices_ordenados[punto][i-1] = indices[i+1];

  return 0;
}


