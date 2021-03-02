 /* Los resultados parciales de una competencia deportiva multidisciplinaria son guardados,
 para cada evento en una misma lista simple ordenada por código de competidor en orden creciente.
 De cada competidor se conoce:
 Código del competidor (con un número entero), Club al que representa y tiempo obtenido.
 Se solicita hacer una función que resuma en la misma lista los tiempos totales obtenidos por cada competidor en todas las disciplinas.
Nota: Eventos son las distintas disciplinas dentro de la competencia, por ejemplo ciclismo, natación, salto, etc.
Cada competidor puede participar en 1 o más eventos.
Deberá quedar la lista ordenada por código de competidor en órden creciente y cada competidor deberá
figurar solo una vez con el total de tiempo utilizado.
10. Implemente un directorio de personas usando listas (simples o dobles) que guarde
y recupere información de archivos, pero que maneje la información en memoria. Los campos básicos deben ser: (nombre, telefono, email). */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo{
 int codigo, eventos;
 int tiempo;

        struct nodo *siguiente;

        char Club[100];
} nodo;

nodo* primero = NULL;
nodo* ultimo = NULL;

void agregar_elemento();
int BUSCAR(int CODIGO);
void mostrar_lista();
void mostrar_menu();
void cambiar(struct nodo *A, struct nodo *B);
void ordenarLista(struct nodo *X);

int main(void){

        int opcion;

        while(opcion != 3){

      	mostrar_menu();
        scanf("%d", &opcion);
      	switch (opcion){
                        case 1: agregar_elemento(); break;
                        case 2: mostrar_lista(); break;
                     	case 3: return 0; }
	  }
	return 0;

    }



    void agregar_elemento(){

	nodo* nuevo = (nodo*) malloc(sizeof(nodo));

	  int CodigoAux = 0;
        printf( "\n ===== Nuevo Competidor =====" );
        printf( "\nCodigo del competidor: " );
        	scanf( "%d", &CodigoAux);
        	if(BUSCAR(CodigoAux) == 1)return;

	   nuevo->codigo = CodigoAux;

        printf( "Club al que pertenece: ");
            scanf("%s", &nuevo->Club);
        printf("Tiempo realizado (Segundos): ");
            scanf("%d", &nuevo->tiempo);
            nuevo->eventos = 1;

      if(primero==NULL){
		primero = nuevo;
		primero->siguiente = NULL;
		ultimo = nuevo;
	}else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = NULL;
		ultimo = nuevo;
	}

}


int BUSCAR(int CODIGO){

	nodo* actual = (nodo*) malloc(sizeof(nodo));


	actual = primero;
int TiempoAux = 0;
int encontrado = 0;

	if(primero!=NULL){
		while(actual != NULL && encontrado != 1){

			if(actual->codigo == CODIGO){
							printf("\nCoincidencia Encontrada. ");

					 printf("\nIntroduzca el tiempo (segundos) para el competidor #%d: ", CODIGO);
				 			scanf("%d", &TiempoAux);
				 			actual->tiempo += TiempoAux;
				 			actual->eventos++;

					encontrado = 1;
					return 1;
		}
			actual = actual->siguiente;

	}
		if(encontrado == 0)return 0;
	}

}

void mostrar_lista(){
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;

	ordenarLista(actual);

	if(primero!=NULL){
		while(actual != NULL){

			printf("\nCodigo del Competidor: %d ",actual->codigo);
			printf("\nClub del Competidor: %s ", actual->Club);
			printf("\nTiempo (Segundos):  %d segundos. ", actual->tiempo);
			printf("\nEventos Participados: %d", actual->eventos);


			printf("\n\n");
			actual = actual->siguiente;
		}
	}else{
		printf("\n La lista se encuentra vacia\n\n");
	}
}

void mostrar_menu(void){
        printf( "\n ===== Menu =====" );
        printf( "\n\n 1 - Agregar Competidor" );
        printf( "\n 2 - Mostrar Competidores" );
        printf( "\n 3 - Salir" );
        printf("\n\n Escoge una opcion: ");
}

void ordenarLista(struct nodo *X){

	int cambio;

	struct nodo *ptr;
	struct nodo *ptr2 = NULL;

	if (X == NULL) return;

	do{

		cambio = 0;
		ptr = X;

		while(ptr->siguiente != ptr2){

		if(ptr->codigo > ptr->siguiente->codigo){

			cambiar(ptr, ptr->siguiente);
			cambio = 1;

		}
		ptr = ptr->siguiente;
	}
	 ptr2 = ptr;
	}
	while(cambio);

}

void cambiar(struct nodo *A, struct nodo *B){

		int codigoTemp = A->codigo;
		int TiempoTemp = A->tiempo;
		int EventoTemp = A->eventos;
		char ClubTemp[50];
		strcpy(ClubTemp, A->Club);

		A->codigo = B->codigo;
		A->tiempo = B->tiempo;
		A->eventos = B->eventos;
		strcpy(A->Club, B->Club);

		B->codigo = codigoTemp;
		B->tiempo = TiempoTemp;
		B->eventos = EventoTemp;
		strcpy(B->Club, ClubTemp);
	}
