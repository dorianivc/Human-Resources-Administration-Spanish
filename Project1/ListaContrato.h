#pragma once
#include <sstream>
#include <iostream>
#include <string>
#include "NodoContrato.h"
using namespace std;
class ListaContratos
{private:
	NodoContrato* primero;
	NodoContrato* actual;
public:
	ListaContratos();
	void insertar(Contrato*);
	int cuentaNodos();
	bool listaVacia();
	void actualizarAhorros(int);
	NodoContrato* getPosicion(int);
	string toString();
	bool eliminarIdentificador(string);
	void pagarAguinaldos(Fecha*);

	~ListaContratos();
};

