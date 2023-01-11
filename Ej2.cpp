#include<iostream>
#include<conio.h>

/*
Puntero = variable que almacena la direccion de memoria de otra variable
*/

using namespace std;

int main(){
	cout << "**** NUMEROS DE VOCALES EN LA CADENA ****\n\n";
	string cadena;//Limite de la cadena es de 50 caracteres
	int a=0, e=0, i=0, o=0, u=0;
	
 	// getline, lee la cadena
	cout << "Ingrese una cadena: "; getline(cin, cadena);
	cout << "Cadena: " << cadena << endl;
	
	// Direccion de memoria del primer elemento del array
	char *dir_caracteres = &cadena[0]; // 
	
	for(int i=0;i<cadena.length();i++){
		switch(*dir_caracteres){ // valor de la direccion de memoria
				case 'a': a++; break;
				case 'e': e++; break;
				case 'i': i++; break;
				case 'o': o++; break;
				case 'u': u++; break;		
		}
		*dir_caracteres++; // pasamos al siguiente elemento del arreglo
	}
	
	cout << endl;
	cout << "La cadena cuenta con " << a << " vocales a.\n";
	cout << "La cadena cuenta con " << e << " vocales e.\n";
	cout << "La cadena cuenta con " << i << " vocales i.\n";
	cout << "La cadena cuenta con " << o << " vocales o.\n";
	cout << "La cadena cuenta con " << u << " vocales u.\n";
	

	getch();
		
	return 0;
}
