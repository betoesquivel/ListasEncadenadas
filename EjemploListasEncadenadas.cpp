#include <iostream>

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
	~Lista() 
	{  
		Nodo<T> *aux = inicio;
		while(aux != NULL)
		{
			inicio = aux->sig;
			delete aux;
			aux = inicio;
		}
		
	}
	void AgregarAInicio(T dato);
	void despliega();
	//Ademas ocupo los metodos para implementar las operaciones de la lista.
};
template <class T>
void Lista<T>::AgregarAInicio(T dato)
{
//checar presentacion
	Nodo<T> *aux = new Nodo<T> (dato); 	
/*para ver si un apuntador no es null y no se acabo la memoria */
	if (aux != NULL)
	{
		aux->sig = inicio;
		inicio = aux;
	}
	
}
template <class T>
void Lista<T>::despliega()
{
	Nodo<T> *aux = inicio;
	while(aux != NULL)
	{
		cout<<aux->info<<endl;
		aux = aux->sig;
	}
}

int main ()
{
	Lista<int> l;
	l.AgregarAInicio(36);	
	l.AgregarAInicio(55);	
	l.AgregarAInicio(98);	
	l.AgregarAInicio(3);	
	l.despliega();
}
