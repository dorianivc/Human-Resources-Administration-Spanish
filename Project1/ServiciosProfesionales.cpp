#include "ServiciosProfesionales.h"



ServiciosProfesionales::ServiciosProfesionales(string fechaActual, Empleado* newEmpleado, Puesto* newPuesto, string fechaCesantia):Contrato(fechaActual, newEmpleado, newPuesto)
{
	this->fechaCesantia = fechaCesantia;
}

const string ServiciosProfesionales::toString()
{
	stringstream p;
	p << "Fecha de Cesantia: " << fechaCesantia << endl;
	return p.str();
}



ServiciosProfesionales::~ServiciosProfesionales()
{
}
