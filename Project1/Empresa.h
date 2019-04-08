#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include "Lista.h"
#include "Puesto.h"
#include "NodoLista.h"
using namespace std;
class Empresa
{
	string nombre;
	string direccion;
	string telefono;
	string fechaActual;
	Lista* listaEmpleados;
	Lista* ListaPuestos;
public:
	Empresa(string, string, string, string);
	Empresa(Empresa&);
	void addPuesto(string, string, string, double);
	void addPuesto(Puesto*);
	bool eliminarPuesto(string);
	string getNombre();
	string getDireccion();
	void setDireccion(string);
	string getTelefono();
	void setTelefono(string);
	string getFechaActual();
	Lista* getListaEmpleados();
	void setListaEmpleados(Lista*);
	Lista* getListaPuestos();
	void setListaPuestos(Lista*);
	void operator =(Empresa&);
	string toString();

	~Empresa();
};

