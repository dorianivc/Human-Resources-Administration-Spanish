#pragma once
#include <sstream>
#include<iostream>
#include<string>

using namespace std;
class Puesto
{
private:
	string nombre;
	int codigo;
	string descripcion;
	double salarioBase;
public:
	Puesto(string, int, string, double);
	Puesto( Puesto&);
	string getNombre();
	void setNombre(string);
	int getCodigo();
	void setCodigo(int);
	string getDescripcion();
	void setDescripcion(string);
	double getSalarioBase();
	void setSalarioBase(double);
	 string toString();
	double getDeducciones(double p);
	 int identificador();
	double getSalarioDiario();
	
	~Puesto();
};

