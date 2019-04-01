#include "Lista.h"



Lista::Lista()
{
	primero = NULL;
	actual = NULL;
}

void Lista::insertarInicio(Nodo * p)
{
	if (primero != NULL) {
		actual = primero;
		while (actual->getSiguiente() != NULL) {
			actual = actual->getSiguiente();
		}
		actual->setSiguiente(p);
	}
	else
		primero = p;
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
	try {
		if (p <= cuentaNodos() && listaVacia() != false) {
			actual = primero;
			if (p == 1) {
				return actual;
			}
			else

				for (int i = 1; i < p; i++) {
					actual = actual->getSiguiente();
				}
			return actual;
		}
		else throw "Posicion No Existe";
	}
	catch (string p) {
		cout << p << endl;
	}
}

string Lista::toString()
{
	
	if (listaVacia() != true) {
		stringstream p;
		actual = primero;
		while (actual != NULL) {
			p << actual->toString() << endl;;
			actual = actual->getSiguiente();
		}
		return p.str();
	}
	else return "Lista Vacia";
}


Lista::~Lista()
{
}
