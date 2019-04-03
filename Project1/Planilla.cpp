#include "Planilla.h"



Planilla::Planilla(string fechaIncio, Empleado* newEmpleado, Puesto* newPuesto,bool temp):Contrato(fechaIncio, newEmpleado, newPuesto)
{
	esTemporal = temp;
}

const string Planilla::toString()
{
	stringstream p;
	if (esTemporal) {
		p << "EMPLEADO TEMPORAL" << endl;

	}
	else {
		p << "EMPLEADO EN PROPIEDAD" << endl;
	}
	return p.str();
}


Planilla::~Planilla()
{
}
