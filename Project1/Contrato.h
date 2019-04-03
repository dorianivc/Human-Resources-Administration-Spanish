#pragma once
#include "Empleado.h"
#include "Herramientas.h"
#include "Puesto.h"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
class Contrato :public NodoLista
{
private:
	string fecha;
	Empleado* empleado;
	Puesto* puesto;
	double salarioBruto;
	double salarioNeto;//falta de programar en el constructor;
public:
	Contrato(string, Empleado*, Puesto*);
	Empleado* getEmpleado();
	void setEmpleado(Empleado*);
	Puesto* getPuesto();
	void setPuesto(Puesto*);
	string getFecha();
	virtual const string toString();
	~Contrato();
};

