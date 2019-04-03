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
public:
	Puesto(string, string, string, double);
	string getNombre();
	void setNombre(string);
	string getCodigo();
	void setCodigo(string);
	string getDescripcion();
	void setDescripcion(string);
	virtual const string toString();
	~Puesto();
};

