#pragma once
#include "Contrato.h"
using namespace std;
class ServiciosProfesionales :
	public Contrato
{private:
	Fecha* fechaCesantia;
public:
	ServiciosProfesionales(Fecha*, Empleado*, Puesto*, Fecha*);
	virtual const string toString();
	virtual const bool esPlanilla();
	~ServiciosProfesionales();
};

