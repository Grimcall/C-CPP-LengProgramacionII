/* Escribir una función Reemplazar que tenga como argumentos una pila con tipo de elemento int y dos valores int:
 nuevo y viejo de forma que si el segundo valor aparece en algún lugar de la pila, sea reemplazado por el segundo. */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct COLA
{
//La mayor�a de carros tienen letras en su placa, por eso la variable tipo char.
char Placa[100];
char Color[100], Modelo[100];
char Dueno[100];
char HoraDeEntrada[100];
char year[100];
float monto;

struct COLA *next;

}*CAB=NULL, *AUX=NULL, *FIN=NULL;

int Estacionamiento = 0, Circulados = 0;
float PrecioPorHora, total = 0.0f;

void encolar(void);
void desencolar(void);
void finDia(void);

int main(void){
	int Eleccion;
	printf("Introduzca el precio por hora: ");
		scanf("%f", &PrecioPorHora);

	Eleccion = 1;
	while(Eleccion > 0 && Eleccion < 3){

		printf("\n1. Encolar.");
		printf("\n2. Desencolar.");
		printf("\n3. Terminar el dia y salir.");
		printf("\n-Eleccion: ");
			scanf("%d", &Eleccion);

				switch(Eleccion){

					case 1: encolar(); break;
					case 2: desencolar(); break;
					case 3: finDia(); break;

				}
	}
	printf("\nPulse una tecla para salir del programa. ");
	getch();

}

void encolar(void){

	if(Estacionamiento == 100){
		printf("El estacionamiento esta lleno!");
		return;
	}
	AUX=(struct COLA*)malloc(sizeof(struct COLA));

	printf("\nPlaca: ");
		scanf("%s", AUX->Placa);
	printf("Color: ");
		scanf("%s", AUX->Color);
	printf("Modelo: ");
		scanf("%s", AUX->Modelo);
	printf("Nombre del due�o: ");
		scanf("%s", AUX->Dueno);
	printf("Hora de Entrada: ");
		scanf("%s", AUX->HoraDeEntrada);
	printf("'Year' de vehiculo: ");
		scanf("%s", AUX->year);

		Estacionamiento++;

	AUX->next=NULL;
	if(FIN==NULL) FIN=CAB=AUX;
	else
	{
		FIN->next=AUX;
		FIN=AUX;
	}


}


void desencolar(void){

	if(CAB==NULL)return;
	AUX=CAB;

	float HorasTranscurridas;

	printf("\nIntroduzca las horas transcurridas en el estacionamiento: ");
		scanf("%f", &HorasTranscurridas);


	printf("Se ha retirado a: \n");
	printf("\n-Placa: %s", AUX->Placa);
	printf("\n-Color: %s", AUX->Color);
	printf("\n-Modelo: %s", AUX->Modelo);
	printf("\n-Dueno: %s", AUX->Dueno);
	printf("\n-Hora de Entrada: %s", AUX->HoraDeEntrada);
	printf("\n-Horas transcurridas: %0.2f", HorasTranscurridas);
	printf("\n-Year: %s", AUX->year);

	AUX->monto = HorasTranscurridas*PrecioPorHora;
   printf("\n-Monto: $%0.2f\n\n", AUX->monto);
	total += AUX->monto;
	Circulados++;
	Estacionamiento--;

	CAB=CAB->next;
	free(AUX);

}

void finDia(void){


	printf("\n-Total acumulado: $%0.2f", total);
	printf("\n-Vehiculos circulados: %d", Circulados);
	printf("\n-Vehiculos Restantes en el Estacionamiento: %d", Estacionamiento);

}
