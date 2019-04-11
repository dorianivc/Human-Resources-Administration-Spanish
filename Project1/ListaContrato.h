#pragma once
#include <sstream>
#include <iostream>
#include <string>
#include "NodoContrato.h"
#include <fstream>
using namespace std;
class ListaContratos
{private:
	NodoContrato* primero;
	NodoContrato* actual;
public:
	ListaContratos();
	void viajarEnElTiempo(Fecha*);
	bool insertarSinRegistrar(Contrato*);
	void insertar(Contrato*);
	int cuentaNodos();
	bool listaVacia();
	void actualizarAhorros(int);
	Contrato* getPosicion(int);
	bool existePosicion(int);
	string toString();
	string pagarSalarios(Fecha*);
	string otorgarVacaciones(Fecha*, int);
	bool eliminarIdentificador(string);
	string pagarAguinaldos(Fecha*);

	~ListaContratos();
};

