#pragma once
#include "Empleado.h"
#include "Herramientas.h"
#include "Salario.h"
using namespace std;
class Contrato :public Empleado
{
private:
	string fecha;
	string puesto;
	string descripcion;
	Salario* salario;
public:
	Contrato(string, string, string, string, string, string, string, string, double);
	string getFecha();
	string getPuesto();
	string getDescripcion();
	void setPuesto(string);
	void setDescripcion(string);
	Salario* getSalario();
	void setSalario(Salario*);
	~Contrato();
};

