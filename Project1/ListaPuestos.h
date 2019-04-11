#pragma once
#include "NodoPuesto.h"
#include <fstream>
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
	bool insertarSinRegistrar(Puesto*);
	int cuentaNodos();
	bool listaVacia();
	bool existePosicion(int);
	Puesto* getPosicion(int);
	string toString();
	bool eliminarIdentificador(int);
	~ListaPuestos();
};

