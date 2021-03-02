/* Se tiene una pila con información de los alumnos de un curso. De cada alumno se sabe la matrícula, el nombre, la carrera y la cantidad de materias aprobadas. La pila está ordenada por matrícula. Se tiene otra pila con alumnos que acaban de rendir varios examenes, desordenada. Hacer una función que actualice la primera con los datos de la segunda. Si en la segunda hay algún alumno que no está en la primera, hay que agregarlo de manera que la pila siga ordenada. En cambio si el alumno está, hay que sumarle la cantidad de materias aprobadas.*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define MAX 50



typedef struct{

    int nroMatricula[MAX], materiasAprobadas[MAX];
    int tope;
    char nombre[MAX][MAX], carrera[MAX][MAX];

}LISTA;

LISTA Matriculados[MAX], Aprobados[MAX];

void pushInicial(int cantidad, LISTA *ptr, int i); //Funcion para agregar elementos a la Pila.
void mostrar(LISTA *ptr); //Funcion para mostrar la pila.
void reordenar(LISTA *ptr); //Funcion para reordenar la pila.

int main(){

        int n, cont = 0, continuar = 1;
        Matriculados[0].tope = -1;
        Aprobados[0].tope = -1;

        printf ("==BIENVENIDO==\n");


           printf("Introduzca la cantidad de alumnos para la primera pila: ");
           	scanf("%d", &n);

            pushInicial(n, Matriculados, cont);
            printf ("\nPILA #1 (DESORDENADA):\n");
            mostrar(Matriculados);
            printf("\n\nAhora, introduzca los datos de los alumnos que rindieron el examen.");


                      int i;
            while(continuar != 0){//init 1er while

              printf("\nNumero de Matricula/Cedula: ");
              	scanf("%d", &Aprobados[Aprobados[0].tope].nroMatricula);

                for(i = Matriculados[0].tope-1; i >= -1; i--){//init 'i'

                /*Busca si el numero de matricula ya existe en la otra pila.
                	Si existe, se salta el proceso de entrada de datos y se suma
                   la materia aprobada al alumno en la pila 1.	 */
                  if(*Aprobados[Aprobados[0].tope].nroMatricula == *Matriculados[i].nroMatricula){//init cond
                      printf("\n\n==COINCIDENCIA ENCONTRADA==\n");
                      printf("==DATOS GUARDADOS AUTOMATICAMENTE==\n");
                      printf("==MATERIA SUMADA==\n\n");

                     *Matriculados[i].materiasAprobadas += 1;

                       strcpy(*Aprobados[Aprobados[0].tope].nombre, *Matriculados[i].nombre);
                       strcpy(*Aprobados[Aprobados[0].tope].carrera, *Matriculados[i].carrera);
                      *Aprobados[Aprobados[0].tope].materiasAprobadas = *Matriculados[i].materiasAprobadas;

                     goto SKIP;
                        }//fin 'i'
                      }//fin cond

              printf("Nombre del alumno: ");
              	scanf("%s", &Aprobados[Aprobados[0].tope].nombre);
              printf("Carrera: ");
              	scanf("%s", &Aprobados[Aprobados[0].tope].carrera);
              printf("Cantidad de materias aprobadas: ");
              	scanf("%d", &Aprobados[Aprobados[0].tope].materiasAprobadas);

                        /* Pasa los datos del nuevo alumno a la Pila1 y principal. */
               *Matriculados[Matriculados[0].tope].nroMatricula = *Aprobados[Aprobados[0].tope].nroMatricula;
               *Matriculados[Matriculados[0].tope].materiasAprobadas = *Aprobados[Aprobados[0].tope].materiasAprobadas;
               strcpy(*Matriculados[Matriculados[0].tope].nombre, *Aprobados[Aprobados[0].tope].nombre);
               strcpy(*Matriculados[Matriculados[0].tope].carrera, *Aprobados[Aprobados[0].tope].carrera);
               Matriculados[0].tope = Matriculados[0].tope + 1;


          SKIP:printf("Desea continuar? (1 para si, 0 para no): ");
             	scanf("%d", &continuar);

            if(continuar < 0 || continuar > 1) { printf("\nNUMERO INCORRECTO. INTENTE DE NUEVO.\n"); goto SKIP; }

               Aprobados[0].tope = Aprobados[0].tope + 1;


            	}//fin 1er while
            printf ("\nPILA #2 (DESORDENADA):\n");
            mostrar(Aprobados);

            reordenar(Matriculados);
            printf("\nPILA #1 (ORDENADO POR MATRICULA):\n");
            mostrar(Matriculados);

   printf("\nPresiona una tecla para salir...");
