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
protected:
	Fecha* fecha;
	Empleado* empleado;
	Puesto* puesto1;
public:
	Contrato(Empleado*, Puesto*, Fecha*);
	Empleado* getEmpleado();
	virtual const void viajarEnElTiempo(Fecha*)=0;
	void setEmpleado(Empleado*);
	Puesto* getPuesto();
	void setPuesto(Puesto*);
	string getFechaToString();
	Fecha* getFecha();
	virtual const bool pagarAhorro() = 0;
	virtual const bool esPlanilla() = 0;
	virtual const string toString()=0;
	virtual const string  pagarAguinaldo(Fecha*) = 0;
	virtual const string  otorgarVacaciones(Fecha*) = 0;
	virtual const string imprimirColillaDePago(Fecha*, double p = 0)=0;
	virtual const string retirarAhorros(Fecha*) = 0;
	virtual const int calcularCesantia(Fecha*) = 0;
	virtual const string cesarEmpleado(Fecha*)=0;
	string verColillaPago();
	virtual const string identificador();

	~Contrato();
};

