#include "Puesto.h"



Puesto::Puesto(string nom, string cod, string desc)
{
	nombre = nom;
	codigo = cod;
	descripcion = desc;
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

Puesto::~Puesto()
{
}
