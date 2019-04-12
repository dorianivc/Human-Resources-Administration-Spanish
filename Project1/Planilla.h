#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include "Fecha.h"
#include "Contrato.h"
class Planilla :
	public Contrato
{
private:
	bool esTemporal;
	bool activo;
	Fecha* fechaUltimasVacaciones;
	Fecha* ultimoPagoAguinaldo;
	double ahorroNavidad;
	double ahorroEscolar;
	int porcentajeAhorroNav;
	int porcentajeAhorroEscol;
	
public:
	Planilla(Fecha*, Empleado*, Puesto*, bool);
	virtual const void setAhorroEscolar(int);
	virtual const void setAhorroNavidad(int);
	int vacacionesAcumuladas(Fecha*);
	int getPorcentajeAhorroNavidad();
	int getPorcentajeAhorroEscolar();
	virtual const string pagarAguinaldo(Fecha*);
	virtual const string otorgarVacaciones(Fecha*);
	void setPorcentajeAhorroEscolar(int);
	void setPorcentajeAhorroNavidad(int);
	void addAhorroNavidad();
	void addAhorroEscolar();
	virtual const bool pagarAhorro();
	double calculcarAguinaldo(Fecha*);
	void setFechaUltimaVacaciones(Fecha*);//
	virtual const void viajarEnElTiempo(Fecha*);
	virtual const string getSerializacion();
	void setUltimoPagoAguinaldo(Fecha*);//
	virtual const string retirarAhorros(Fecha*);
	double getDeducciones(double p); //Le paso el salario Bruto
	virtual const  string imprimirColillaDePago(Fecha*, double p=0);
	double getSalarioBruto(double regalia =0);
	double getSalarioNeto(double);//hay que pasarle el salarioBruto
	virtual const bool esPlanilla();
	virtual const int calcularCesantia(Fecha*);
	virtual const string cesarEmpleado(Fecha*);
	virtual const string toString();
	~Planilla();
};

