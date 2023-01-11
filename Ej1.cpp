#include<iostream>
#include<conio.h>

/*
Puntero = variable que almacena la direccion de memoria de otra variable
*/

using namespace std;

int main(){
	cout << "**** MOSTRANDO ELEMENTOS DE UN ARRAY (CON PUNTEROS) ****\n\n";
	int cantidadNumeros = 10;
	int array[cantidadNumeros];
	
	// Direccion de memoria del primer elemento del array
	int *dir_array = array; // *dir_array = &array[0]
	
	// Ingreso de numeros al arreglo
	for(int i=0;i<cantidadNumeros;i++){
		cout << (i+1) << ") Ingrese numero: "; cin >> array[i];
	}
	
	
	cout<<endl;
	cout << "LOS NUMEROS IMPARES SON:\n";
	for(int i=0;i<cantidadNumeros;i++){
		// *dir_array indica el valor dentro de esa direccion de memoria
		if(*dir_array % 2!=0){ 
			cout << "Numero " << *dir_array << endl; // Se muestra el valor 
			cout << "Direccion de memoria: " << dir_array << endl;// Se muestra la direccion
			cout << endl;	
		}
		// *dir_array aumenta en 4 bytes, es decir a la siguiente pos del arreglo
		*dir_array++;
	}
	
	getch();
		
	return 0;
}
