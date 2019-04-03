#pragma once
#include "Contrato.h"
using namespace std;
class ServiciosProfesionales :
	public Contrato
{private:
	string fechaCesantia;
public:
	ServiciosProfesionales(string, Empleado*, Puesto*, string);
	virtual const string toString();
	virtual const bool esPlanilla();
	~ServiciosProfesionales();
};

