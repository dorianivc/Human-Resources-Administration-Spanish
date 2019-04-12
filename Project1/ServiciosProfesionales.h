#pragma once
#include "Contrato.h"
using namespace std;
class ServiciosProfesionales :
	public Contrato
{private:
	Fecha* fechaCesantia;
	bool activo;
public:
	ServiciosProfesionales(Fecha*, Empleado*, Puesto*, Fecha*);
	virtual const string toString();
	virtual const bool esPlanilla();
	virtual const bool pagarAhorro();
	virtual const string  pagarAguinaldo(Fecha* p1 = NULL);
	virtual const string otorgarVacaciones(Fecha* p1 = NULL);
	virtual const string getSerializacion();
	double getSalarioBruto(double);
	virtual const void setAhorroEscolar(int);
	virtual const void setAhorroNavidad(int);
	virtual const int calcularCesantia(Fecha*);
	virtual const void viajarEnElTiempo(Fecha*);
	virtual const string cesarEmpleado(Fecha*);
	double calculcarAguinaldo(Fecha*);
	virtual const string imprimirColillaDePago(Fecha*, double p = 0);
	virtual const string retirarAhorros(Fecha*);
	~ServiciosProfesionales();
};

