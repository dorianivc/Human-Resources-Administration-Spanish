#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include "Herramientas.h"
using namespace std;
class Salario
{
private:
	double salarioBase;
	double ahorroEscolarxQuin;//monto de deduccion quincenal
	double ahorroNavidadxQuin;//monto de deduccion quincenal
	bool salarioMensual;
	double salarioBruto;
public:
	Salario(double);
	double getSalarioBase();
	double getAhorroEscolarxQuin();
	double getAhorroNavidadxQuin();
	void setSalarioBase(double);
	void setAhorroEscolar(double);
	void setAhorroNavidad(double);
	//string mostrarInfoSalario();
	int getSalarioNeto();
	//string mostrarDeducciones();
	double getDeducciones();
	double getSalarioBruto(double=0);
	string proximaFechaPago();


	~Salario();
};

