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
	/*//---------------------Creacion de la empresa------------------------//

	cout << "Bienvendo al sistema de gestion de Recursos Humanos" << endl;
	//Creado las variables de empresa
	Empresa* central=NULL;
	Fecha* fechaEmpresa=NULL;
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
			 fechaEmpresa = new Fecha(dia, mes, ano);
			central = new Empresa(nombreEmpresa, direccionEmpresa, telefonoEmpresa, fechaEmpresa);
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
	string fechaCentral = central->fechaToString();*/
	Empresa* central = new Empresa("hP", " dds", " jns", new Fecha(01, 01, 2001));
	Puesto* puestin = new Puesto("Labrador", "45", " ", 345000);
	Planilla*  p = new Planilla(central->getFechaActual(), new Empleado("604560223", "Dorian", "ROBERTO", "", "", ""), puestin, true);
	p->setPorcentajeAhorroEscolar(10);

	Planilla*  j = new Planilla(central->getFechaActual(), new Empleado("604560224", "Jorge", "RT", "", "", ""), puestin, false);
	j->setPorcentajeAhorroEscolar(15);
	central->addPuesto(puestin);
	central->addContrato(p);
	central->addContrato(j);
	bool exito = 0;
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
		cout << "(5) -->  Pagar Salarios" << endl;
		cout << "(6) --> Retirar Ahorros" << endl;
		cout << "(7) --> Pagar Aguinaldos" << endl;
		cout << "(8) --> Otorgar Vacaciones" << endl;
		cout << "(9) --> Cesar Empleado" << endl;
		cout << "(10) --> Viajar en el tiempo" << endl;
		cout << "(11) --> SALIR" << endl;

		//--------------------FIN: Creacion de Menu Principal-------------------------//

		//-------------------Iterador con Menu Principal-------------------------------//
		try {
			cin.ignore();
			cin >> eleccionMenuPrincipal;
			swtich(eleccionMenuPrincipal) {
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
					central->getListaPuestos()->insertar(new Puesto(nombrePuesto, codigoPuesto, descripcionPuesto, salarioBasePuesto));
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


				do {
					cin.ignore();
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

				string subEleccion;

				cout << "Digite el numero del codigo del puesto al que desea contratar" << endl;
				cout << central->getListaPuestos()->toString() << endl;
				do {
					bool exito = 0;
					try {
						cin.ignore();
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
					puestoAux = central->getListaPuestos()->getPosicion(subEleccion);

					exito = 1;
				} while (exito != 1);
				empleadoAux = new Empleado(nombreEmpleado, apellidoEmpleado, fechaNacimientoEmpleado, direccionEmpleado, direccionEmpleado, telefonoEmpleado);
				cout << "Digite 1 si desea contratar por Planilla(Temporal o Propiedad)" << endl;
				cout << "Digite 2 si desea contratar por servicios profesionales" << endl;

				try {
					cin.ignore();
					cin >> eleccionSubMenuContratacion;
					if (eleccionSubMenuContratacion == 1) {
						central->getListaEmpleados()->insertar(new Planilla(central->getFechaActual(), empleadoAux, puestoAux, esTemporal));

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
				try {
					cout << central->getListaEmpleados()->pagarSalarios(central->getFechaActual()) << endl;
				}
				catch (bad_alloc& e) {
					cout << "Exepcion producida : " << e.what() << endl;
					system("pause");
				}
				system("pause");

			}
			else if (eleccionMenuPrincipal == 6) {//------------->Retirar ahorros
				string cedEmpleado;
				cout << "Digite el numero de cedula del empleado que desea retirar ahorro" << endl;
				getline(cin, cedEmpleado);
				cin.ignore();
				try {
					if (central->getListaEmpleados()->getPosicion(cedEmpleado) == NULL) {
						string p = "Empleado no existe";
						throw p;

					}
					else {

						central->getListaEmpleados()->getPosicion(cedEmpleado)->retirarAhorros(central->getFechaActual());
					}
				}
				catch (string l) {
					cout << "Exepcion producida: " << l << endl;
					system("pause");
				}
			}
			else if (eleccionMenuPrincipal == 7) {//----------->Pagar Aguinaldos
				cout << central->getListaEmpleados()->pagarAguinaldos(central->getFechaActual());
				system("pause");
			}
			else if (eleccionMenuPrincipal = 8) {//-------------> Otorgar Vacaciones
				cout << "Otorgando vacaciones" << endl;
				cout << "Ingrese el numero de cedula del empleado a otorgar vacaciones" << endl;
				string cedAux;
				getline(cin, cedAux);
				cin.ignore();
				cout << central->getListaEmpleados()->otorgarVacaciones(central->getFechaActual(), cedAux);

			}
			else if (eleccionMenuPrincipal == 9) {//------------> Cesar Empleado
				cout << "Cesando Empleado" << endl;
				cout << "Digite el numero de cedula del empleado a cesar" << endl;
				string cedAux;
				getline(cin, cedAux);
				cin.ignore();
				try {
					if (central->getListaEmpleados()->getPosicion(cedAux) == NULL) {
						throw "Empleado no existe";

					}
					else {
						cout << central->getListaEmpleados()->getPosicion(cedAux)->cesarEmpleado(central->getFechaActual()) << endl;
					}
				}
				catch (string x) {
					cout << "Exepcion Producida: " << x << endl;
					system("pause");

				}
			}
			else if (eleccionMenuPrincipal == 10) {//--------------> viajar en el tiempo
				bool exito = 0;
				int dia, mes, ano;
				Fecha* fechaAviajar = NULL;
				do {

					system("cls");
					cout << "Digite la fecha a viajar" << endl;

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
						fechaAviajar = new Fecha(dia, mes, ano);
						exito = 1;
					}
					catch (string excepcion) {

						cout << "Se ha producido una exepcion:  " << excepcion << endl;
						system("PAUSE");

					}
				} while (exito != 1);

				central->getListaEmpleados()->viajarEnElTiempo(fechaAviajar);
			}
			else if (eleccionMenuPrincipal == 11) {//salir
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
	}
	}while (salirMenu != 1);



	//-------------------FIN: Iterador con Menu Principal-------------------------------//

	delete central;

	return 0;
}