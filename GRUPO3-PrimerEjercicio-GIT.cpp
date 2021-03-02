/*Desarrolle un programa en C que efectúe lo siguiente:

1.      Lea desde un archivo de texto ‘lectura.dat’ un conjunto de oraciones (una por línea). En cada oración pueden haber: letras (mayúsculas y minúsculas), dígitos, espacios en blanco, comas (,), dos puntos (:), puntos y comas (;), paréntesis que abren y paréntesis que cierran. Una oración con cualquier otro carácter se considera incorrecta y, por lo tanto, no se procesa.  Para cada oración determine:
  i.         La palabra con más vocales
  ii.            La palabra más corta
  iii.            Numero de palabras
  iv.     Numero de vocales

a)      Al procesar todas las oraciones mostrar:

i. Número total de oraciones

ii. Número de oraciones incorrectas

b)      Desarrolle subprogramas para:

a. Leer una oración del archivo

b. Determinar si una oración es incorrecta.

c. Determinar si una frase es un palíndromo*/
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 500

int cont = 0, i = 0;

int main(){

char oracion[MAX], auxOracion[MAX][MAX], Reverso[MAX][MAX];
  FILE *p;
  p = fopen("lectura.dat", "r");

  if (p==NULL) {
    printf("\nArchivo incompatible/inexistente.");
    getch();
    return 0;}

    while(fgets(oracion, MAX, p) != NULL){

    	cont++;
    	oracion[strlen(oracion)-1] = '\0';
    	puts("");
    	strcpy(auxOracion[cont], oracion);

    }
   clrscr();

  	 int Matriz[MAX];
    int auxContV, j = 0, k, x, y, CantP = 0, auxMatriz, u;
    char Separar[MAX][MAX], corta[MAX], masVocales[MAX];
    int Incorrecto, nroIncorrecto = 0;
    int eleccion = 0;

   printf("Pulse una tecla para mostrar cada oracion.\n");
	getch();

    for(i = 1; i < cont+1; i++){ //init for 'i'
       /* Resetea todas las variables a 0. */
       u = 0;
  	    x = 0;
       y = 0;
       CantP = 0;
       Incorrecto = 0;
       auxContV = 0;
       auxMatriz = 0;
       printf("\n-#%d. %s", i, auxOracion[i]);
 	  strcpy(Reverso[i], auxOracion[i]);

	    for(j = 0; auxOracion[i][j] != '\0'; j++){  //init for 'j'

       /* Identifica si una oracion es correcta o incorrecta. */
     if((auxOracion[i][j] == '\0') ||(auxOracion[i][j] == '\n') ||
          (auxOracion[i][j] >= 'a' && auxOracion[i][j] <= 'z')  ||
          (auxOracion[i][j] >= 'A' && auxOracion[i][j] <= 'Z')  ||
          (auxOracion[i][j] >= '0' && auxOracion[i][j] <= '9' ) ||
         (auxOracion[i][j] == ' ') || (auxOracion[i][j] == ',') ||
         (auxOracion[i][j] == ':') || (auxOracion[i][j] == ';') ||
         (auxOracion[i][j] == '(') || (auxOracion[i][j] == ')')){ //init alg_incorrecto_1
		     /* Este goto sencillamente est� aqu� por par�metros del Borland.  */
            goto Continuar;
         }//fin alg_incorrecto_1

         else{
            Incorrecto = 1;
         }
           /* Cuenta el numero de palabras y prepara una matriz para separarlas sin espacios blancos.*/
           /* La variable Matriz[MAX] se usar� para contar las vocales, donde cada espacio corresponde
              al numero de vocales que tiene una palabra particular.
              Debimos haberla llamado vector.*/
 		  Continuar:if(auxOracion[i][j] == ' ' && auxOracion[i][j+1] != ' '){//init contar_palabras_or


         Matriz[u++] = auxMatriz;
   		auxMatriz = 0;

		  }//fin contar_palabras_or

        		/*Cuenta el numero de vocales y prepara la matriz separada para proxima verificacion. */
        if(auxOracion[i][j] != ' ' && auxOracion[i][j] != '\0'){//init separar_x_palabra

         Separar[x][y++] = auxOracion[i][j];

            if(auxOracion[i][j] == 'a' || auxOracion[i][j] == 'A' ||
            auxOracion[i][j] == 'e' || auxOracion[i][j] == 'E' ||
            auxOracion[i][j] == 'i' || auxOracion[i][j] == 'I' ||
          	auxOracion[i][j] == 'o' || auxOracion[i][j] == 'O' ||
       	 	auxOracion[i][j] == 'u' || auxOracion[i][j] == 'U'){//init contar_vocales

   				 auxContV++;
                auxMatriz++;
                  }//fin contar_vocales

        }
        else{
        /* Lista la oracion? Continuar.*/
        	Separar[x][y] = '\0';
        	x++;
         	y = 0; }//fin separar_x_palabra

      }//fin for 'j'



         nroIncorrecto += Incorrecto; //Cuenta la cantidad de oraciones incorrectas.
        	CantP = x + 1;              //Cuenta las palabras.
		   Matriz[u] = auxMatriz;      //Guarda la ultima posicion.
         strcpy(corta, Separar[0]);   //Inicializa el string sin espacios a una variable char que buscar� la palabra m�s corta..
         strcpy(masVocales, Separar[0]); //Inicializa el string sin espacios a una variable char que buscar� la palabra con m�s vocales.
         strrev(Reverso[i]);             //Invierte la oracion actual.

         /* Matando dos pajaros de un tiro. */
         for(k = 0; k < CantP; k++){//init for 'k'

                 /* Busca la palabra mas corta*/
         	if(strlen(corta) > strlen(Separar[k])){//init cond
         	 	strcpy(corta, Separar[k]); } //fin cond

               /* Busca la palabra con mas vocales.*/
	     	  if(Matriz[0] < Matriz[k]){ //init cond
	     		   Matriz[0] = Matriz[k];
	     		   strcpy(masVocales, Separar[k]);

		    } //fin cond
         } //fin for 'k'

         /* Resetea todos los elementos en el vector Matriz(que actualmente contaba las vocales) a 0.*/
		  for(j = 0; j < CantP; j++){
		  	Matriz[j] = 0;
		  }

    /* Verifica si una oracion es palindrome con una variable char de la misma oracion invertida. */
       if(strcmp(auxOracion[i], Reverso[i]) == 0){
  		      printf("\n-ORACION PALINDROME?: SI"); }
    	else{ printf("\n-ORACION PALINDROME?: NO"); }

    /* Verifica si se activ� la variable Incorrecto. */
	if(Incorrecto == 1){ printf("\n-ORACION INCORRECTA?: SI"); }
	   else{ 			   printf("\n-ORACION INCORRECTA?: NO"); }

      printf("\n-Palabra con mas vocales: %s\n", masVocales);
      printf("-Palabra mas Corta: % s\n", corta);
      printf("-Cant Palabras: %d\n", CantP);
      printf("-Cant Vocales: %d\n", auxContV);
      getch();
    } //fin for 'i'


    printf("\n\n--CANTIDAD DE ORACIONES: %d", cont);
    printf("\n--CANTIDAD DE ORACIONES INCORRECTAS: %d", nroIncorrecto);


LOOP:printf("\n--1. Leer Oracion");
    printf("\n--2. Salir del Programa");
    printf("\nOPCION: ");
    	scanf("%d", &eleccion);

      switch(eleccion){


       case 1:CUEK:printf("\nIndique el numero de la linea que desea leer (1 al %d): ", cont);
             scanf("%d", &i);
             if(i < 1 || i > cont){ printf("\nNUMERO INVALIDO. INTENTE DE NUEVO."); goto CUEK; }
             printf("\n((%s))\n", auxOracion[i]);

             goto LOOP;

    	 case 2:printf("\nPulse una tecla para salir... ");
    				getch();
    				fclose(p);
               return 0;

       default:printf("\nNUMERO INVALIDO. INTENTE DE NUEVO.");
       			goto LOOP;
      }




} //fin main
