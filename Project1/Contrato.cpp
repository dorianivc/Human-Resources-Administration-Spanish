#include "Contrato.h"



Contrato::Contrato(string ced, string nom, string apell, string fechaN, string dir, string telefono, string puesto, string desc, double monto):Empleado(ced, nom, apell, fechaN, dir, telefono)
{
	fecha = Herramientas::obtenerFecha();
	this->puesto = puesto;
	descripcion = desc;
	salario = new Salario(monto);
}

string Contrato::getFecha()
{
	return fecha;
}

string Contrato::getPuesto()
{
	return puesto;
}

string Contrato::getDescripcion()
{
	return descripcion;
}

void Contrato::setPuesto(string p)
{
	puesto = p;
}

void Contrato::setDescripcion(string j)
{
	descripcion = j;
}

Salario * Contrato::getSalario()
{
	return salario;
}

void Contrato::setSalario(Salario *p)
{
	salario = p;
}


Contrato::~Contrato()
{
	delete salario;
}
