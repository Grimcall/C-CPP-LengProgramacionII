/* Escriba una función que genere dinámicamente una matriz identidad de dimensión "N",
a partir del valor de su dimensión recibido como parámetro. Realizar las validaciones que considere necesarias. 12 PTS */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int **matriz, n;

void GeneraMatriz(int dimension);
void ImprimeMatriz(int dimension);

int main(void){ //init main

printf("Introduzca la dimension de la matriz: ");
scanf("%d", &n);

GeneraMatriz(n);
ImprimeMatriz(n);


getch();
return 0;

} //fin main

void GeneraMatriz(int dimension){ //init GeneraMatriz
int i, j;

      matriz = (int**)calloc(dimension, sizeof(int*));
      for(i = 0; i < dimension; i++){//init for 'i'
        matriz[i] = (int*)calloc(dimension, sizeof(int));
       }//fin for 'i'


       for(i = 0; i < dimension; i++){//init for 'i' filas
       	for(j = 0; j < dimension; j++){//init for 'j' cols

           if(i == j){ matriz[i][j] = 1; }

         }//fin for 'j' cols
       }//fin for 'i' filas

}    //fin GeneraMatriz

void ImprimeMatriz(int dimension){ //init ImprimeMatriz
int i, j;


for(i = 0; i < dimension; i++){ //init for 'i'
   for( j = 0; j < dimension; j++){ //init for 'j'

   		printf("%d ", matriz[i][j]);
          	}//fin for 'j'
            printf("\n");
   }//fin for 'i'

    for(i = 0; i < dimension; i++){ //init 2do for 'i' LiberarMemoria
         free(matriz[i]);
      }//fin 2do for 'i' LiberarMemoria
     	free(matriz);

}//fin ImprimeMatriz
