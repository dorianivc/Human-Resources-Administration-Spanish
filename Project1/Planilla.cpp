#include "Planilla.h"



Planilla::Planilla(string fechaIncio, Empleado* newEmpleado, Puesto* newPuesto,bool temp):Contrato(fechaIncio, newEmpleado, newPuesto)
{
	esTemporal = temp;

}

const bool Planilla::esPlanilla()
{
	return true;
}

const string Planilla::toString()
{
	stringstream p;
	p << "CONTRATO A PLANILLA";
	if (esTemporal) {
		p << " TEMPORAL" << endl;
	}
	else {
		p << " POR TIEMPO INDEFINIDO" << endl;
	}
	p << "Fecha de Inicio Contrato: " << getFecha() << endl;
	p << getEmpleado()->toString();
	if (esTemporal) {
		
		p <<"Tipo de Empleado: " << "EMPLEADO TEMPORAL" << endl;

	}
	else {
		p << "Tipo de Empleado: " << "EMPLEADO EN PROPIEDAD" << endl;
	}
	p << getPuesto()->toString() << endl;
	return p.str();
}


Planilla::~Planilla()
{
}
