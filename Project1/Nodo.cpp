#include "Nodo.h"



Nodo::Nodo(NodoLista * info, Nodo * siguiente)
{
	this->info = info;
	this->siguiente = siguiente;
}

NodoLista * Nodo::getInfo()
{
	return info;
}

void Nodo::setInfo(NodoLista * newInfo)
{
	info = newInfo;
}

Nodo * Nodo::getSiguiente()
{
	return siguiente;
}

void Nodo::setSiguiente(Nodo * sgts)
{
	siguiente = sgts;
}

string Nodo::toString()
{
	stringstream p;
	p << info->toString() << endl;
	return p.str();
}

Nodo::~Nodo()
{
}
