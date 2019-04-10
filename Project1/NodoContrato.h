#pragma once
#include "Contrato.h"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
class NodoContrato
{
private:
	Contrato* info;
	NodoContrato* siguiente;
public:
	NodoContrato(Contrato*, NodoContrato*);
	Contrato* getInfo();
	void setInfo(Contrato*);
	NodoContrato* getSiguiente();
	void setSiguiente(NodoContrato*);
	string toString();
	~NodoContrato();
};

