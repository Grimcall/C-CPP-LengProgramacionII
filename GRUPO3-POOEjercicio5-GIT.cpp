/* TERCER CORTE, Ejercicio #5 POO, 15%
	--UNEFA-NPC, 11.12.2020
   --INGENIERIA DE SISTEMAS, 5TO SEMESTRE
   --LENGUAJE DE PROGRAMACION II
   --Grupo #3
   --ESTUDIANTES:

   *DIEGO PARRA, V-26.671.334
   *KATHERINE GARCIA, V-26.696.857

   --PROFESORA:
   *YELMIN PEREZ */
#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std; //NO COMPATIBLE NI NECESARIO EN BORLAND C++
const int MAX = 10;

class Matriz{  //Declaración clase MATRIZ.

	public:

   	//Decl. Variables.
		int X;
		//N = Vendedores; M = Productos
		int N, M;
        int i, j;

      //Decl. Arreglos
		int Ventas[MAX][MAX];
        int nroVendedor[MAX];
		float Promedios[MAX];	


 void leerArchivo(void){  //init leerArchivo

   //Abriendo archivo para leer.
	ifstream archivoInicial;
	archivoInicial.open("NxM.txt", ios::in);

		if(!archivoInicial){
			cout<<"Error en abrir archivo! Asegurese de que este se encuentre presente.";
			return;
		}

	//El archivo debería verse: "3 2" si serán 3 vendedores y 2 productos.
   //Introduciendo las variables y cerrando.
	archivoInicial>>N;
	archivoInicial>>M;
	archivoInicial.close();

	cout<<"Vendedores inicializados: "<<N<<endl;
	cout<<"Productos inicializados: "<<M<<endl;

}  //fin leerArchivo

void CargarMatriz(void){ //Init CargarMatriz

			for(i = 0; i < N; i++){
				for(j = 0; j < M; j++){

            	nroVendedor[i] = (i+1);
					cout<<"Vendedor #"<<(i+1)<<", producto #"<<(j+1)<<": ";
					cin>>Ventas[i][j];

				}  //Fin J
			} //Fin I
		} //Fin CargarMatriz

void ImprimirMatriz(int CONDICION){ //Init imprimirMatriz


			//Condicion para imprimir = 1 para transferir las Valores menores a un Vector con el proposito de comparar
         //en una siguiente funcion.
			if(CONDICION == 1){//Init CONDICION

			for(i = 0; i < N; i ++){//Init I
				X = Ventas[i][0];

			 		for(j = 0; j < M; j++){//Init J

					cout<<"("<<Ventas[i][j]<<") ";
					if(Ventas[i][j] < X)X = Ventas[i][j];
					}//Fin J

		Promedios[i] = X;
		cout<<endl;

			}//Fin I


		//En caso de ser falso, imprimir solamente la Matriz.
		}else{//Init ELSE

			for(i = 0; i < N; i ++){
		 		for(j = 0; j < M; j++){
					cout<<"("<<Ventas[i][j]<<") ";
					}//Fin J
			cout<<endl;
			}	//Fin I
		} //Fin Else

	} //Fin ImprimirMatriz

void ImprimirVector(int CONDICION){

     //Condicion para imprimir = 1 para reemplazar los valores menores en el vector por la sumatoria de ventas - nro menor.
		if(CONDICION == 1){
		for(i = 0; i < N; i++){ //Init I
			X = 0;
	 			for(j = 0; j < M; j++){ //Init J
         		if(Ventas[i][j] != Promedios[i])X += Ventas[i][j];
					} //Fin J
				Promedios[i] = X;
				cout<<"  ("<<Promedios[i]<<")"<<endl;
		    	} //Fin I

		//En caso de ser falsa, imprimir solamente.
	     	}else{

				for(i = 0; i < N; i++)cout<<"  ("<<Promedios[i]<<")"<<endl;
		}
}

void Reordenar(){

 //Sacar los Promedios-1 de cada vendedor.
 //SE ENCUENTRA AQUÍ ARRIBA SIGUIENDO EL ORDEN DEL ENUNCIADO.
for(i = 0; i < N; i++)Promedios[i] = (Promedios[i]/(M-1)); 

int K;

	for ( i = 0; i < N; i++){ //Init 1er For

		for (K = i + 1; K < N; K++) {  //init 2do For

			if(Promedios[i] < Promedios[K]){ //init Cond

				X = Promedios[i];
				Promedios[i] = Promedios[K];
				Promedios[K] = X;

       	   X = nroVendedor[i];
        	 	nroVendedor[i] = nroVendedor[K];
       	   nroVendedor[K] = X;


			for( j = 0; j < M; j++){ //init 3er For

				X = Ventas[i][j];
				Ventas[i][j] = Ventas[K][j];
				Ventas[K][j] = X;
				
			}//fin 3er For
		}//fin cond
	 }//fin 2do for
	}//fin 1er for
}//fin Reordenar

void escribirArchivo(){

	//Declarando Archivo para crearse y escribir dentro de él.
	ofstream archivoFinal;

	archivoFinal.open("Reporte.txt", ios::out);
	if(!archivoFinal){
		cout<<"No se pudo crear el archivo."<<endl;
		return;
			}
	
	
	archivoFinal<<"Matriz: "<<endl;
	
	//Escribiendo Matriz Ventas dentro del archivo Reporte.txt
	for(i = 0; i < N; i++){
		archivoFinal<<"-Ventas Vendedor #"<<(nroVendedor[i])<<" -->";
		
		for(j = 0; j < M; j++){
			archivoFinal<<" ("<<Ventas[i][j]<<")";

			}
         archivoFinal<<" ==Promedio--> "<<(Promedios[i])<<endl;
		}
		
	archivoFinal.close();

	}
};

int main(){
	
	Matriz objeto1;
	
	objeto1.leerArchivo();
		cout<<endl;
	objeto1.CargarMatriz();
		cout<<"\n\n==============DATOS INTRODUCIDOS=============="<<endl;
    	cout<<"Matriz: "<<endl;
	objeto1.ImprimirMatriz(1);
		cout<<"Vector: "<<endl;
	objeto1.ImprimirVector(1);
   	cout<<"\n\nLos nuevos datos se encontraran dentro del archivo 'Reporte.txt'"<<endl;
   objeto1.Reordenar();
	objeto1.escribirArchivo();
		cout<<"\nPulse una tecla para salir..."<<endl;
	getch();
	return 0;
	
}
