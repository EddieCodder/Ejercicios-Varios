#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

struct Nodo {
	string nombre;
	string apellido;
	int edad; // Valor que almacena el nodo
	string dni;
	string telefono;
	
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

void insertarCola(Nodo *&frente, Nodo *&fin, string nombre, string apellido, int edad, string dni, string telefono) {
	Nodo *nuevo_nodo = new Nodo();//Reserva memoria para un nodo
	// Agregando datos al nodo
	nuevo_nodo -> nombre = nombre;
	nuevo_nodo -> apellido = apellido;
	nuevo_nodo -> edad = edad;	
	nuevo_nodo -> dni = dni;
	nuevo_nodo -> telefono = telefono;
	
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
	cout << "**** COLA DE CLIENTES DEL BANCO ****\n";
	int opc;//Opcion
	
	// Variables de datos del cliente
	string nombre;
	string apellido;
	int edad;
	//string porque probablemente no se realizaran operaciones con esos valores
	string dni;
	string telefono;
	
	//Menu
	do {
		cout << "\nELIJA SU OPCION\n";
		cout << "a. Insertar un elemento a la cola (1)\n";
		cout << "b. Mostrar todos los elementos de la cola. (2)\n";
		cout << "c. Salir. (3)\n";
		cout << "Opcion: "; cin >> opc;
		
		switch(opc){
			case 1:
				cout << "\nDATOS DEL CLIENTE" << endl;
				cout << "Nombre: ";
				//cin captura la cadena hasta un espacio en blanco
				cin >> nombre;
				cout << "Appellido: ";
				cin >> apellido;
				cout << "Edad: ";
				cin >> edad;
				cout << "DNI: ";
				cin >> dni;
				cout << "Telefono: ";
				cin >> telefono;
				
				insertarCola(frente, fin, nombre, apellido, edad, dni, telefono); // Agrega un elemento a la pila
				cout << "\nSe agrego a " << nombre << " " << apellido << " correctamente.\n";
				break;
			case 2:
				cout << "\nCLIENTES EN COLA\n";
				
				// direccion memoria aux = direccion de memoria frente de la cola
				Nodo *aux; aux = frente; // Capturando la direccion de memoria
				while(aux != NULL) { // Recorremos toda la cola
					cout << "\n________________\n\n";//Separacion
					cout << aux->nombre << " "; // Mostramos el dato
					cout << aux->apellido << "\n"; 
					cout << "Edad: "<<aux->edad << "\n";
					cout << "DNI: "<<aux->dni << "\n";
					cout << "Telefono: "<<aux->telefono;
					aux = aux->siguiente; // Avanzamos de posicion
				}
				cout << "\n________________\n"; break;
			case 3:
				cout << "Adios!.\n"; break;
			default: cout << "Opcion no valida.\n"; break;
		}
	} while(opc!=3);
		
	getch();
		
	return 0;
}
