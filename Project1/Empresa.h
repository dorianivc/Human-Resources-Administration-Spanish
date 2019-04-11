#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include "ListaContrato.h"
#include "ListaPuestos.h"
using namespace std;
class Empresa
{
private:

	string nombre;
	string direccion;
	string telefono;
	Fecha* fechaActual;
	ListaContratos* listaEmpleados;
	ListaPuestos* puestos;
	
public:
	ListaPuestos* getListaPuestos();
	void setListaPuesto(ListaPuestos*);
	Empresa(string, string, string, Fecha* );
	Empresa(Empresa&);
	void viajarAdelanteEnELTiempo(Fecha*);
	void addPuesto(string, int, string, double);
	void pagarAguinaldo();
	void addPuesto(Puesto*);
	void setFecha(Fecha*);
	void addContrato(Contrato*);
	bool eliminarPuesto(int);
	string getNombre();
	string getDireccion();
	void setDireccion(string);
	string getTelefono();
	void setTelefono(string);
	Fecha* getFechaActual();
	string fechaToString();
	ListaContratos* getListaEmpleados();
	void setListaEmpleados(ListaContratos*);
	void operator =(Empresa&);
	string toString();

	~Empresa();
};

