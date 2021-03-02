/* Se tiene una matriz 20x20.
En la matriz hay un elemento repetido muchas veces.
Se quiere generar una matriz fila de 20 espacios y que en cada Filas
solo esten los elementos no repetidos.
Genere la matriz dinamica pedida y muestre en pantalla.
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define n 20

int **matrizA;
int *matrizFila;
int i, j, x;

void SepararElementos();

int main(void){

//Asignacion de Memoria
matrizA = (int**)calloc(20, sizeof(int*));
for( i = 0; i < n; i++) {
matrizA[i] = (int*)calloc(20, sizeof(int)); }

//Cargar Matriz
printf("Introduzca %dx%d elementos para la matriz: \n\n", n, n);
for(i = 0; i < n; i++){//init for 'i'
for(j = 0; j < n; j++){//init for 'j'
  	printf("-(%d)(%d): ", i, j);
   	scanf("%d", &matrizA[i][j]);
   		}//fir for 'j'
   	}//fin for 'i'

//Imprimir Matriz Ingresada
printf("\n Matriz Ingresada:\n");
for( i = 0; i < n; i++){
 for(j = 0; j < n; j++){
  	printf("%d ", matrizA[i][j]); }
       printf("\n");
           }
          printf("\n");

        SepararElementos();

//Imprimir Matriz Fila
        printf("\nMatriz Fila con elementos no repetidos. (20x1): \n", n);
         for(i = 0; i < 20; i++) {
         printf("%d\n", matrizFila[i]);
             }
        free(matrizFila);

        getch();
        return 0;


}

//Marca el elemento repetido para que se elimine.
void SepararElementos(){//init SepararELementos
int u, k, x;
int elementoRepetido = 0;


for(i = 0; i < n; i++){//init for 'i'
 for( j = 0; j < n; j++){//init for 'j'
       x = matrizA[i][j];

    		for(u = n-1; u != -1; u--){//init for 'u'
           for(k = n-1; k != -1; k--){//init for 'k'
   			  if(u == i && k == j){ goto NEXT; }
			  if(x == matrizA[u][k]){//init cond

              elementoRepetido = x;
              goto LISTO;

              }//fin cond

              }//fin for 'k'
            }//fin for 'u'
       NEXT:;}//fin for 'j'
         }//fin for 'i'

   LISTO:printf("\n El elemento repetido es %d.\n\n", elementoRepetido);




 matrizFila = (int*)calloc(20, sizeof(int));
  x = 0;
  for(i = 0; i < n; i++){//init for 'i'
   	for(j = 0; j < n; j++){//init for 'j'
         if(elementoRepetido == matrizA[i][j]){

           goto SKIP;
		  }

           else{  matrizFila[x++] = matrizA[i][j];}


       SKIP:;}//fin for 'j'

       }//fin for 'i'
        for(i = 0; i < 20; i++){ //init for 'i' LiberarMemoria
         				free(matrizA[i]);
     				 }//fin for 'i' LiberarMemoria
       				free(matrizA);


      }//fin SepararElementos
