#pragma once
#include "Contrato.h"
class ServiciosProfesionales :
	public Contrato
{private:
	string fechaCesantia;
public:
	ServiciosProfesionales();
	~ServiciosProfesionales();
};

