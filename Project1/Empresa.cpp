#include "Empresa.h"




Empresa::Empresa(string nombre, string direccion, string telefono , string FechaActual)
{
	this->nombre = nombre;
	this->direccion = direccion;
	this->telefono = telefono;
	this->fechaActual = FechaActual;
	listaEmpleados = new Lista();
	ListaPuestos = new Lista();
}

Empresa::Empresa(Empresa & p)
{
	nombre = p.getNombre();
	direccion = p.getDireccion();
	telefono = p.getTelefono();
	fechaActual = p.getFechaActual();
	listaEmpleados = p.getListaEmpleados();
	ListaPuestos = p.getListaPuestos();
}

void Empresa::addPuesto(string nombre, string codigo, string descripcion, double salarioBase)
{
	ListaPuestos->insertar(new Puesto(nombre, codigo, descripcion, salarioBase));
}

void Empresa::addPuesto(Puesto * newPuesto)
{
	ListaPuestos->insertar(newPuesto);
}

bool Empresa::eliminarPuesto(string cod)
{
	return(ListaPuestos->eliminarIdentificador(cod));
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

string Empresa::getFechaActual()
{
	return fechaActual;
}

Lista * Empresa::getListaEmpleados()
{
	return listaEmpleados;
}

void Empresa::setListaEmpleados(Lista * newListaEmpleados)
{
	listaEmpleados = newListaEmpleados;
}

Lista * Empresa::getListaPuestos()
{
	return ListaPuestos;
}

void Empresa::setListaPuestos(Lista * newListaPuestos)
{
	ListaPuestos = newListaPuestos;
}

void Empresa::operator=(Empresa & p)
{
	nombre = p.getNombre();
	direccion = p.getDireccion();
	telefono = p.getTelefono();
	fechaActual = p.getFechaActual();
	listaEmpleados = p.getListaEmpleados();
	ListaPuestos = p.getListaPuestos();
}

string Empresa::toString()
{
	stringstream p;
	p << "Empresa: " << nombre << endl;
	p << "Direccion: " << direccion << endl;
	p << "Telefono: " << telefono << endl;
	p << "Fecha Actual" << fechaActual << endl;
	p << "------------------------------" << endl;
	p << "Puestos: " << endl;
	p << ListaPuestos->toString() << endl;
	p << "------------------------------" << endl;
	p << "Lista de Empleados: " << "              " << "Total: " << listaEmpleados->cuentaNodos() << endl;
	p << listaEmpleados->toString() << endl;
	p << "       ---Fin---     " << endl;
	return p.str();
}

Empresa::~Empresa()
{
	delete listaEmpleados;
	delete ListaPuestos;
}
