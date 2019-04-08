#pragma once
#include <sstream>
#include <iostream>
#include <string>
#include "Nodo.h"
using namespace std;
class Lista
{private:
	Nodo* primero;
	Nodo* actual;
public:
	Lista();
	void insertar(NodoLista*);
	int cuentaNodos();
	bool listaVacia();
	Nodo* getPosicion(int);
	string toString();
	bool eliminarIdentificador(string);

	~Lista();
};

