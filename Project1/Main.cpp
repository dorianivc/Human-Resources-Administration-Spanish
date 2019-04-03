#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include "Empleado.h"
#include "Contrato.h"
#include "Herramientas.h"
#include "Planilla.h"
using namespace std;

int main()
{
	string ced = "604560223";
	string apellido = "Vallecillo";
	string nombre = "Dorian";
	string fecha = "07/10/1999";
	string numero = "84042758";
	string dir = "Heredia";
	cout << "//Probando Empleado;" << endl;
	Empleado* newEmpleado = new Empleado(ced, apellido, nombre, fecha, numero, dir);
	cout << newEmpleado->toString();
	cin.get();
	cout << "//Probando Puesto;" << endl;

	double b = 1500000;
	Puesto* newPuesto = new Puesto("Ingeniero en Sistemas", "777", "Encargado en Calidad de Sistemas", b);
	cout << newPuesto->toString();
	cin.get();
	cout << "//Probando planilla;" << endl;

	Planilla* newPlanilla = new Planilla("07/10/2018", newEmpleado, newPuesto, false);
	cout << newPlanilla->toString() << endl;
	cin.get();

	delete newEmpleado;
	delete newPuesto;
	delete newPlanilla;

	return 0;
}