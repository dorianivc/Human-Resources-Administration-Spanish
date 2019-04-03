#pragma once
#include "Contrato.h"
class Planilla :
	public Contrato
{
private:
	bool esTemporal;

public:
	Planilla(string, Empleado*, Puesto*, bool);
	virtual const bool esPlanilla();
	virtual const string toString();
	~Planilla();
};

