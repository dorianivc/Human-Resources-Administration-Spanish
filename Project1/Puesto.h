#pragma once
#include "NodoLista.h"
class Puesto :
	public NodoLista
{
private:
	string nombre;
	string codigo;
	string descripcion;
public:
	Puesto(string, string, string);
	string getNombre();
	void setNombre(string);
	string getCodigo();
	void setCodigo(string);
	string getDescripcion();
	void setDescripcion(string);
	~Puesto();
};

