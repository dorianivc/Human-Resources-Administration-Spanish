#pragma once
#include "Puesto.h"
#include <iostream>
#include <sstream>
using namespace std;
class NodoPuesto
{private:
	Puesto* info;
	NodoPuesto* siguiente;
public:
	NodoPuesto(Puesto*, NodoPuesto*);
	Puesto* getInfo();
	void setInfo(Puesto*);
	NodoPuesto* getSiguiente();
	void setSiguiente(NodoPuesto*);
	string toString();
	~NodoPuesto();
};

