#include "ListaPuestos.h"



ListaPuestos::ListaPuestos()
{
	primero = NULL;
	actual = NULL;
}

void ListaPuestos::insertar(Puesto * newPuesto)
{
	if (existePosicion(newPuesto->getCodigo()) == false) {
		primero = new NodoPuesto(newPuesto, primero);
		ofstream puestos("Puestos.txt", ios::app);
		if (!puestos.bad() && !puestos.fail()) {
			puestos << newPuesto->getNombre() << "," << newPuesto->getCodigo() << "," << newPuesto->getDescripcion() << "," << newPuesto->getSalarioBase() << ";";

		}
		else {
			cout << "Error al abrir el archivo" << endl;
		}
		puestos.close();
	}
	else {

		cout << "El puesto codigo: " << newPuesto->getCodigo() << " YA EXISTE y corresponde a: " <<endl<< getPosicion(newPuesto->getCodigo())->toString() << endl;
	}
	
}

bool ListaPuestos::insertarSinRegistrar(Puesto * newPuesto)
{
	if (existePosicion(newPuesto->getCodigo()) == false) {
		primero = new NodoPuesto(newPuesto, primero);
		return true;
	}
	else {

		cout << "El puesto codigo: " << newPuesto->getCodigo() << " YA EXISTE y corresponde a: " << endl << getPosicion(newPuesto->getCodigo())->toString() << endl;
	}
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

bool ListaPuestos::existePosicion(int p)
{
	if (getPosicion(p) != NULL) {
		return true;
	}
	else {
		return false;
	}
}



Puesto * ListaPuestos::getPosicion(int cod)
{
	if (primero != NULL) {
		actual = primero;
		while (actual != NULL) {
			if (actual->getInfo()->getCodigo() == cod) {
				return actual->getInfo();
			}
			else {
				actual = actual->getSiguiente();
			}
		} return NULL;
	}
	else return NULL;
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

bool ListaPuestos::eliminarIdentificador(int cod)
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
	while (primero!= NULL) {
		actual = primero;
		primero = primero->getSiguiente();
		delete actual;

	}
}
