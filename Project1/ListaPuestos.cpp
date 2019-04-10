#include "ListaPuestos.h"



ListaPuestos::ListaPuestos()
{
	primero = NULL;
	actual = NULL;
}

void ListaPuestos::insertar(Puesto * newPuesto)
{
	primero = new NodoPuesto(newPuesto, primero);
}

int ListaPuestos::cuentaNodos()
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

bool ListaPuestos::listaVacia()
{
	return  (primero == NULL) ? true : false;
}

NodoPuesto * ListaPuestos::getPosicion(int p)
{
	actual = primero;
	int can = 0;
	if (listaVacia() == false && p <= cuentaNodos()) {
		while (actual != NULL)
		{
			can++;
			actual = actual->getSiguiente();
			if (p == can) {
				return actual;
			}
		}
	}
	else {
		return NULL;
	}
}

string ListaPuestos::toString()
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

bool ListaPuestos::eliminarIdentificador(string cod)
{
	actual = primero;
	NodoPuesto* auxBorrar;
	NodoPuesto* anterior = actual;
	auxBorrar = actual;

	if (primero != NULL) {

		while (auxBorrar != NULL && auxBorrar->getInfo()->getCodigo() != cod) {
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


ListaPuestos::~ListaPuestos()
{
	actual = primero;
	while (actual != NULL) {
		actual = primero;
		primero = primero->getSiguiente();
		delete actual;

	}
}
