#pragma once
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
	double aguinaldo;
	int porcentajeAhorroNav;
	int porcentajeAhorroEscol;
	int diasvacacionesAcumuladas;
public:
	Planilla(Fecha*, Empleado*, Puesto*, bool);
	int vacacionesAcumuladas();
	int getPorcentajeAhorroNavidad();
	int getPorcentajeAhorroEscolar();
	void setPorcentajeAhorroEscolar(int);
	void setPorcentajeAhorroNavidad(int);
	void addAhorroNavidad();
	void addAhorroEscolar();
	double calculcarAguinaldo(Fecha*);
	void setFechaUltimaVacaciones(Fecha*);//
	void setUltimoPagoAguinaldo(Fecha*);//
	double getDeducciones(double p); //Le paso el salario Bruto
	string imprimirColillaDePago(Fecha*, double p=0);
	double getSalarioBruto(double regalia =0);
	double getSalarioNeto(double);//hay que pasarle el salarioBruto
	virtual const bool esPlanilla();
	virtual const string toString();
	~Planilla();
};

