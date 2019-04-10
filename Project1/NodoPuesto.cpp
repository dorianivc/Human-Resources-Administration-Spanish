#include "NodoPuesto.h"





NodoPuesto::NodoPuesto(Puesto * newPuesto, NodoPuesto * newContrato)
{
	info = newPuesto;
	siguiente = newContrato;
}

Puesto * NodoPuesto::getInfo()
{
	return info;
}

void NodoPuesto::setInfo(Puesto * newPuesto)
{
	info = newPuesto;
}

NodoPuesto * NodoPuesto::getSiguiente()
{
	return siguiente;
}

void NodoPuesto::setSiguiente(NodoPuesto * newNodo)
{
	siguiente = newNodo;
}

string NodoPuesto::toString()
{
	return info->toString();
}

NodoPuesto::~NodoPuesto()
{
}
