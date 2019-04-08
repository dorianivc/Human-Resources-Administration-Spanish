#include "Lista.h"



Lista::Lista()
{
	primero = NULL;
	actual = NULL;
}

void Lista::insertar(NodoLista * p)
{
	if (primero == NULL) {
		primero = new Nodo(p, NULL);
	} else

		primero = new Nodo(p, primero);

}

int Lista::cuentaNodos()
{
	actual = primero;
	int can = 0;
	while (actual != NULL)
	{
		can++;
		actual = actual->getSiguiente();
	}
	return can;
}
bool Lista::listaVacia()
{
	return  (primero == NULL) ? true : false;
}

Nodo * Lista::getPosicion(int p)
{
	actual = primero;
	int can = 0;
	if (listaVacia() == false && p<=cuentaNodos()) {
	while (actual != NULL)
	{
		can++;
		actual = actual->getSiguiente();
		if (p == can) {
			return actual;
		}
	}
	}
}

string Lista::toString()
{
	
	if (listaVacia() != true) {
		stringstream p;
		actual = primero;
		int i = 0;
		while (actual != NULL) {
			i++;
			p << "Nodo # " << i << endl;
			p << actual->toString() << endl;
			actual = actual->getSiguiente();
		}
		return p.str();
	}
	else return "Lista Vacia";
}

bool Lista::eliminarIdentificador(string cod)
{
	actual = primero;
	Nodo* auxBorrar;
	Nodo* anterior = actual;
	auxBorrar = actual;

	if (primero != NULL) {
		
		while (auxBorrar != NULL && auxBorrar->getInfo()->identificador()!= cod) {
			anterior = actual;
			auxBorrar = auxBorrar->getSiguiente();
		}
		if (auxBorrar == NULL) {
			cout << "El elemento no existe" << endl;
			return false;
		}
		else
			if (anterior == NULL) {
				actual = actual->getSiguiente();
				delete auxBorrar;
				return true;
			}
			else
			{
				actual->setSiguiente(auxBorrar->getSiguiente());
				delete auxBorrar;
				return true;
			}
	}
	else return false;
}



Lista::~Lista()
{
	actual = primero;
	while (actual != NULL) {
		actual = primero;
		primero = primero->getSiguiente();
		delete actual;
		
	}
}
