#include "Empresa.h"




ListaPuestos * Empresa::getListaPuestos()
{
	return puestos;
}

void Empresa::setListaPuesto(ListaPuestos *p)
{
	puestos = p;
}

Empresa::Empresa(string nombre, string direccion, string telefono , Fecha* pfecha)
{
	this->nombre = nombre;
	this->direccion = direccion;
	this->telefono = telefono;
	this->fechaActual = pfecha;
	listaEmpleados = new ListaContratos();
	puestos = new ListaPuestos();
}

Empresa::Empresa(Empresa & p)
{
	nombre = p.getNombre();
	direccion = p.getDireccion();
	telefono = p.getTelefono();
	fechaActual = p.getFechaActual();
	listaEmpleados = p.getListaEmpleados();
	puestos = p.getListaPuestos();
}

void Empresa::viajarAdelanteEnELTiempo(Fecha * fechaFutura)
{
	int DiasAViajar = fechaActual->Distancia(fechaActual, fechaFutura);
	int mesesAViajar = 0;
	if(DiasAViajar>0){

		if (DiasAViajar > 29) {
			mesesAViajar = (DiasAViajar / 30);
			if (listaEmpleados->listaVacia() != true) {
				listaEmpleados->actualizarAhorros(mesesAViajar);
			}
		}
	}
}

void Empresa::addPuesto(string nombre, string codigo, string descripcion, double salarioBase)
{
	puestos->insertar(new Puesto(nombre, codigo, descripcion, salarioBase));
}

void Empresa::pagarAguinaldo()
{
	if (listaEmpleados->listaVacia() == false) {
		listaEmpleados->pagarAguinaldos(fechaActual);
	}
}

void Empresa::addPuesto(Puesto * newPuesto)
{
	puestos->insertar(newPuesto);
}

void Empresa::setFecha(Fecha * newFecha)
{
	fechaActual = newFecha;
}

void Empresa::addContrato(Contrato * p)
{
	listaEmpleados->insertar(p);
}

bool Empresa::eliminarPuesto(string cod)
{
	return(puestos->eliminarIdentificador(cod));
}

string Empresa::getNombre()
{
	return nombre;
}

string Empresa::getDireccion()
{
	return direccion;
}

void Empresa::setDireccion(string newDireccion)
{
	direccion = newDireccion;
}

string Empresa::getTelefono()
{
	return telefono;
}

void Empresa::setTelefono(string newTelefono)
{
	telefono = newTelefono;
}

Fecha* Empresa::getFechaActual()
{
	return fechaActual;
}

string Empresa::fechaToString()
{
	return fechaActual->toStringFecha();
}

ListaContratos * Empresa::getListaEmpleados()
{
	return listaEmpleados;
}

void Empresa::setListaEmpleados(ListaContratos * newListaEmpleados)
{
	listaEmpleados = newListaEmpleados;
}



void Empresa::operator=(Empresa & p)
{
	nombre = p.getNombre();
	direccion = p.getDireccion();
	telefono = p.getTelefono();
	fechaActual = p.getFechaActual();
	listaEmpleados = p.getListaEmpleados();
	puestos = p.getListaPuestos();
}

string Empresa::toString()
{
	stringstream p;
	p << "Empresa: " << nombre << endl;
	p << "Direccion: " << direccion << endl;
	p << "Telefono: " << telefono << endl;
	p << "Fecha Actual: " << fechaActual->toStringFecha() << endl;
	p << "------------------------------" << endl;
	p << "Puestos: " << endl;
	if (puestos != NULL) {
		p << puestos->toString() << endl;
	}
	p << "------------------------------" << endl;
	p << "Lista de Empleados: " << "              " << "Total: " << listaEmpleados->cuentaNodos() << endl;
	if (listaEmpleados != NULL) {
		p << listaEmpleados->toString() << endl;
	}
	p << "       ---Fin---     " << endl;
	return p.str();
}

Empresa::~Empresa()
{
	delete listaEmpleados;
	delete puestos;
}
