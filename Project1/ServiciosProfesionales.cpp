#include "ServiciosProfesionales.h"



ServiciosProfesionales::ServiciosProfesionales(Fecha* fechaActual, Empleado* newEmpleado, Puesto* newPuesto, Fecha* fechaCesantia):Contrato( newEmpleado, newPuesto, fechaActual)
{
	this->fechaCesantia = fechaCesantia;
}

const string ServiciosProfesionales::toString()
{
	stringstream p;
	p <<"CONTRATO POR SERVICIOS PROFESIONALES" << endl;
	p << "Fecha de Inicio Contrato: " << getFechaToString() << endl;
	p << "Fecha de Cesantia: " << fechaCesantia << endl;
	p << getEmpleado()->toString();
	p << getPuesto()->toString() << endl;
	return p.str();
	
}

const bool ServiciosProfesionales::esPlanilla()
{
	return false;
}

const bool ServiciosProfesionales::pagarAhorro()
{
	return false;
}



ServiciosProfesionales::~ServiciosProfesionales()
{
}
