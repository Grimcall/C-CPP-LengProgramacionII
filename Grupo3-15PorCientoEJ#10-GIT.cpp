 /* Se tiene un estacionamiento con 100 puestos para carros el cual posee una sola entrada para los vehículos y una única salida.
 Cada vez que entra un vehículo se toman los siguientes datos nro de placa, color, modelo, nombre del dueño, año, hora de entrada,
 al momento de la salida del vehiculo se debe calcular el monto por el estacionamiento.
 Considere el precio actual por hora.
 Al final del día se desea saber el total acumulado por recaudación de entrada de vehículos y la cantidad total de vehículos que circularon,
 debe indicar si quedo algún vehiculo en el estacionamiento.
 Diseñe un programa que simule el funcionamiento de dicho estacionamiento, utilizando para ello la estructura cola vista en clases.*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#define MAX 50

typedef struct{

    int ELEMENTOS[MAX];
    int tope;

}Pila;

Pila *A, *B;

void Reemplazar(Pila *ptr, int nuevo, int viejo);
void push(Pila *ptr, int numero);
void pop(Pila *ptr);
void mostrar(Pila *ptr);
void liberaPila (Pila *ptr);
void liberarMemoria(Pila *ptr);
int Vacia(Pila *ptr);
int Tope(Pila *ptr);


int TAMANO;

int main(void){

	int i, NUMERO, NUEVO, VIEJO;

	printf("Indique el tama�o de la pila: ");
		scanf("%d", &TAMANO);
	A = (Pila*)malloc(TAMANO*sizeof(Pila));
	B = (Pila*)malloc(TAMANO*sizeof(Pila));
	A[0].tope = -1;
	B[0].tope = -1;

	printf("Introduzca los elementos de la pila: \n");
	for(i = 0; i < TAMANO; i++){
		scanf("%d", &NUMERO);
		push(A, NUMERO);
	}

	printf("\nPila: \n");
 	mostrar(A);

	printf("\n Introduzca el numero viejo: ");
		scanf("%d", &VIEJO);
	printf("\n Introduzca el numero nuevo: ");
		scanf("%d", &NUEVO);

	printf("\nPila Actualizada: \n");
	Reemplazar(A, NUEVO, VIEJO);
	mostrar(A);
   liberarMemoria(A);

   printf("\nPulse una tecla para salir.");
   getch();

}

void push(Pila *ptr, int numero){ //Funcion para añadir un elemento a la pila.

    if (ptr[0].tope-1 == (TAMANO - 1)){

        printf ("La pila esta llena.\n");
        return;
    } //Fin IF

    else{

	  ptr->ELEMENTOS[ptr->tope] = numero;
	  ptr->tope++;

    } // Fin ELSE
    return;

}//Fin Funcion PUSH

void pop(Pila *ptr){//init POP
  ptr->tope--;
 } //fin POP


int Vacia(Pila *ptr){//init VACIA
  return(ptr->tope == -1);
 }//fin VACIA

int Tope(Pila *ptr){//init TOPE
	if (Vacia(ptr)) {
     printf("No hay elementos en la pila."); //return numero;
	 }
   //  numero = ptr->ELEMENTOS[ptr->tope-1];
  return(ptr->ELEMENTOS[ptr->tope-1]);

}//fin TOPE

void mostrar (Pila *ptr){ //Funcion para mostrar la pila.

    int i;
    if (ptr[0].tope == -1){

        printf ("La pila esta vacia.\n");
        return;

    }//Fin IF

    else{


        for (i = ptr[0].tope-1; i >= -1; i--){//init ciclo 'i'

            printf ("%d\n", ptr->ELEMENTOS[i]);

        }//Fin Ciclo

    }//Fin ELSE

    printf ("\n");

}//Fin Funcion MOSTRAR

void Reemplazar(Pila *ptr, int nuevo, int viejo){//init REEMPLAZAR
	int aux;

	while(!Vacia(ptr)){
		aux = Tope(ptr);
		if(aux == viejo) push(B, nuevo);
		else push(B, aux); pop(ptr);
	}

	while(!Vacia(B)){

	 aux = Tope(B);
	 pop(B);
	 push(ptr, aux);
	}

}//fin REEMPLAZAR

void liberarMemoria(Pila *ptr){
 while(!Vacia(ptr)) pop(ptr);
free(ptr->ELEMENTOS);
free(ptr);

}
