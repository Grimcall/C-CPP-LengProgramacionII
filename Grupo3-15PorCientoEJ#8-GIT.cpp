/* Escribir un programa que utilice pila para comprobar si una determinada frase o palabra es un palindrome. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>


char *pilaCadena;
int tope = -1;


void push(char Elemento);
char pop();
void eliminarEspacios(char Cadena[]);
int esPalindrome(char Cadena[]);

int main (void){

	char Frase[500];
	int i;
	printf("Introduzca su palabra/frase: ");
		gets(Frase);


		for(i = 0; Frase[i]; i++){
  Frase[i] = tolower(Frase[i]);
						}

		eliminarEspacios(Frase);


		printf("\nCadena introducida: '%s'\n", Frase);

		if(esPalindrome(Frase)){
			printf("La cadena introducida es palindrome. ");
			}

		else {
			printf("La cadena introducida no es palindrome. ");
		}

	printf("\n\nPulse una tecla para salir.");

	free(pilaCadena);
	getch();
	return 0;

}

void push(char Elemento)
{ //Init Funcion Push
    pilaCadena[++tope] = Elemento;
} //Fin Funcion Push



char pop()
{ //Init Func Pop
	return pilaCadena[tope--];
} //Fin Func Pop



void eliminarEspacios(char Cadena[])
{ //Init Func EliminarEspacios
   	int i;
    int cuenta = 0;

       for (i = 0; Cadena[i]; i++)
        if (Cadena[i] != ' ')
            Cadena[cuenta++] = Cadena[i];
    Cadena[cuenta] = '\0';
} //Fin Func EliminarEspacios



int esPalindrome(char Cadena[])
{ // Init Func esPalidnrome
	int longitud = strlen(Cadena);

	pilaCadena = (char*)malloc(longitud*sizeof(char));

	int i, med = longitud / 2;

	for(i = 0; i < med; i ++){
		push(Cadena[i]);
	}

	if(longitud%2 != 0){
		i++;
	}

	while(Cadena[i] != '\0'){
		char Elemento = pop();

		if(Elemento != Cadena[i])
			return 0;
			i++;
	}
	return 1;
} // Fin Func esPalindrome
