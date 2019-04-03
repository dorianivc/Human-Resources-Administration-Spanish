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


Lista::~Lista()
{
}
