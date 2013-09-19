#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace System;
using namespace std;

template <class T>
class Nodo
{
	//no tiene sentido que los declare privados
	//seran accesibles por cualquier elemento de la lista
	public:
		T info;
		Nodo<T> *sig;//tiene que ser el nodo siguiente al que apunta
		Nodo(){ sig = NULL; }
		Nodo(T dato){ info = dato; sig = NULL; }
		//no necesitamos un destructor porque no hay un new de por medio.
};

template <class T>
class Lista
{
	private:
		Nodo<T> *inicio;
	public: 
		Lista() { inicio = NULL; }
	//Cada vez que le inserte un dato a esta lista, se va a hacer un new.
	//Aqui ocupo un destructor que libere todos los nodos de la lista.
	~Lista() { /*pendiente*/ }
	void AgregarAInicio(T dato);
	//Ademas ocupo los metodos para implementar las operaciones de la lista.
};
void Lista::insertar()
{
//checar presentacion
}

int main ()
{

}
