#pragma once
#include <sstream>
#include<iostream>
#include<string>

using namespace std;
class Puesto
{
private:
	string nombre;
	string codigo;
	string descripcion;
	double salarioBase;
public:
	Puesto(string, string, string, double);
	Puesto( Puesto&);
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
	virtual const string identificador();
	double getSalarioDiario();
	
	~Puesto();
};

