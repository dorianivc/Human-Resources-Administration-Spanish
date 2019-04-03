#pragma once
#include "NodoLista.h"
using namespace std;
class Puesto :
	public NodoLista
{
private:
	string nombre;
	string codigo;
	string descripcion;
	double salarioBase;
	double salarioBruto;
	double ahorroNavidad;
	double ahorroSalEscolar;
public:
	Puesto(string, string, string, double);
	string getNombre();
	void setNombre(string);
	string getCodigo();
	void setCodigo(string);
	string getDescripcion();
	void setDescripcion(string);
	double getSalarioBase();
	void setSalarioBase(double);
	virtual const string toString();
	double getDeducciones(double p);
	double getSalarioBruto();
	void addSalario(double);
	double getSalarioNeto();
	double getAhorroNavidad();
	void setAhorroNavidad(double);
	double getAhorroSalEscolar();
	void setAhorroSalEscolar(double);
	~Puesto();
};

