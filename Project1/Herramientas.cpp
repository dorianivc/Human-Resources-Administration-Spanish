#include "Herramientas.h"



string Herramientas::obtenerFecha()
{
#pragma warning(disable : 4996)

	auto t = std::time(nullptr);
	auto tm = *std::localtime(&t);
	std::ostringstream oss;
	oss << std::put_time(&tm, "%F");
	auto str = oss.str();

	return str;

	
}

int Herramientas::convertirInt(string s)
{
	std::stringstream r(s);
	int v;
	r >> v;
	return v;
}
