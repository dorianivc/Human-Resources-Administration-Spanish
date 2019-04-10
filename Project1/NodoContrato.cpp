#include "NodoContrato.h"



NodoContrato::NodoContrato(Contrato* info, NodoContrato * siguiente)
{
	this->info = info;
	this->siguiente = siguiente;
}

Contrato*  NodoContrato::getInfo()
{
	return info;
}

void NodoContrato::setInfo(Contrato* newInfo)
{
	info = newInfo;
}

NodoContrato * NodoContrato::getSiguiente()
{
	return siguiente;
}

void NodoContrato::setSiguiente(NodoContrato * sgts)
{
	siguiente = sgts;
}

string NodoContrato::toString()
{
	stringstream p;
	p << info->toString() << endl;
	return p.str();
}

NodoContrato::~NodoContrato()
{
}
