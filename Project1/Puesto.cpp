#include "Puesto.h"



Puesto::Puesto(string nom, string cod, string desc, double newSalarioBase)
{
	nombre = nom;
	codigo = cod;
	descripcion = desc;
	salarioBase = newSalarioBase;
	salarioBruto = salarioBase;
	ahorroNavidad = 0;
	ahorroSalEscolar = 0;

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
		deduccion = (cargaSocial + ahorro + renta + ahorroNavidad + ahorroSalEscolar);
		return deduccion;
	}
	else
	{
		double total = p, cargaSocial, ahorro, deduccion = 0;
		cargaSocial = (total*0.09);//Cargas Sociales
		ahorro = (total*0.02);
		deduccion = cargaSocial + ahorro+ ahorroNavidad + ahorroSalEscolar;
		return deduccion;
	}
}

double Puesto::getSalarioBruto()
{
	return salarioBruto;
}

void Puesto::addSalario(double p)
{
	salarioBruto = salarioBruto + p;
}

double Puesto::getSalarioNeto()
{
	double salarioNetop = 0;
	salarioNetop = salarioBruto - getDeducciones(salarioBruto);
	return salarioNetop;

}

double Puesto::getAhorroNavidad()
{
	return ahorroNavidad;
}

void Puesto::setAhorroNavidad(double newAhorro)
{
	ahorroNavidad = newAhorro;
}

double Puesto::getAhorroSalEscolar()
{
	return ahorroSalEscolar;
}

void Puesto::setAhorroSalEscolar(double p)
{
	ahorroSalEscolar = p;
}

Puesto::~Puesto()
{
}
