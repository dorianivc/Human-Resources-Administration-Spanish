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
	int porcentajeAhorroNav;
	int porcentajeAhorroEscol;
	
public:
	Planilla(Fecha*, Empleado*, Puesto*, bool);
	int vacacionesAcumuladas(Fecha*);
	int getPorcentajeAhorroNavidad();
	int getPorcentajeAhorroEscolar();
	virtual const void pagarAguinaldo(Fecha*);
	virtual const void otorgarVacaciones(Fecha*);
	void setPorcentajeAhorroEscolar(int);
	void setPorcentajeAhorroNavidad(int);
	void addAhorroNavidad();
	void addAhorroEscolar();
	virtual const bool pagarAhorro();
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

