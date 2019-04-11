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
#include "AnalizadorArchivos.h"
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
	Puesto * puestin = new Puesto("Loquera", 777, "nada,", 46000.0);
	//central->addPuesto(puestin);
	central->addContrato(new ServiciosProfesionales(new Fecha(01, 01, 2001), new Empleado(604560225, "dorian", "vallecillo", "f", "g", "h"), puestin, new Fecha(01, 01, 2002)));
	//AnalizadorArchivos::ingresarEmpleados(central->getListaEmpleados(), central->getListaPuestos());
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
		cout << "(11) --> Cargar puestos desde registro" << endl;
		cout << "(12) --> Cargar empleados desde registro" << endl;
		cout << "(13) --> SALIR" << endl;

		//--------------------FIN: Creacion de Menu Principal-------------------------//

		//-------------------Iterador con Menu Principal-------------------------------//
		try {
			cin >> eleccionMenuPrincipal;
			Puesto* puestoAagregar;
			string nombrePuesto,  descripcionPuesto; double salarioBasePuesto;
			unsigned eleccionSubMenuContratacion;
			int codigoPuesto;
			Empleado* empleadoAux;
			Puesto* puestoAux=NULL;
			string nombreEmpleado, apellidoEmpleado, fechaNacimientoEmpleado, direccionEmpleado, telefonoEmpleado;
			bool esTemporal;
			string p;
			int cedEmpleado;
			bool exito = 0;
			int dia, mes, ano;
			int cedAux;
			int subEleccion;
			Fecha* fechaAviajar = NULL;
			
			switch (eleccionMenuPrincipal){ 
			case 1:  cin.ignore();
				
				exito = 0;
				cout << "Digite el nombre del Puesto" << endl;
				getline(cin, nombrePuesto);
				cout << "Digite el codigo del Puesto" << endl;
				cin >> codigoPuesto;
				cin.ignore();
				cout << "Escriba una descripcion del Puesto ---> " << nombrePuesto << " : " << codigoPuesto << " <---" << endl;

				getline(cin, descripcionPuesto);
				do {
					system("cls");
					cout << "Digite el Salario Base del puesto a crear" << endl;

					try {


						cin >> salarioBasePuesto;


					}
					catch (double salarioBasePuesto) {
						cout << "El dato ingresado no corresponde a un numero" << endl;
						system("pause");
					}
					exito = 1;
					if (central->getListaPuestos()->existePosicion(codigoPuesto) == false) {
						central->getListaPuestos()->insertar(new Puesto(nombrePuesto, codigoPuesto, descripcionPuesto, salarioBasePuesto));
					}
					else {
						cout << "Codigoo de puesto ya existe y esta relacionado a: " <<endl<< central->getListaPuestos()->getPosicion(codigoPuesto)->toString() << endl;
						system("pause");
					}
				} while (exito != 1);//------------------------> FIN ELECCION 1
				
				break;
			case 2:

				cin.ignore();
				
				exito = 0;
				cout << "ELIMINANDO PUESTO" << endl;
				cout << endl;
				cout << central->getListaPuestos()->toString() << endl;
				cout << endl;
				cout << endl;
				do {
					cout << "Digite el codigo del puesto a eliminar" << endl;
					cin>> codigoPuesto;
					try {
						if (central->eliminarPuesto(codigoPuesto) != false) {
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
				break;
			case 3:
				
				if (central->getListaPuestos()->listaVacia() == false) {
					cin.ignore();
					cout << "Digite el numero de Cedulad del empleado" << endl;
					cin >> cedAux;
					cin.ignore();
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


					if (central->getListaEmpleados()->existePosicion(cedAux) == false) {
						cin.ignore();
						system("cls");
						cout << "Es el puesto de : " << nombreEmpleado << " " << apellidoEmpleado << "  TEMPORAL?" << endl;
						cout << "Digite 1 si es Temporal" << endl;
						cout << "Digite 0 si es a Propiedad" << endl;



						cin >> esTemporal;







						cout << "Digite el numero del codigo del puesto al que desea contratar" << endl;
						cout << central->getListaPuestos()->toString() << endl;
						do {
							exito = 0;
							try {
								cin >> subEleccion;
								if (central->getListaPuestos()->getPosicion(subEleccion) == NULL)
								{
									string exepcion = "La posicion ingresada no existe";
									throw exepcion;
								}
								else {
									puestoAux = central->getListaPuestos()->getPosicion(subEleccion);
									exito = 1;
								}
							}
							catch (string exepcion) {
								cout << exepcion << endl;
								system("pause");
							}



						} while (exito != 1);
						empleadoAux = new Empleado(cedAux, nombreEmpleado, apellidoEmpleado, fechaNacimientoEmpleado, direccionEmpleado, telefonoEmpleado);
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
else {
cout << "Ya existe un empleado relacionado al numero de cedula: " << cedAux << endl;
cout << "Corresponde a : " << endl << central->getListaEmpleados()->getPosicion(cedAux)->toString() << endl;
}
				}
 else {
 cout << "No hay puestos disponibles para contratar empleados" << endl;
}
system("pause");
				break;
				case 4:
					cout << central->toString() << endl;
					system("pause");
					break;
				case 5:
					try {
						cout << central->getListaEmpleados()->pagarSalarios(central->getFechaActual()) << endl;
					}
					catch (bad_alloc& e) {
						cout << "Exepcion producida : " << e.what() << endl;
						system("pause");
					}
					system("pause");

					break;
				case 6:
					
					cout << "Digite el numero de cedula del empleado que desea retirar ahorro" << endl;
					cin>>cedEmpleado;
					cin.ignore();
					try {
						if (central->getListaEmpleados()->getPosicion(cedEmpleado) == NULL) {
							string p = "Empleado no existe";
							throw p;

						}
						else {

							cout<<central->getListaEmpleados()->getPosicion(cedEmpleado)->retirarAhorros(central->getFechaActual());
							system("pause");
						}
					}
					catch (string l) {
						cout << "Exepcion producida: " << l << endl;
						system("pause");
					}
					break;
				case 7:cout << central->getListaEmpleados()->pagarAguinaldos(central->getFechaActual());
					system("pause");
					break;
				case 8:  cout << "Otorgando vacaciones" << endl;
					cout << "Ingrese el numero de cedula del empleado a otorgar vacaciones" << endl;
					
					cin >> cedAux;
					cin.ignore();
					cout << central->getListaEmpleados()->otorgarVacaciones(central->getFechaActual(), cedAux);
					system("pause");
					break;
				case 9:
					cout << "Cesando Empleado" << endl;
					cout << "Digite el numero de cedula del empleado a cesar" << endl;
					
					cin>> cedAux;
					cin.ignore();
					try {
						if (central->getListaEmpleados()->getPosicion(cedAux) == NULL) {
							string p = "Empleado no existe";
							throw p ;

						}
						else {
							cout << central->getListaEmpleados()->getPosicion(cedAux)->cesarEmpleado(central->getFechaActual()) << endl;
							system("pause");
						}
					}
					catch (string x) {
						cout << "Exepcion Producida: " << x << endl;
						system("pause");

					}
					break;
				case 10: 
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
					central->setFecha(fechaAviajar);
					break;
				case 13:
					salirMenu = 1;
					break;
				case 11:
					AnalizadorArchivos::ingresarPuestos(central->getListaPuestos());
					break;
				case 12:
					if (central->getListaPuestos()->listaVacia() == false) {
						AnalizadorArchivos::ingresarEmpleados(central->getListaEmpleados(), central->getListaPuestos());
						
					}
					else {
						cout << "No hay puestos disponibles a contratar" << endl;
						system("pause");
					}
					break;
				default:
					string p;
					throw p;
					break;
		  


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