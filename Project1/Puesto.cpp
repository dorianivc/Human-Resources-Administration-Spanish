#include "Puesto.h"



Puesto::Puesto(string nom, string cod, string desc, double newSalarioBase)
{
	nombre = nom;
	codigo = cod;
	descripcion = desc;
	salarioBase = newSalarioBase;
}

string Puesto::getNombre()
{
	return nombre;
}

void Puesto::setNombre(string nom)
{
	nombre = nom;
}

string Puesto::getCodigo()
{
	return codigo;
}

void Puesto::setCodigo(string cod)
{
	codigo = cod;
}

string Puesto::getDescripcion()
{
	return descripcion;
}

void Puesto::setDescripcion(string desc)
{
	descripcion = desc;
}

const string Puesto::toString()
{
	stringstream p;
	p << "Nombre del Puesto: " << nombre << endl;
	p << "Codigo del Puesto: " << codigo << endl;
	p << "Descripcion del Puesto: " << descripcion << endl;
	p << "Salario Base: " << (int)salarioBase << endl;
	return p.str();
}

Puesto::~Puesto()
{
}
