/* Predicción de texto T9, versión consola.
   HECHO EN BORLAND C++ 5.02 */
#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

class Diccionario{

	public:

		int i, j;
		int cantidadPalabras;
      char DiccionarioCOD[10000][20];
      char DiccionarioSTR[10000][20];


void abrirArchivo(void){//init leerArchivo

	//Abriendo archivo para leer.
	ifstream archivoDiccionario;
	archivoDiccionario.open("Diccionario_consola.txt", ios::in);
	cantidadPalabras = 0;


      //Abrir Archivo
		if(!archivoDiccionario){
			cout<<"Error en abrir archivo! Asegurese de que este se encuentre presente.";
			return;
		}



      char Temp[20], codAux[20];
      i = 0;
     	while(archivoDiccionario>>Temp){

        strcpy(DiccionarioSTR[i], Temp);

        itoa(construirArregloInt(Temp), codAux, 10);
        strcpy(DiccionarioCOD[i], codAux);

        cantidadPalabras++;
        i++;
      }

        archivoDiccionario.close();

        	cout<<"Palabras cargadas: "<< cantidadPalabras << endl;

}//fin leerArchivo

int construirArregloInt(char Auxiliar[20]) {//init construirArregloInt

 	int CodEntero = 0, CodigoFinal = 0, x = 0;
 	char CodCaracter;

 	while(Auxiliar[x]!= '\0'){//init separar

            CodCaracter = Auxiliar[x];

            switch(CodCaracter){//init switch

            case 'a': case 'b': case 'c':
                CodEntero += 2;
                break;

            case 'd': case 'e': case 'f':
                CodEntero += 3;
                break;

            case 'g': case 'h': case 'i':
                CodEntero += 4;
                break;

            case 'j': case 'k': case 'l':
                CodEntero += 5;
                break;

            case 'm': case 'n': case 'o':
                CodEntero += 6;
                break;

           case 'p': case 'q': case 'r': case 's':
                CodEntero += 7;
                break;

           case 't': case 'u': case 'v':
                CodEntero += 8;
                break;

           case 'w': case 'x': case 'y': case 'z':
                CodEntero += 9;
                break;
            default:;
                            }//fin switch
                  CodEntero= CodEntero*10;
            x++;

 			}//fin serparar
            CodigoFinal = CodEntero/10;
            return(CodigoFinal);

 }//fin ConstruirArregloInt

int entradaDeDatos(){
int Selecc;
char entrada[20];

if(Selecc = 0)return 0;


cout<<"Empiece a escribir: "<<endl;
cout<<">>";
cin >> entrada;

char Auxiliar[20];

cout<<"Sugerencias: \n"<<endl;
	for(i = 0; i < cantidadPalabras; i++){

        strcpy(Auxiliar, DiccionarioCOD[i]);
        Auxiliar[strlen(entrada)] = '\0';

          if(strcmp(Auxiliar, entrada) == 0){

             cout<<(DiccionarioSTR[i])<<endl;

        }//fin cond

    }//fin for 'i'

       cout<<"\n\nDesea buscar de nuevo?\n1 = Si.\n0 = No.\n>>";
       cin>>Selecc;
       switch(Selecc){
            case 1:
            	system("CLS");
               entradaDeDatos();
            case 0:
            	return 0;


       }
}

};//Fin Clase


int main(){

	Diccionario objeto;

	objeto.abrirArchivo();
   objeto.entradaDeDatos();
   cout<<"Pulse una tecla para salir.";
   getch();


}
