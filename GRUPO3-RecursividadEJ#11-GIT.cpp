/* Elabore un programa que determine
todos los numeros primos circulares de cinco digitos. */
# include <stdio.h>
# include <conio.h>
#include <math.h>

long int esPrimo(long int x);
long int esCircular(long int x, long int cuenta);

long int i, aux, aux2, Circulo = 0;
long int y = 0, Comparacion = 0;


int main(void)
{
	int eleccion = 0;
    int PRIMO;
	long int NUMERO = 10000, limiteInferior = 9999, limiteSuperior = 99999;

	    printf("\n==INTRODUZCA UNA OPCION==\n");
	    printf("--------------------------------------------------------\n");
	    printf("\n\n-1. (PREDETERMINADO) Iterar busqueda de primos para cinco digitos.\n");
	    printf("-2. Establecer limites manualmente. \n");
	    printf("-3. Salir.\n");
	    printf("\nELECCION: ");
	    	scanf("%d", &eleccion);

	    switch (eleccion){

	    	case 1:	break;
	    	case 2: printf("Limite Inferior: ");
	    			scanf("%d", &limiteInferior);
	    			NUMERO = limiteInferior;
	    			printf("Limite Superior: ");
	    			scanf("%d", &limiteSuperior);
	    			break;
	    	case 3: return 0;
		}

	 printf("Numeros Primos Circulares: \n----------------------------\n");

	while(NUMERO >= limiteInferior && NUMERO < limiteSuperior){

	   i = NUMERO/2;
    PRIMO = esPrimo(NUMERO);
    if(PRIMO==1) esCircular(NUMERO, y);
	NUMERO++;
}
	printf("\n\n==LISTO. Pulse una tecla para salir.==\n");
	getch();
   return 0;
}

long int esPrimo(long int x){
    if(i==1)
    {
        return 1;
    }
    else if(x %i==0)
    {
         return 0;
    }
    else
       {
         i = i -1;
         esPrimo(x);
      }
  //    return x;
}

long int esCircular(long int x, long int cuenta){
int digito; // CANTIDAD;


if(x == 0){
	if(Comparacion == cuenta+1)printf("%ld, ", Circulo);
	 cuenta = 0;
	 Comparacion = 0;
	 Circulo = 0;
	  return x;

 	}  else{

	//INIT COND
	if(Circulo != 0){

	digito = Circulo % 10;
	aux = Circulo / 10;
	aux2 = aux;
	cuenta = 0;

	do{

			cuenta++;
			aux /= 10;

		}while(aux != 0);

	Circulo = digito*(pow(10, cuenta));
	Circulo = (Circulo + aux2);
		} //FIN

		else{

	//Factorizar el �ltimo d�gito.
	digito = x % 10;
	aux = x / 10;
	aux2 = aux;
	cuenta = 0;

	//Contar la cantidad de d�gitos restantes.
		do{

			cuenta++;
			aux /= 10;

		}while(aux != 0);

	//Multiplicar d�gito por 10^(cuenta)
	Circulo = digito*(pow(10, cuenta));

	//Sumar nueva variable con los d�gitos restantes.
	Circulo = (Circulo + aux2);

	//Eliminar el �ltimo digito de la variable x para propositos de romper funci�n.
	}
	x = x / 10;
	 i = Circulo/2;
	 if(esPrimo(Circulo) == 1)Comparacion++;
	 else{
	 cuenta = 0;
	 Comparacion = 0;
	 Circulo = 0;
	 return x;	 }
	 esCircular(x, cuenta);

	 }
	 return x;

}
