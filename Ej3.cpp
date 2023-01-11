#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

struct Nodo {
	int dato; // Valor que almacena el nodo
	Nodo *siguiente; // Se guarda el puntero del siguiente (la referencia)
};

void agregarPila(Nodo *&pila, int n) {
	Nodo *nuevo_nodo = new Nodo();//Reserva memoria para un nodo
	nuevo_nodo -> dato = n;	// Agregar el dato al nodo
	nuevo_nodo -> siguiente = pila; // Igualar el puntero a pila
	pila = nuevo_nodo; // Igualar pila al nuevo nodo
}

int main(){
	cout << "**** PILA ****\n";
	Nodo *pila = NULL; // Creacion de la pila
	
	int opc;//Opcion
	//Menu
	do {
		cout << "\nELIJA SU OPCION\n";
		cout << "a. Insertar un elemento a la pila (1)\n";
		cout << "b. Mostrar todos los elementos de la pila. (2)\n";
		cout << "c. Salir. (3)\n";
		cout << "Opcion: "; cin >> opc;
		
		switch(opc){
			case 1:
				cout << "Igrese un numero para agregar: ";
				int num; cin >> num;
				agregarPila(pila, num); // Agrega un elemento a la pila
				cout << "\nSe agrego " << num << " correctamente.\n";
				break;
			case 2:
				cout << "\nElementos de su pila ";
				cout << "[ ";
				// direccion memoria aux = direccion de memoria pila
				Nodo *aux; aux = pila; // Capturando la direccion de memoria
				while(aux != NULL) { // Recorremos toda la pila
						cout << aux->dato << " "; // Mostramos el dato
						aux = aux->siguiente; // Avanzamos de posicion
				}
				cout << "]\n"; break;
			case 3:
				cout << "Adios!.\n"; break;
			default: cout << "Opcion no valida.\n"; break;
		}
	} while(opc!=3);
		
	getch();
		
	return 0;
}
