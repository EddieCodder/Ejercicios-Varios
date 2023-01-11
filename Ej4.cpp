#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;


struct Nodo {
	int dato; // Valor que almacena el nodo
	Nodo *siguiente; // Se guarda el puntero del siguiente (la referencia)
};

// Variables generales de direcciones 
Nodo *frente = NULL; // Frente en null (cuando la cola no existe)
Nodo *fin = NULL; // Fin en null (cuando la cola no existe)

// Determina si la cola esta vacia
bool cola_vacia(Nodo *frente) {
	// Si el frente es null no hay elementos
	return (frente == NULL)? true : false;
}

void insertarCola(Nodo *&frente, Nodo *&fin, int n) {
	Nodo *nuevo_nodo = new Nodo();//Reserva memoria para un nodo
	nuevo_nodo -> dato = n;	// Agregar el dato al nodo
	nuevo_nodo -> siguiente = NULL; // Igualar el puntero a NULL
	
	if(cola_vacia(frente)){
		frente = nuevo_nodo;
	}
	else {// La referencia del siguiente del final apunta al nuevo nodo
		fin -> siguiente = nuevo_nodo; 
	}
	fin = nuevo_nodo; // El nuevo nodo siempre es el final
}

int main(){
	cout << "**** COLA ****\n";
	int opc;//Opcion
	
	//Menu
	do {
		cout << "\nELIJA SU OPCION\n";
		cout << "a. Insertar un elemento a la cola (1)\n";
		cout << "b. Mostrar todos los elementos de la cola. (2)\n";
		cout << "c. Salir. (3)\n";
		cout << "Opcion: "; cin >> opc;
		
		switch(opc){
			case 1:
				cout << "Igrese un numero para agregar: ";
				int num; cin >> num;
				insertarCola(frente, fin, num); // Agrega un elemento a la pila
				cout << "\nSe agrego " << num << " correctamente.\n";
				break;
			case 2:
				cout << "\nElementos de su cola ";
				cout << "[ ";
				// direccion memoria aux = direccion de memoria frente de la cola
				Nodo *aux; aux = frente; // Capturando la direccion de memoria
				while(aux != NULL) { // Recorremos toda la cola
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
