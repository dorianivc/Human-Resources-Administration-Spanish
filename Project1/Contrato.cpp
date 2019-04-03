#include "Contrato.h"



Contrato::Contrato(string fecha, Empleado* empl, Puesto* pues)
{
	this->fecha = fecha;
	empleado = empl;
	puesto = pues;
	
}

Empleado * Contrato::getEmpleado()
{
	return empleado;
}

void Contrato::setEmpleado(Empleado * p)
{
	empleado = p;
}

Puesto * Contrato::getPuesto()
{
	return puesto;
}

void Contrato::setPuesto(Puesto * newPuesto)
{
	puesto = newPuesto;
}

string Contrato::getFecha()
{
	return fecha;
}

const string Contrato::toString()
{
	stringstream p;

	p << "Fecha Inicio de Contrato: " << fecha << endl;
	p <<"Empleado: "<< empleado->toString() << endl;
	p << "Puesto: " << puesto->toString() << endl;
	return p.str();
}



Contrato::~Contrato()
{
	
}
