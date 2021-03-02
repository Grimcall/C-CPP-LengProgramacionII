 /* Se tiene una lista con las facturas que deben los clientes de una empresa.
 En cada nodo figura el código del cliente, el número de factura y el importe.
 La lista está ordenada por cliente y puede haber más de una factura por cliente.
 Hacer una función que reciba la lista, el número de un cliente y un importe que representa el pago de un cliente y
 elimine de la lista las primeras facturas de dicho cliente para las que alcanza el pago.
Si el importe no alcanza para pagar una factura no seguir buscando más facturas. Informar si sobró algo del importe después de pagar. */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct nodo{
 int codigo, factura;
        float importe1;
        float pago;
        struct nodo *siguiente;
        float DeudaTotal;
} nodo;

nodo* primero = NULL;
nodo* ultimo = NULL;

void agregar_elemento();
int BUSCAR(int CODIGO);
void mostrar_lista();
void mostrar_menu();
void cambiar(struct nodo *A, struct nodo *B);
void ordenarLista(struct nodo *X);
void mostrar_listaFINAL();

int main(){

        int opcion;



      while(opcion != 3){

      	mostrar_menu();
        scanf("%d", &opcion);
      	switch (opcion){
                        case 1: agregar_elemento(); break;
                        case 2: mostrar_lista(); break;
                     	case 3: mostrar_listaFINAL(); return 0;}
	  }
	return 0;
}


void agregar_elemento(){

	nodo* nuevo = (nodo*) malloc(sizeof(nodo));

	  int CodigoAux;

        printf( "\n ===== Nueva factura =====" );
        printf( "\nCodigo de cliente: " );
        	scanf( "%d", &CodigoAux);
        	if(BUSCAR(CodigoAux) == 1){

			return;}

	   nuevo->codigo = CodigoAux;
        printf( "Codigo de Factura: " );
            scanf("%d", &nuevo->factura);
        printf("Importe del Cliente: ");
            scanf("%f", &nuevo->importe1);

     if(primero==NULL){
		primero = nuevo;
		primero->siguiente = NULL;
		ultimo = nuevo;
	}else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = NULL;
		ultimo = nuevo;
	}

	printf("\n Nodo ingresado con Exito\n\n");
}


int BUSCAR(int CODIGO){

	nodo* actual = (nodo*) malloc(sizeof(nodo));


	actual = primero;
	float PagoAux = 0.0f;
	float ImporteAux = 0.0f;

	int eleccion = 0;
	int encontrado = 0;

	if(primero!=NULL){
		while(actual != NULL && encontrado != 1){

			if(actual->codigo == CODIGO){
				printf("\nCoincidencia Encontrada. ");
				printf("\nDesea realizar un pago(1) o incrementar su importe?(2): ");
				scanf("%d", &eleccion);
				switch(eleccion){
					case 1: printf("\nIntroduzca el Pago para %d: ", CODIGO);
				 			scanf("%f", &PagoAux);
				 			actual->pago += PagoAux;
				 			break;
					case 2: printf("\nIntroduzca el Importe para %d: ", CODIGO);
				 			scanf("%f", &ImporteAux);
				 			actual->importe1 += ImporteAux;
				 			break;
				}

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



	if(primero!=NULL){
		while(actual != NULL){

			printf("\nCodigoCliente: %d ",actual->codigo); //Imprimimos el valor del nodo
			printf("\nFacturaCliente: %d ", actual->factura);
			printf("\nImporteCliente: $%0.2f ", actual->importe1);
			printf("\nPagoCliente: $%0.2f", actual->pago);


			printf("\n\n");
			actual = actual->siguiente;
		}
	}else{
		printf("\n La lista se encuentra vacia\n\n");
	}
}

void mostrar_menu(void){
        printf( "\n ===== Menu =====" );
        printf( "\n\n 1 - Agregar factura" );
        printf( "\n 2 - Mostrar clientes" );
        printf( "\n 3 - Ordernar listas, imprimir, y salir. " );
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
		float importeTemp = A->importe1;
		int facturaTemp = A->factura;
		float pagoTemp = A->pago;

		A->codigo = B->codigo;
		A->importe1 = B->importe1;
		A->factura = B->factura;
		A->pago = B->pago;

		B->codigo = codigoTemp;
		B->importe1 = importeTemp;
		B->factura = facturaTemp;
		B->pago = pagoTemp;
	}

 void mostrar_listaFINAL(){
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;

	ordenarLista(actual);
	float DeudaAux = 0.0f;
	if(primero!=NULL){
		while(actual != NULL){

			printf("\nCodigoCliente: %d ",actual->codigo); //Imprimimos el valor del nodo
			printf("\nFacturaCliente: %d ", actual->factura);
			printf("\nImporteCliente: $%0.2f ", actual->importe1);
			printf("\nPagoCliente: $%0.2f", actual->pago);

			actual->DeudaTotal = (actual->pago - actual->importe1);
			DeudaAux = actual->DeudaTotal;

			printf("\nDeudaFINAL: $%0.2f", actual->DeudaTotal);
			if(DeudaAux > 0.0f)printf(" (SOBRANTE. EL PAGO EXCEDE LA DEUDA.)");
			if(DeudaAux < 0.0f)printf(" (RESTANTE. FALTA POR PAGAR.)");
			if(DeudaAux == 0.0f)printf(" (EXACTO)");

			printf("\n\n");
			actual = actual->siguiente;
		}
	}else{
		printf("\n La lista se encuentra vacia\n\n");
	}
	printf("\nPulse una tecla para salir del programa.");
	getch();
}
