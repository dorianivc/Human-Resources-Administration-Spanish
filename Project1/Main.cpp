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
#include "Empresa.h"
#include "Fecha.h"
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
	


	double b = 1800000;
	Puesto* newPuesto = new Puesto("Ingeniero en Sistemas", "777", "Encargado en Calidad de Sistemas", b);
	
	double b2 = 1400000;
	Puesto* newPuesto2 = new Puesto("Ingeniero en Telematica", "776", "Encargado en Calidad de Redes", b2);

	
	Empleado* newEmpleado2 = new Empleado("602580939", "Calderon", "Monica", "18/11/2011", "84298549", "Quepos, Puntarenas");

	Planilla* newPlanilla = new Planilla(new Fecha(07,10,2018), newEmpleado, newPuesto, false);
	newPlanilla->setPorcentajeAhorroEscolar(10);
	newPlanilla->addAhorroEscolar();
	cout << newPlanilla->toString() << endl;
	cout << newPlanilla->imprimirColillaDePago(new Fecha(07,10,1999), 0) << endl;
	
	/*ServiciosProfesionales* newServ = new ServiciosProfesionales("04/03/2019", newEmpleado2, newPuesto2, "09/05/2017");
	cout << newServ->verColillaPago() << endl;*/
	Lista* newLista = new Lista();
	for (int i = 0; i < 5; i++) {
		newLista->insertar(newPlanilla);
		
		
	}


	Empresa* newEmpresa = new Empresa("HP", "Heredia", "84042758", new Fecha(07,07,2007));
	cout << newEmpresa->toString() << endl;
	cin.get();
	cout << "Agregando Puestos" << endl;
	newEmpresa->addPuesto(newPuesto);
	newEmpresa->addPuesto(newPuesto2);
	cout << newEmpresa->toString() << endl;
	cin.get();
	cout << "Eliminando Puesto" << endl;
	if (newEmpresa->eliminarPuesto("777")) {
		cout << "Puesto Eliminado" << endl;

	}
	else cout << "No eliminado" << endl;
	cout << newEmpresa->toString() << endl;
	cin.get();
	cout << "Agregando Lista de Empleados por referencia" << endl;
	newEmpresa->setListaEmpleados(newLista);
	cout << newEmpresa->toString() << endl;
	cin.get();


	//delete newPuesto2;
	//delete newServ;
	delete newEmpleado2;
	delete newEmpleado;
	//delete newPuesto;
	delete newPlanilla;

	return 0;
}