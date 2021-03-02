/* Escribir una función que te permita cargar una matriz de valores enteros de manera dinámica.
UD debe desarrollar solamente esta función. */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int i, j, n;
int **MATRIZ;

void cargarArreglo(int** MAT, int dimension, int i, int j);
void mostrarMatriz(int** MAT, int dimension, int i, int j);
void liberarMemoria(int** MAT, int dimension, int i);


int main(void){

printf("Introduzca la dimension de la matriz: ");
scanf("%d", &n);

MATRIZ = (int**)calloc(n, sizeof(int*));
for( i = 0; i < n; i++) {
MATRIZ[i] = (int*)calloc(n, sizeof(int)); }
i = 0;

cargarArreglo(MATRIZ, n, i, j);
printf("\n");
mostrarMatriz(MATRIZ, n, i, j);
liberarMemoria(MATRIZ, n, i);

getch();
return 0;

}

//>>FUNCION BUSCADA POR EL ENUNCIADO>>
void cargarArreglo(int **MAT, int dimension, int i, int j){

		printf("(%d)(%d): ", i, j);
		scanf("%d", &MAT[i][j]);
if(i == dimension-1 && j == dimension-1 ) return;

else{  if(j == dimension-1)
		{
		 		cargarArreglo(MAT, dimension, i+1, 0);
		}
		else
		{
				cargarArreglo(MAT, dimension, i, j+1);
		}
}

}
//<<FUNCION BUSCADA POR EL ENUNCIADO<<



void mostrarMatriz(int** MAT, int dimension, int i, int j)
{

for(i = 0; i < dimension; i ++)
	{
	for(j = 0; j < dimension; j++)
		{
		printf("(%d) ", MAT[i][j]);
		}
	printf("\n");
	}

}


void liberarMemoria(int** MAT, int dimension, int i){

	for(i = 0; i < dimension; i++){ //init  for 'i' LiberarMemoria
         free(MAT[i]);
      }//fin  for 'i' LiberarMemoria
     	free(MAT);

}
