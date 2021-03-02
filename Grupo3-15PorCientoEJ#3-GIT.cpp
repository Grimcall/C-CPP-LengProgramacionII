
/*Desarrollar un programa que genere dos pilas
A y B con valores aleatorios entre 0 y 9 ;
calcule y escriba un a función que genere una tercera pila que muestre A∩B. */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>


int *A, *B, *C, *AUX;
int Ocurrencias = 0;


void generarNumeros(int *X, int nroArreglos, int lim);
void asignarNumeros(int *DESTINO, int *ORIGEN, int nroArreglo);
void visualizar(int *X, int N);
void buscarIgualdades(int *DESTINO, int *X, int *Y);


int main(void){
	A = (int*)malloc(10*sizeof(int));
	B = (int*)malloc(10*sizeof(int));
	AUX = (int*)malloc((2*10)*sizeof(int));

   //Generamos un espacio donde tendremos todos los valores iniciales.
   /* Esto lo hacemos porque la funcion aleatoria devuelve numeros
   	pseudo-aleatorios que siempren seran los mismos en cada ocurrencia
      durante el tiempo de ejecuci�n. Si utilizara esta funcion 2 veces
      para las pilas A y B, devolver�an los mismos numeros.
      Por eso, divido una pila auxiliar por la mitad con una limitante de espacios
      (ver par�metros) cuya implementacion es m�s corta y f�cil, y luego
      los reparto entre la pila A y B utilizando algoritmos mat�m�ticos
      (ver funcion asignarNumeros). */
		generarNumeros(AUX, 2, 10);

	printf("\nPresione una tecla para generar los elementos de A.\n");
	getch();
		asignarNumeros(A, AUX, 1); visualizar(A, 10);

	printf("\nPresione una tecla para generar los elementos de B. \n");
	getch();
		asignarNumeros(B, AUX, 2);
		free(AUX);
		visualizar(B, 10);


	C = (int*)malloc(10*sizeof(int));
	printf("\nPresione una tecla para generar los elementos de C. \n");
	getch();
	printf("A y B unidos dan lugar a C con los numeros: ");
		buscarIgualdades(C, A, B);
		free(A);
		free(B);
		visualizar(C, Ocurrencias);
		free(C);

	printf("\n\nPulse una tecla para salir. ");
	getch();
	return 0;

}

void generarNumeros(int *X, int nroArreglos, int lim){ //init generarNumeros
int i;
int numeroAleatorio;
int x = nroArreglos*lim;
srand(time(NULL));

for(i = 0; i < x; i++)
	{
	numeroAleatorio = (rand()%10);
	X[i] = numeroAleatorio;
	}
}//fin generarNumeros


void asignarNumeros(int *DESTINO, int *ORIGEN, int nroArreglo){//init asignarNumeros
	int limInferior, limSuperior, i, j;

limInferior = (nroArreglo-1)*10;
limSuperior = (nroArreglo)*10;
i = 0;

while(i < 10){

	for(j = limInferior; j < limSuperior; j++)
	{
	DESTINO[i] = ORIGEN[j];
	i++;
		}

	}

}//fin generarNumeros


void visualizar(int *X, int N){//init visualizar
	int i;

	for(i = 0; i < N; i++)
	printf("%d, ", X[i]);
	printf("\b\b.\n");

}//fin visualizar


void buscarIgualdades(int *DESTINO, int *X, int *Y){ //init buscarIgualdades


	int i, j, numero = 0, k;
	int lim = 10;
   int auxiliar[10];
	Ocurrencias = 0;


for(i = 0; i < lim; i++){
	for(j = 0; j < lim; j++){

		if(X[i] == Y[j]){
			numero = X[i];

			for(k = 0; k <= i; k++)	{
			if(numero == auxiliar[k])goto SALTAR;
		}

	    	auxiliar[Ocurrencias] = numero;
			Ocurrencias++; break;
		}
	}SALTAR:;
  }
	 for(i = 0; i < Ocurrencias; i++)
    DESTINO[i] = auxiliar[i];

}//fin buscarIgualdades
