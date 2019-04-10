#include "ListaContrato.h"



ListaContratos::ListaContratos()
{
	primero = NULL;
	actual = NULL;
}

void ListaContratos::insertar(Contrato * p)
{
	if (primero == NULL) {
		primero = new NodoContrato(p, NULL);
	} else

		primero = new NodoContrato(p, primero);

}

int ListaContratos::cuentaNodos()
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
bool ListaContratos::listaVacia()
{
	return  (primero == NULL) ? true : false;
}

void ListaContratos::actualizarAhorros(int veces)
{
	if (primero != NULL) {
		actual = primero;
		while (actual != NULL) {
			for (int i = 0; i < veces; i++) {
				actual->getInfo()->pagarAhorro();
			}
			actual = actual->getSiguiente();
		}
	}
}

NodoContrato * ListaContratos::getPosicion(int p)
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

string ListaContratos::toString()
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

bool ListaContratos::eliminarIdentificador(string cod)
{
	actual = primero;
	NodoContrato* auxBorrar;
	NodoContrato* anterior = actual;
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

void ListaContratos::pagarAguinaldos(Fecha*p)
{
	if (primero != NULL) {
		actual = primero;
		while (actual != NULL) {
			actual->getInfo()->pagarAguinaldo(p);
			actual = actual->getSiguiente();
		}
	}
}



ListaContratos::~ListaContratos()
{
	actual = primero;
	while (actual != NULL) {
		actual = primero;
		primero = primero->getSiguiente();
		delete actual;
		
	}
}
