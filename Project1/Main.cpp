#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include "ListaContrato.h"
#include "ListaPuestos.h"
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
	//---------------------Creacion de la empresa------------------------//

	cout << "Bienvendo al sistema de gestion de Recursos Humanos" << endl;
	//Creado las variables de empresa
	Empresa* central = NULL;
	string nombreEmpresa, telefonoEmpresa, direccionEmpresa;
	int dia, mes, ano;
	bool exito = 0;
	cout << "Diguite el nombre de la empresa" << endl;
	getline(cin, nombreEmpresa);
	system("cls");
	cout << "Digite el telefono de la empresa" << endl;
	getline(cin, telefonoEmpresa);
	system("cls");
	cout << "Digite la direccion de la empresa" << endl;
	getline(cin, direccionEmpresa);
	system("cls");
	do {
		system("cls");
		try {

			cout << "Digite el dia de la fecha de hoy (Fortmato --> [1,31] )" << endl;
			cin >> dia;
			if (dia > 31 || dia < 0) {
				string excepcion = " Digito de dia Invalido ";
				throw excepcion;
			}
			system("cls");
			cout << "Digite el mes de la fecha de hoy(Fortmato-- > [1, 12])" << endl;
			cin >> mes;
			if (mes > 12 || mes < 0) {
				string excepcion = " Digito de mes Invalido ";
				throw excepcion;
			}
			system("cls");
			cout << "Digite el mes de la fecha de hoy(Fortmato-- > [2000, +00[  )" << endl;
			cin >> ano;
			if (ano < 2000) {
				string excepcion = " Digito de annio Invalido ";
				throw excepcion;
			}
			central = new Empresa(nombreEmpresa, direccionEmpresa, telefonoEmpresa, new Fecha(dia, mes, ano));
			exito = 1;
		}
		catch (string excepcion) {

			cout << "Se ha producido una exepcion:  " << excepcion << endl;
			system("PAUSE");

		}
	} while (exito != 1);
	if (central != NULL) {
		cout << central->toString() << endl;
		system("pause");
	}

	//---------------------FIN: Creacion de la empresa------------------------//

	//--------------------Creacion de Menu Principal-------------------------//
	unsigned eleccionMenuPrincipal;
	bool salirMenu = 0;
	do {
		system("cls");
		cout << "Empresa: " << central->getNombre() << endl;
		cout << endl;
		cout << "Ingrese el digito que corresponde a la eleccion del menu" << endl;
		cout << endl;
		cout << endl;
		cout << "(1) --> Crear Puesto" << endl;
		cout << "(2) --> Eliminar Puesto" << endl;
		cout << "(3) --> Contratar empleado a algun puesto disponible" << endl;
		cout << "(4) --> toString()" << endl;
		cout << "(5) --> SALIR" << endl;
		//--------------------FIN: Creacion de Menu Principal-------------------------//

		//-------------------Iterador con Menu Principal-------------------------------//
		try {
			
			cin >> eleccionMenuPrincipal;
			if (eleccionMenuPrincipal == 1) {	//----------------> ELECCION 1
				cin.ignore();
				Puesto* puestoAagregar;
				string nombrePuesto, codigoPuesto, descripcionPuesto; double salarioBasePuesto;
				exito = 0;
				cout << "Digite el nombre del Puesto" << endl;
				getline(cin, nombrePuesto);
				cout << "Digite el codigo del Puesto" << endl;
				getline(cin, codigoPuesto);
				system("cls");
				cout << "Escriba una descripcion del Puesto ---> " << nombrePuesto << " : " << codigoPuesto << " <---" << endl;
				getline(cin, descripcionPuesto);
				do {
					system("cls");
					cin.ignore();
					cout << "Digite el Salario Base del puesto a crear" << endl;
					
					try {

						
						cin >> salarioBasePuesto;
						

					}
					catch (double salarioBasePuesto) {
						cout << "El dato ingresado no corresponde a un numero" << endl;
						system("pause");
					}
					exito = 1;
					puestoAagregar = new Puesto(nombrePuesto, codigoPuesto, descripcionPuesto, salarioBasePuesto);
					central->getListaPuestos()->insertar(puestoAagregar);
				} while (exito != 1);//------------------------> FIN ELECCION 1
			}
			else if (eleccionMenuPrincipal == 2) {//--------------------ELECCION 2
				cin.ignore();
				string codigoPuesto;
				exito = 0;
				cout << "ELIMINANDO PUESTO" << endl;
				cout << endl;
				cout << central->getListaPuestos()->toString() << endl;
				cout << endl;
				cout << endl;
				cout << "Digite el codigo del puesto a eliminar" << endl;
				getline(cin, codigoPuesto);
				do {
					cout << "Digite el codigo del puesto a eliminar" << endl;
					getline(cin, codigoPuesto);
					try {
						if (central->getListaPuestos()->eliminarIdentificador(codigoPuesto) != false) {
							cout << "Puesto eliminado" << endl;
							exito = 1;
							system("pause");


						}
						else {
							string exepcion = "PUESTO NO ELIMINADO: (No existe o error al borrar)";
							throw exepcion;

						}
					}
					catch (string exepcion) {
						cout << "ERROR: " << exepcion << endl;
						system("pause");
					}
				} while (exito != 1);//-----------------> FIN ELECCION 2
			}
			else if (eleccionMenuPrincipal == 3) { //----------------> ELECCION 3

				cin.ignore();
				unsigned eleccionSubMenuContratacion;
				Empleado* empleadoAux;
				Puesto* puestoAux;
				string nombreEmpleado, apellidoEmpleado, fechaNacimientoEmpleado, direccionEmpleado, telefonoEmpleado;
				bool esTemporal;
				cout << "Digite el nombre del empleado" << endl;
				getline(cin, nombreEmpleado);
				system("cls");
				cout << "Digile los apellidos del empleado" << endl;
				getline(cin, apellidoEmpleado);
				system("cls");
				cout << "Digite la Fecha de Nacimiento del empleado" << endl;
				getline(cin, fechaNacimientoEmpleado);
				system("cls");
				cout << "Digite la direccion domestica del empleado" << endl;
				getline(cin, direccionEmpleado);
				system("cls");
				cout << "Digite el numero de telefono del empleado" << endl;
				getline(cin, telefonoEmpleado);
				cin.ignore();

				do {
					system("cls");
					cout << "Es el puesto de : " << nombreEmpleado << " " << apellidoEmpleado << "  TEMPORAL?" << endl;
					cout << "Digite 1 si es Temporal" << endl;
					cout << "Digite 0 si es a Propiedad" << endl;
					bool exito = 0;
					try {
						cin >> esTemporal;
						exito = 1;
					}
					catch (string p) {
						cout << "Error: TIPO DE DATO INGRESADO ES INVALIDO" << endl;
					}
				} while (exito != 1);

				unsigned subEleccion;

				cout << "Digite el numero del nodo del puesto al que desea contratar" << endl;
				cout << central->getListaPuestos()->toString() << endl;
				do {
					bool exito = 0;
					try {
						cin >> subEleccion;
						if (central->getListaPuestos()->getPosicion(subEleccion) == NULL)
						{
							string exepcion = "La posicion ingresada no existe";
							throw exepcion;
						}
						}
					catch (string exepcion) {
						cout << exepcion << endl;
						system("pause");
					}
					puestoAux = central->getListaPuestos()->getPosicion(subEleccion)->getInfo();
					exito = 1;
				} while (exito != 1);
				empleadoAux = new Empleado(nombreEmpleado, apellidoEmpleado, fechaNacimientoEmpleado, direccionEmpleado, direccionEmpleado, telefonoEmpleado);
				cout << "Digite 1 si desea contratar por Planilla(Temporal o Propiedad)" << endl;
				cout << "Digite 2 si desea contratar por servicios profesionales" << endl;
				string nomPuesto = puestoAux->getNombre(), codPuesto = puestoAux->getCodigo(), desPuesto = puestoAux->getDescripcion();
				double salPuesto= puestoAux->getSalarioBase();
				try {
					cin >> eleccionSubMenuContratacion;
					if (eleccionSubMenuContratacion == 1) {
						puestoAux = new Puesto(nomPuesto, codPuesto, desPuesto, salPuesto);
						central->getListaEmpleados()->insertar(new Planilla(central->getFechaActual(), empleadoAux,puestoAux , esTemporal));

					}
					else if (eleccionSubMenuContratacion == 2) {
						Fecha* cesantia;
						cout << "Digite una fecha de Censantia" << endl;
						do {
							int dia, mes, ano;
							system("cls");
							try {

								cout << "Digite el dia de la fecha (Fortmato --> [1,31] )" << endl;
								cin >> dia;
								if (dia > 31 || dia < 0) {
									string excepcion = " Digito de dia Invalido ";
									throw excepcion;
								}
								system("cls");
								cout << "Digite el mes de la fecha (Fortmato-- > [1, 12])" << endl;
								cin >> mes;
								if (mes > 12 || mes < 0) {
									string excepcion = " Digito de mes Invalido ";
									throw excepcion;
								}
								system("cls");
								cout << "Digite el annio de la fecha (Fortmato-- > [2000, +00[  )" << endl;
								cin >> ano;
								if (ano < 2000) {
									string excepcion = " Digito de annio Invalido ";
									throw excepcion;
								}
								
							}
							catch (string excepcion) {

								cout << "Se ha producido una exepcion:  " << excepcion << endl;
								system("PAUSE");

							}
							cesantia = new Fecha(dia, mes, ano);
							if (cesantia->Distancia(central->getFechaActual(), cesantia) > 0) {

								exito = 1;
							}
							else
							{
								cout << "La fecha de cesantia ingresada es invalida" << endl;
								
							}
						} while (exito != 1);

						central->getListaEmpleados()->insertar(new ServiciosProfesionales(central->getFechaActual(), empleadoAux, puestoAux, cesantia));
					}
				}
				catch (string p) {
					cout << "Eleccion incorrecta o mal digitada" << endl;
					system("pause");
				}
			}
			else if (eleccionMenuPrincipal == 4) {
				cout << central->toString() << endl;
				system("pause");
			}
			else if (eleccionMenuPrincipal == 5) {
				salirMenu = 1;
			}
			else {
			string p;
			throw p;
}
		}
		catch (string p) {
			cout << "Eleccion incorrecta o mal digitada" << endl;
			system("pause");

		}
	}while (salirMenu != 1);



	//-------------------FIN: Iterador con Menu Principal-------------------------------//

	delete central;

	return 0;
}