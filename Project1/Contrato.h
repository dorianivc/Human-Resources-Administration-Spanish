#pragma once
#include "Empleado.h"
#include "Herramientas.h"
#include "Puesto.h"
#include <string>
#include <sstream>
#include <iostream>
#include "Fecha.h"
using namespace std;
class Contrato 
{
private:
	Fecha* fecha;
	Empleado* empleado;
	Puesto* puesto;
public:
	Contrato(Empleado*, Puesto*, Fecha*);
	Empleado* getEmpleado();
	void setEmpleado(Empleado*);
	Puesto* getPuesto();
	void setPuesto(Puesto*);
	string getFechaToString();
	Fecha* getFecha();
	virtual const bool pagarAhorro() = 0;
	virtual const bool esPlanilla() = 0;
	virtual const string toString();
	virtual const void pagarAguinaldo(Fecha*) = 0;
	virtual const void otorgarVacaciones(Fecha*) = 0;
	string verColillaPago();
	virtual const string identificador();

	~Contrato();
};

