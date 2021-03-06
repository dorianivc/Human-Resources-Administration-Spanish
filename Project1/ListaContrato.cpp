#include "ListaContrato.h"



ListaContratos::ListaContratos()
{
	primero = NULL;
	actual = NULL;
}

void ListaContratos::viajarEnElTiempo(Fecha * fechaAViajar)
{
	if (primero != NULL) {
		actual = primero;
		while (actual != NULL) {
			actual->getInfo()->viajarEnElTiempo(fechaAViajar);
			actual = actual->getSiguiente();
		}
	}
}

bool ListaContratos::insertarSinRegistrar(Contrato * newContrato)
{
	if (existePosicion(newContrato->getEmpleado()->getCedula()) == false) {
		primero = new NodoContrato(newContrato, primero);
		return true;
	}
	else {
		cout << "El empleado con cedula: " << newContrato->getEmpleado()->getCedula() << " YA SE ENCUENTRA CONTRATADO y corresponde a: " << endl;
		cout << getPosicion(newContrato->getEmpleado()->getCedula())->toString() << endl;

	}
}

void ListaContratos::insertar(Contrato * p)
{
	if (existePosicion(p->getEmpleado()->getCedula())==false) {
		if (primero == NULL) {
			primero = new NodoContrato(p, NULL);
		}
		else {

			primero = new NodoContrato(p, primero);
		}
		if (p->esPlanilla()) {
			ofstream listaEmpleados;
			listaEmpleados.open("ListaEmpleadosPlanilla.txt", ios::app);
			if ( !listaEmpleados.fail()) {
				listaEmpleados << p->getSerializacion();
				

			}
			else {
				cout << "Error abriendo el archivo ListaEmpleadosPlanilla.txt" << endl;
				system("pause");
			}
			listaEmpleados.close();
		}
		else {
			ofstream listaServProf("ListaEmpleadosServiciosProfesionales.txt", ios::app);
			if (!listaServProf.fail()) {
				listaServProf << p->getSerializacion();
				
			}
			else {
				cout << "Error abriendo el archivo ListaEmpleadosServiciosProfesionales.txt " << endl;
				system("pause");
			}
			listaServProf.close();
		}
	}
	else {
		cout << "El empleado con cedula: " << p->getEmpleado()->getCedula() << " YA SE ENCUENTRA CONTRATADO" << endl;
		cout << getPosicion(p->getEmpleado()->getCedula())->toString() << endl;

	}

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

Contrato * ListaContratos::getPosicion(int p)
{
	
	if (primero != NULL) {
		actual = primero;
		while (actual != NULL) {
			if (actual->getInfo()->getEmpleado()->getCedula() == p) {
				return actual->getInfo();
			}
			else {
				actual = actual->getSiguiente();
			}
		} 
		
		return NULL;
	}
	else return NULL;
	
}

bool ListaContratos::existePosicion(int p)
{
	if (getPosicion(p) != NULL) {
		return true;
	}
	else {
		return false;
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

string ListaContratos::pagarSalarios(Fecha* fechaActual)
{
	stringstream p;
	if (primero != NULL) {
		actual = primero;
		while (actual != NULL) {
			p << actual->getInfo()->imprimirColillaDePago(fechaActual) << endl;
			actual = actual->getSiguiente();
		}
	}
	ofstream reporteSalarios("ReporteSalarios.txt", ios::app);
	if (!reporteSalarios.bad()) {
		reporteSalarios << p.str() << endl;
	}
	else {
		cout << "Error creando el archivo:  Reporte de Salarios" << endl;
	}
	reporteSalarios.close();
	return p.str();
}

string ListaContratos::otorgarVacaciones(Fecha * fechita, int ced)
{
	stringstream p;
	if (primero != NULL) {
		actual = primero;
		while (actual != NULL) {
			if (actual->getInfo()->getEmpleado()->getCedula() == ced) {
				p << actual->getInfo()->otorgarVacaciones(fechita);
				return p.str();
			}
			else {
				actual = actual->getSiguiente();
			}
		}
		p << "Empleado no existe" << endl;
		return p.str();
	}
	else {
		p << "Empleado no existe---> Lista Vacia" << endl;
		return p.str();
	}
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

string ListaContratos::pagarAguinaldos(Fecha*p)
{
	stringstream k;
	if (primero != NULL) {
		k << "Pagando aguinaldos a la fecha de: " << p->toStringFecha() << endl;
		actual = primero;
		while (actual != NULL) {
			k << actual->getInfo()->pagarAguinaldo(p) << endl;
			actual = actual->getSiguiente();
		}
	}
	else {
		k << "No posee empleados para realizar pago de aguinaldos" << endl;
	}

	return k.str();
}



ListaContratos::~ListaContratos()
{
	actual = primero;
	while (primero != NULL) {
		actual = primero;
		primero = primero->getSiguiente();
		delete actual;
		
	}
}
