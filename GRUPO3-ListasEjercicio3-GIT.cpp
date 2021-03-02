 /* Considere una lista enlazada que contiene enteros positivos. Tome tantos enteros positivos como sea posible como entrada y crear la lista inicial hasta que el usuario ingrese el valor -9999 para terminar la entrada. Imprimir la
 lista enlazada en el orden en que fueron ingresados los datos.
 Escribir una función llamada find_pox(x) que retorne la posición de x en la lista. */
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{ //nodo es el nombre de la estructura
    int valor;
    struct nodo *sig; //El puntero siguiente para recorrer la lista enlazada
}numero; //tnodo es el tipo de dato para declarar la estructura

typedef numero *tpuntero; //Puntero al tipo de dato tnodo para no utilizar punteros de punteros

void insertarEnLista (tpuntero *cabeza, int e);
void imprimirLista (tpuntero cabeza);
int find_pox(tpuntero *cabeza, int x);

int main(){
    int e, X, cont = 0, pos;
    tpuntero cabeza; //Indica la cabeza de la lista enlazada, si la perdemos no podremos acceder a la lista
    cabeza = NULL; //Se inicializa la cabeza como NULL ya que no hay ningun nodo cargado en la lista

  printf("Ingrese elementos, -9999 para terminar: ");
   scanf("%d",&e);

    while(e!=-9999){
        insertarEnLista (&cabeza, e);
        printf("Ingrese el sig: ");
        scanf("%d",&e);
        cont++;

    }


    printf ("\nSe imprime la lista cargada en el orden introducido: ");
    imprimirLista(cabeza);
    printf("\nIndique el valor a buscar: ");
    scanf("%d", &X);
    //printf("\nPosicion en el orden original: %d", find_pox(&cabeza, X));
    pos = cont-(find_pox(&cabeza, X));
    printf("\nPosicion en el orden ingresado: %d", pos-1);
    printf ("\n");
    system ("PAUSE");

return 0;
}

void insertarEnLista (tpuntero *cabeza, int e){
    tpuntero nuevo; //Creamos un nuevo nodo
    nuevo = (numero*)malloc(sizeof(numero)); //Utilizamos malloc para reservar memoria para ese nodo
    nuevo->valor=e; //Le asignamos el valor ingresado por pantalla a ese nodo
    nuevo->sig = *cabeza; //Le asignamos al siguiente el valor de cabeza
    *cabeza = nuevo; //Cabeza pasa a ser el ultimo nodo agregado
}

void imprimirLista(tpuntero cabeza){

	if(cabeza == NULL) return;

	if(cabeza){ //Mientras cabeza no sea NULL
    		imprimirLista(cabeza->sig);
			printf(" %d",cabeza->valor); //Imprimimos el valor del nodo

        //Pasamos al siguiente nodo
    }
}


int find_pox (tpuntero *cabeza, int x){
int posicion;
tpuntero nuevoNodo;
posicion = 0;

nuevoNodo = *cabeza;

while(nuevoNodo != NULL && nuevoNodo->valor != x){
nuevoNodo = nuevoNodo->sig;
posicion++;

}

return (nuevoNodo != NULL) ? posicion:-1;

}
