#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
using namespace std;
class NodoLista
{
public:
	NodoLista() {

	}
	~NodoLista() {

	}
	virtual const string identificador() = 0;
	virtual const string toString() = 0;
};