getch();
return 0;

}

void pushInicial (int cantidad, LISTA *ptr, int i){ //Funcion para añadir un elemento a la pila.




    if (ptr[0].tope == (MAX - 1)){

        printf ("La pila esta llena.\n");
        return;
    } //Fin IF

    else{
       for(i = cantidad-1; i >= 0; i--){ //init for 'i

    //   clrscr();
        printf("Introduzca el numero de matricula/Cedula del alumno: ");
         scanf("%d", &ptr[ptr[0].tope].nroMatricula);
        printf("Introduzca su nombre: ");
        	scanf("%s", &ptr[ptr[0].tope].nombre);
        printf("Introduzca su carrera: ");
        	scanf("%s", &ptr[ptr[0].tope].carrera);
        printf("Introduzca la cantidad de materias aprobadas: ");
        	scanf("%d", &ptr[ptr[0].tope].materiasAprobadas);

        ptr[0].tope = ptr[0].tope + 1;



       }//fin for 'i'
    } // Fin ELSE
    return;

}//Fin Funcion PUSH


void mostrar (LISTA *ptr){ //Funcion para mostrar la pila.

    int i;
    if (ptr[0].tope == -1){

        printf ("La pila esta vacia.\n");
        return;

    }//Fin IF

    else{



        for (i = ptr[0].tope-1; i >= -1; i--){//init ciclo 'i'

            printf ("-#%d. %s // CARRERA: %s // Materias Aprobadas: %d \n", *ptr[i].nroMatricula, ptr[i].nombre,
            ptr[i].carrera, *ptr[i].materiasAprobadas);

        }//Fin Ciclo

    }//Fin ELSE

    printf ("\n");

}//Fin Funcion MOSTRAR

void reordenar(LISTA *ptr){//Reordena en base al numero de matricula.
									//Trat� de que se leyera como las matriculas que tenemos en la Uni o en el colegio.
         int i, j;
         int matriculaAux, materiasAprobadasAux;
         char nombreAux[MAX][MAX], carreraAux[MAX][MAX];

            for (i = ptr[0].tope-1; i >= -1; i--){//init 'i'
            	for (j = ptr[0].tope-1; j >= -1; j--){//init 'j'

          if(*ptr[j].nroMatricula < *ptr[j+1].nroMatricula){ //init cond

           strcpy(nombreAux[j], *ptr[j].nombre);    //Ordena Nombres
           strcpy(*ptr[j].nombre, *ptr[j+1].nombre);
           strcpy(*ptr[j+1].nombre, nombreAux[j]);

           strcpy(carreraAux[j], *ptr[j].carrera);    //Ordena Carrera
           strcpy(*ptr[j].carrera, *ptr[j+1].carrera);
           strcpy(*ptr[j+1].carrera, carreraAux[j]);


           matriculaAux = *ptr[j].nroMatricula;              //Ordena matriculaAux
           *ptr[j].nroMatricula = *ptr[j+1].nroMatricula;
           *ptr[j+1].nroMatricula = matriculaAux;


             materiasAprobadasAux = *ptr[j].materiasAprobadas;  //Ordena materiasAprobadas
           *ptr[j].materiasAprobadas = *ptr[j+1].materiasAprobadas;
           *ptr[j+1].materiasAprobadas = materiasAprobadasAux;

           				}//fin cond

                   }//fin 'j'
                 }//fin 'i'

		} //init 'reordenar'
