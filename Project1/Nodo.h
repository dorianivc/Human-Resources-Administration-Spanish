#pragma once
#include "NodoLista.h"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
class Nodo
{
private:
	NodoLista* info;
	Nodo* siguiente;
public:
	Nodo(NodoLista*, Nodo*);
	NodoLista* getInfo();
	void setInfo(NodoLista*);
	Nodo* getSiguiente();
	void setSiguiente(Nodo*);
	string toString();
	~Nodo();
};

