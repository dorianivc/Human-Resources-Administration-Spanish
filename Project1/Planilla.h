#pragma once
#include "Contrato.h"
class Planilla :
	public Contrato
{
private:
	bool esTemporal;

public:
	Planilla();
	~Planilla();
};

