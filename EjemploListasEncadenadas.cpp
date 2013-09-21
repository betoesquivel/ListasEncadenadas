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
		void AgregarAlFinal(T dato);
		bool BorrarInicio(T &dato);
		bool BorrarFinal(T &dato);
		void despliega();
	//Ademas ocupo los metodos para implementar las operaciones de la lista.
};
template <class T>
void Lista<T>::AgregarAInicio(T dato)
{
	Nodo<T> *aux = new Nodo<T> (dato); 	
	/*para ver si un apuntador no es null y no se acabo la memoria */
	if (aux != NULL)
	{
		aux->sig = inicio;
		inicio = aux;
	}
	
}
template <class T>
void Lista<T>::AgregarAlFinal(T dato)
{
	Nodo<T> *aux;
	Nodo<T> *temp = new Nodo<T> (dato);
	aux = inicio;
	if(aux != NULL) 
	{
		while (aux->sig != NULL)
		{
			aux = aux->sig;
		}
		aux->sig = temp;
	}
	else
		inicio = temp;
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
template <class T>
bool Lista<T>::BorrarInicio(T &dato)
{  
	Nodo<T> *aux = inicio;
	if(aux == NULL)
		return false;
	inicio = aux->sig;
	dato = aux->info;
	delete aux;
	return true;
}
template <class T>
bool Lista<T>::BorrarFinal(T &dato)
{  
	Nodo<T> *aux = inicio;
	while( (aux->sig)->sig != NULL)
	{
		aux = aux->sig;
	}
	dato = (aux->sig)->info;
	delete aux->sig;
	aux->sig = NULL;
	//Problema si la lista esta vacia.
	//Buscar como validar esto.
}


int main ()
{
	int x; 
	Lista<int> l;
	l.AgregarAInicio(36);	
	l.AgregarAInicio(55);	
	l.AgregarAInicio(98);	
	l.AgregarAInicio(3);	
	for (int i = 1; i < 100; i++)
		l.AgregarAInicio(i);
	l.despliega();
	l.BorrarInicio(x);
	l.BorrarInicio(x);
	l.despliega();
	l.AgregarAlFinal(0);	
	l.despliega();
	l.BorrarFinal(x);
	l.despliega();
}
