/* 2. Una farmacia del centro de la ciudad lleva un control de sus medicamentos registrando para cada uno de ellos: nombre, tipo de medicamento (1=Pastillas, 2=Jarabe, 3=Inyección, 4=Otro), precio y fecha de adquisición (expresada en Día, mes y año). La información está organizada por la fecha de adquisición. Desarrolle un programa que lea la información de un grupo de medicamentos y determine: a) Para cada día de adquisición

a.) Cantidad de medicamentos de cada tipo

b) Para todos los días

b.1) Mayor Promedio de venta de los jarabes

b.2) Día de adquisición donde se compró la mayor cantidad de Pastillas  */

#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 100

typedef struct{//Init. Estruct01.

	char Fechas[MAX][50];


}FECHA; //Fin. Estruct01.

typedef struct{//Init. Estruct01.

  char nombre[MAX][100];
 // int tipo[4][MAX]; //Continuar[MAX];
  float precio[MAX];
  FECHA ddn;

}DATOS;//Fin Estruct 02.
DATOS medicamentos[MAX];

int eleccion = 0, nroVentas = 0, j, VentasPastillas[MAX], OrdenTIPO[MAX], cantidadDias = 0;
int contJarabes = 0, MayorPastillas = 0;
long int Codigo[MAX];
float promedioFechas, promedioVentas;
char Dias[MAX][50];

void entrada(DATOS *ptr);
void listado(int j);
void reordenar(DATOS *ptr, int j);

int main(){ //init main.

  printf("\n======BIENVENIDO======");
  printf("\nIngrese el numero de la opcion que busca.\n");

 while(eleccion != 3) { //init while.

  printf("\n\n-1. Realizar Venta");
  printf("\n-2. Recibir listado de ventas");
  printf("\n-3. Salir del programa y recibir reporte final.\n");
  printf("-Opcion: ");
  	scanf("%d", &eleccion);

  if(eleccion < 1 || eleccion > 3){ //init primer cond.
    printf("\n\n**OPCION INVALIDA. INTENTE DE NUEVO.**");
  		}  //fin primer cond.

  if(eleccion == 1){ entrada(medicamentos); }
  if(eleccion == 2){ reordenar(medicamentos, j); listado(j); }
  if(eleccion == 3 && nroVentas == 0){ printf("Pulse una tecla para salir..."); getch(); return 0; }
 }  //fin while.

      for(j = 0; j < cantidadDias; ++j){ //init for 'j'

          if(VentasPastillas[0] < VentasPastillas[j]) {//init Cond
              	MayorPastillas = j;} //fin Cond
       				}//Fin for 'j'

 		reordenar(medicamentos, j);
      listado(j);


         promedioFechas = (float)contJarabes/(float)cantidadDias;
         promedioVentas = (float)contJarabes/(float)nroVentas;
         printf("\n\n\n==PROMEDIO DE DIAS EN QUE SE VENDEN JARABES: %0.2f%==", promedioFechas);
         printf("\n==PROMEDIO DE VENTAS DE JARABES: %0.2f%==", promedioVentas);
         //printf("\n==DIA CON MAYOR VENTAS DE PASTILLAS: %s==", medicamentos[MayorPastillas].ddn.Dias);
         printf("\n==DIA CON MAYOR VENTAS DE PASTILLAS: %s==", Dias[MayorPastillas]);


      printf("\n\nPulse una tecla para salir...");
      getch();
      return 0;
} //fin main


