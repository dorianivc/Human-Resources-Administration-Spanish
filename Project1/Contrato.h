#pragma once
#include "Empleado.h"
#include "Herramientas.h"
#include "Puesto.h"
using namespace std;
class Contrato :public NodoLista
{
private:
	string fecha;
	Empleado* empleado;
	Puesto* puesto;
	//Salarios
public:
	Contrato(string, Empleado*, Puesto*);
	Empleado* getEmpleado();
	void setEmpleado(Empleado*);
	Puesto* getPuesto();
	void setPuesto(Puesto*);
	string getFecha();
	~Contrato();
};

