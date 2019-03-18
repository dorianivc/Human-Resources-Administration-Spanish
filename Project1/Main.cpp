#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include "Contrato.h"
#include "Herramientas.h"
using namespace std;

int main()
{
	string ced = "604560223";
	string apellido = "Vallecillo";
	string nombre = "Dorian";
	string fecha = "07/10/1999";
	string numero = "84042758";
	string dir = "Heredia";
	double salario = 1500000;
	Contrato* prueba = new Contrato(ced, nombre, apellido, fecha, dir, numero, "Ingeniero", "Sistemas", salario);
	cout << prueba->toString() << endl;
	cin.get();
	delete prueba;
}