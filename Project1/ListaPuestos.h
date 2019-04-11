#pragma once
#include "NodoPuesto.h"
#include <string>
using namespace std;
class ListaPuestos
{
private:
	NodoPuesto* primero;
	NodoPuesto* actual;
public:
	ListaPuestos();
	void insertar(Puesto*);
	int cuentaNodos();
	bool listaVacia();
	Puesto*  getPosicion(int);
	Puesto* getPosicion(string);
	string toString();
	bool eliminarIdentificador(string);
	~ListaPuestos();
};

