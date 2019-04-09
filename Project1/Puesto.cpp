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

double Puesto::getSalarioBase()
{
	return salarioBase;
}

void Puesto::setSalarioBase(double newSalarioBase)
{
	salarioBase = newSalarioBase;
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

double Puesto::getDeducciones(double p)
{
	double limite = 1200000;
	if (p > limite) {
		double total = p, diferenciaRenta, cargaSocial, ahorro, renta, deduccion;
		cargaSocial = (total*0.09);//Cargas Sociales
		ahorro = (total*0.02);
		diferenciaRenta = (total - limite);
		renta = (diferenciaRenta*0.20);
		deduccion = (cargaSocial + ahorro + renta );
		return deduccion;
	}
	else
	{
		double total = p, cargaSocial, ahorro, deduccion = 0;
		cargaSocial = (total*0.09);//Cargas Sociales
		ahorro = (total*0.02);
		deduccion = cargaSocial + ahorro;
		return deduccion;
	}
}



const string Puesto::identificador()
{
	return codigo;
}

double Puesto::getSalarioDiario()
{
	return (salarioBase/30);
}

Puesto::~Puesto()
{
}
