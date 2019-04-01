#pragma once
#include <string>
using namespace std;
class NodoLista
{
public:
	NodoLista();
	~NodoLista();
	virtual const string toString() = 0;
};



NodoLista::NodoLista()
{
}


NodoLista::~NodoLista()
{
}
