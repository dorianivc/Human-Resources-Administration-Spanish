#include "ServiciosProfesionales.h"



ServiciosProfesionales::ServiciosProfesionales(string fechaActual, Empleado* newEmpleado, Puesto* newPuesto, string fechaCesantia):Contrato(fechaActual, newEmpleado, newPuesto)
{
	this->fechaCesantia = fechaCesantia;
}

const string ServiciosProfesionales::toString()
{
	stringstream p;
	p <<"CONTRATO POR SERVICIOS PROFESIONALES" << endl;
	p << "Fecha de Inicio Contrato: " << getFecha() << endl;
	p << "Fecha de Cesantia: " << fechaCesantia << endl;
	p << getEmpleado()->toString();
	p << getPuesto()->toString() << endl;
	return p.str();
	
}

const bool ServiciosProfesionales::esPlanilla()
{
	return false;
}



ServiciosProfesionales::~ServiciosProfesionales()
{
}
