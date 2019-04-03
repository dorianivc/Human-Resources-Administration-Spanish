#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include "Lista.h"
#include "Empleado.h"
#include "Contrato.h"
#include "Herramientas.h"
#include "Planilla.h"
#include "ServiciosProfesionales.h"
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
	


	double b = 800000;
	Puesto* newPuesto = new Puesto("Ingeniero en Sistemas", "777", "Encargado en Calidad de Sistemas", b);
	
	double b2 = 1400000;
	Puesto* newPuesto2 = new Puesto("Ingeniero en Telematica", "776", "Encargado en Calidad de Redes", b2);

	
	Empleado* newEmpleado2 = new Empleado("602580939", "Calderon", "Monica", "18/11/2011", "84298549", "Quepos, Puntarenas");

	Planilla* newPlanilla = new Planilla("07/10/2018", newEmpleado, newPuesto, false);
	newPlanilla->getPuesto()->setAhorroNavidad(150000.00);
	newPlanilla->getPuesto()->setAhorroSalEscolar(25000.00);
	newPlanilla->getPuesto()->addSalario(50000);
	cout << newPlanilla->toString() << endl;
	cout << newPlanilla->verColillaPago() << endl;
	
	ServiciosProfesionales* newServ = new ServiciosProfesionales("04/03/2019", newEmpleado2, newPuesto2, "09/05/2017");
	cout << newServ->verColillaPago() << endl;
	Lista* newLista = new Lista();
	for (int i = 0; i < 5; i++) {
		newLista->insertar(newPlanilla);
		newLista->insertar(newServ);
		
	}

	cout <<"NODOS--->"<< newLista->cuentaNodos();
	cout << newLista->toString() << endl;

	

	cin.get();
	delete newEmpleado;
	delete newPuesto;
	delete newPlanilla;

	return 0;
}