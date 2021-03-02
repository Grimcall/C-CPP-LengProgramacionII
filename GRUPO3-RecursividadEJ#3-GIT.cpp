/* Escriba una funcion recursiva que acepte un entero POSITIVO
como parametro y devuelva un entero con dos ocurrencias de cada digito, como salida
invirtiendo el numero a mostrar. Si por ejemplo el numero es 123 como entrada,
la salida debe ser 332211.*/
#include <stdio.h>
#include <conio.h>

long int NUMERO, aux;
long int Ocurrencias(long int numero);

int main(void){

   /* Borland 5.02 tiene una limitacion que cause cualquier numero que supere o iguale los 10 digitos
   	se convierta en un numero basura. En compiladores modernos, esto se arregla utilizando
      las opciones "long long var", pero esta opcion no est� disponible en Borland 5.02, y por lo tanto
      el valor m�ximo para enteros segun el manual del compilador es de -+2,147,483,647,
      el cual es muy facil sobrepasar con este programa debido a que la cantidad de digitos
      se multiplica por dos cuando se utiliza el mismo.
      Un numero de 3 digitos se convertir� en uno de 6 para cumplir con el enunciado,
      4 a 8, 5 a 10 y as�. */
 POS:printf("Introduzca un numero POSITIVO entero de MAXIMO 4 DIGITOS: ");
    scanf("%d", &NUMERO);
	if(NUMERO < 1)goto POS;


	printf("NUMERO FINAL: %ld", Ocurrencias(NUMERO));
getch();
return 0;


}

long int Ocurrencias(long int numero){
int digito;

 if(numero == 0)
 	{
 	 return aux;
 	}
	 	 else
	 {
		digito = numero % 10;
		numero = numero / 10;
		digito = (digito*10)+digito;
	 	aux = (aux*100)+digito;
		Ocurrencias(numero);
	 }


}