void entrada(DATOS *ptr){//init func entrada
   int TIPO;
   int Continuar = 1;
   int CodigoAux, ddAux, mmAux, yyAux;

      while( Continuar != 3){//init 1er while
         Continuar = 1;
       DIA:printf("--Dia de adquisicion? (dd): ");
        scanf("%d", &ddAux);
        if(ddAux < 1 || ddAux > 31){ printf("\nNUMERO INVALIDO. INTENTE DE NUEVO\n"); goto DIA; }

       MES:printf("--Mes de adquisicion? (mm): ");
        scanf("%d", &mmAux);
        if(mmAux < 1 || mmAux > 12){ printf("\nNUMERO INVALIDO. INTENTE DE NUEVO\n"); goto MES; }

       YEAR:printf("--A�o de adquisicion? (aaaa): ");
        scanf("%d", &yyAux);
        if(yyAux < 1000 || ddAux > 10000){ printf("\nNUMERO INVALIDO. INTENTE DE NUEVO\n"); goto YEAR; }


     while( Continuar != 3 && Continuar != 2 ){ //init 2do while
       printf("\n--Introduzca el nombre del producto: ");
        scanf("%s", &ptr[nroVentas].nombre);
       PRODUCTO:printf("\n--Tipo de Producto: ");
       printf("\n-1. Pastilla.");
       printf("\n-2. Jarabe.");
       printf("\n-3. Inyeccion.");
       printf("\n-4. Otro.");
       printf("\n-Opcion: ");
        scanf("%d", &OrdenTIPO[nroVentas]);

        /* Si se vende un Jarabe, se a�ade la venta a un contador de Jarabes.
           Si se vende una patilla, se a�ade a un vector que luego se iterar� para conseguir el d�a donde se vendieron. */
        if(OrdenTIPO[nroVentas] < 1 || OrdenTIPO[nroVentas] > 4){ printf("\nNUMERO INVALIDO. INTENTE DE NUEVO\n"); goto PRODUCTO; }
        if(OrdenTIPO[nroVentas] == 2){ contJarabes++; }
        if(OrdenTIPO[nroVentas] == 1){ VentasPastillas[cantidadDias] += 1; }


       printf("\n--Precio del producto?: ");
        scanf("%f", &ptr[nroVentas].precio);
       printf("\n==VENTA REGISTRADA==");

       /* Combina las fechas en un tipo de "codigo" para convertirlos en un string. */
       CodigoAux = (((yyAux*100)+mmAux)*100)+ddAux;
       /* Se guarda el "codigo" para iterarlo en el futuro con el fin de organizar las fechas.*/
       Codigo[nroVentas] = CodigoAux;

        /* Combina las fechas en una sola.*/
       sprintf(*ptr[nroVentas].ddn.Fechas, "%d/%d/%d", ddAux, mmAux, yyAux);
       nroVentas++;

 RETRY:printf("\n1. Realizar otra venta.");
       printf("\n2. Cambiar de fecha.");
       printf("\n3. Regresar al menu principal.");
       printf("\n--OPCION: ");
       	scanf("%d", &Continuar);

         if(Continuar < 1 || Continuar > 3){ //init primer cond.
    		printf("\n\n**OPCION INVALIDA. INTENTE DE NUEVO.**");
          goto RETRY;  }  //fin primer cond.
      			 } //fin 2do while

                strcpy(Dias[cantidadDias], *ptr[nroVentas-1].ddn.Fechas);
          			cantidadDias++;

           }//fin while
        }//fin func entrada


void reordenar(DATOS *ptr, int j){//init funcion reordenar
    int i, k, CodigoAux;
    char FechaAux[MAX][50];
    char nombreAux[MAX][50];
    float precioAux;
    int ListadoAux, tipoAux;
    for(k = 0; k < nroVentas-1; k++){//init for 'k'
       for(j = 0; j < nroVentas-1; j++){ //init for 'j'

         /* En base a las fechas, busca las fechas mayores y las organiza de forma adecuada.*/
         if(Codigo[j] < Codigo[j+1]) {//init primer cond

           CodigoAux = Codigo[j];                //Ordena Codigo
           Codigo[j] = Codigo[j+1];
           Codigo[j+1] = CodigoAux;

           strcpy(FechaAux[j], *ptr[j].ddn.Fechas);  //Ordena Fechas
           strcpy(*ptr[j].ddn.Fechas, *ptr[j+1].ddn.Fechas);
           strcpy(*ptr[j+1].ddn.Fechas, FechaAux[j]);

           strcpy(nombreAux[j], *ptr[j].nombre);    //Ordena Nombres
           strcpy(*ptr[j].nombre, *ptr[j+1].nombre);
           strcpy(*ptr[j+1].nombre, nombreAux[j]);

           precioAux = *ptr[j].precio;              //Ordena Precio
           *ptr[j].precio = *ptr[j+1].precio;
           *ptr[j+1].precio = precioAux;

           tipoAux = OrdenTIPO[j];                  //Ordena Tipos
           OrdenTIPO[j] = OrdenTIPO[j+1];
           OrdenTIPO[j+1] = tipoAux;


          }//fin primer cond
       }//fin for 'j'
     }//init for 'k'
   }//fin funcion reordenar



void listado(int j){//init func listado
      int contPrint = 1;


		  	for(j = 0; j < nroVentas; j++){ //fin for 'j'

            printf("\n\n-#%d. NOMBRE: %s", contPrint, medicamentos[j].nombre);
            switch(OrdenTIPO[j]) {
                    case 1: printf("\n--TIPO: PASTILLA"); break;
                    case 2: printf("\n--TIPO: JARABE");   break;
                    case 3: printf("\n--TIPO: INYECCION"); break;
                    case 4: printf("\n--TIPO: OTRO");     break;
            		 }

            printf("\n-PRECIO: %0.2f", *medicamentos[j].precio);
            printf("\n-FECHA: %s", medicamentos[j].ddn.Fechas);
             contPrint++;
         } //fin for 'j'
	}//fin func listado
