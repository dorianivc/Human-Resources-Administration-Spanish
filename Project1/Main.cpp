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
#include <fstream>
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
	
	bool exito = 0;
	//---------------------FIN: Creacion de la empresa------------------------//

	//--------------------Creacion de Menu Principal-------------------------//
	unsigned eleccionMenuPrincipal;
	bool salirMenu = 0;
	int aux3 = 0;
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
		cout << "(13) --> Darle Mantenimiento a los puestos" << endl;
		cout << "(14) --> Darle Mantenimiento a empleados" << endl;
		cout << "(15) --> Modificar datos de la empresa" << endl;
		cout << "(16) --> Modificar datos de ahorro de empleados" << endl;
		cout << "(17) --> SALIR" << endl;

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
			double auxDouble;
			bool esTemporal;
			string p;
			int cedEmpleado;
			bool exito = 0;
			int dia, mes, ano;
			int aux = 0;
			int cedAux;
			int aux2 = 0;
			int subEleccion;
			ofstream registroCese;
			Fecha* fechaAviajar = NULL;
			string auxString;
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
				if (central->getListaPuestos()->listaVacia() == false) {
					cin.ignore();

					exito = 0;
					cout << "ELIMINANDO PUESTO" << endl;
					cout << endl;
					cout << central->getListaPuestos()->toString() << endl;
					cout << endl;
					cout << endl;
					do {
						cout << "Digite el codigo del puesto a eliminar" << endl;
						cin >> codigoPuesto;
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
				}
				else {
					cout << "No existen puestos para eliminar" << endl;
					system("pause");
				}
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
								
								cout << "Es el puesto de : " << nombreEmpleado << " " << apellidoEmpleado << "  TEMPORAL?" << endl;
								cout << "Digite enter" << endl;
								cin.ignore();

								cout << "Digite 1 si es Temporal" << endl;
								cout << "Digite 0 si es a Propiedad" << endl;



								cin >> esTemporal;

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
				case 17:
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
				case 13://MANTENIMIENTO DE PUESTOS
					cout << "Digite enter" << endl;
					cin.ignore();
					if (central->getListaPuestos()->listaVacia() == false) {
						cout << central->getListaPuestos()->toString() << endl;
						cout << "Digite el codigo de puesto al que desea darle mantenimiento" << endl;
						cin >> aux;
						if (central->getListaPuestos()->existePosicion(aux)) {
							cout << central->getListaPuestos()->getPosicion(aux)->toString() << endl;
							cout << "Digite 1 para cambiarle el nombre al puesto" << endl;
							cout << "Digite 2 para cambiarle el codigo al puesto" << endl;
							cout << "Digite 3 para modificaer la descripcion del puesto" << endl;
							cout << "Digite 4 para modificar el salario base" << endl;
							try {
								cin >> aux3;
								switch (aux3) {
									
								case 1:
									cout << "Digite enter" << endl;
									cin.ignore();
									system("cls");
									
									cout << "Ingrese el nuevo nombre" << endl;
									getline(cin, auxString);
									cout << "---->" << auxString << endl;
									central->getListaPuestos()->getPosicion(aux)->setNombre(auxString);
									cout << "Nombre modificado con exito" << endl;
									cout<<central->getListaPuestos()->getPosicion(aux)->toString();
									break;
								case 2:
									cout << "Digite enter" << endl;
									cin.ignore();
									system("cls");
									cout << "Digite el nuevo codigo" << endl;
									cin >> aux2;
									if (central->getListaPuestos()->existePosicion(aux2)) {
										cout << "Ya existe un puesto asociado al codigo --> " << aux << " corresponde a : " << central->getListaPuestos()->getPosicion(aux2)->toString() << endl;
										system("pause");
									}
									else {
										central->getListaPuestos()->getPosicion(aux)->setCodigo(aux2);
										cout << "Codigo modificado con exito" << endl << central->getListaPuestos()->getPosicion(aux2)->toString()<<endl;
										system("pause");


									}

									break;
								case 3:
									cout << "Digite enter" << endl;
									cin.ignore();
									system("cls");
									cout << "Digite la nueva descripcion del puesto "<< central->getListaPuestos()->getPosicion(aux)->getNombre()<<" Codigo: "<< central->getListaPuestos()->getPosicion(aux)->getCodigo()<< endl;
									getline(cin, auxString);
									central->getListaPuestos()->getPosicion(aux)->setDescripcion(auxString);
									cout << "Descripcion modificada con exito" << endl;
									system("pause");
									break;
								case 4:
									cout << "Digite enter" << endl;
									cin.ignore();
									system("cls");
									cout << "Digite el nuevo salario base del puesto" << central->getListaPuestos()->getPosicion(aux)->getNombre() << " Codigo: " << central->getListaPuestos()->getPosicion(aux)->getCodigo() << endl;
									cin >> auxDouble;
									central->getListaPuestos()->getPosicion(aux)->setSalarioBase(auxDouble);
									cout << "Salario modificado con exito" << endl;
									system("pause");
								default:
									auxString = "Opcion ingresada invalida";
									throw auxString;
								}
								
							}
							catch (string p) {
								cout << "Exepcion producida: " << p << endl;
								system("pause");
							}
						}
						else { cout << "Puesto No existe" << endl;
						system("pause");
						}
					}
					else {
						cout << "No hay puestos disponibles" << endl;
						system("pause");
					}

					break;
				case 14://MANTENIMIENTO DE EMPLEADOS
					if (central->getListaEmpleados()->listaVacia() == false) {
						cout << "Digite enter una vez" << endl;
						cin.ignore();
						system("cls");
						cout << "Digite el numero de cedula del empleado a modificar" << endl;
						cin >> aux;
						if (central->getListaEmpleados()->existePosicion(aux) == true) {
							cout << "Digite enter" << endl;
							cin.ignore();
							system("cls");
							cout << central->getListaEmpleados()->getPosicion(aux)->toString() << endl;
							cout << "Digite 1 si desea modificar el nombre del empleado" << endl;
							cout << "Digite 2 si desea modificar los apellidos del empleado" << endl;
							cout << "Digite 3 si desea cambiar la fecha de nacimiento del empleado" << endl;
							cout << "Digite 4 si desea modificar la direccion del empleado" << endl;
							cout << "Digite 5 si desea modificar el numero de telefono del empleado" << endl;
							cin >> aux2;
							try {
								switch (aux2) {
								default: auxString = "Eleccion ingresada invalida";
									throw auxString;
									break;
								case 1:
									cout << "Digite enter una vez" << endl;
									cin.ignore();
									system("cls");
									cout << "Digite el nuevo nombre del empleado" << endl;
									getline(cin, auxString);
									central->getListaEmpleados()->getPosicion(aux)->getEmpleado()->setNombre(auxString);
									cout << "Nombre modificado con exito" << endl;
									system("pause");
									break;
								case 2:
									cout << "Digite enter una vez" << endl;
									cin.ignore();
									system("cls");
									cout << "Digite los nuevos apellidos del empleado" << endl;
									getline(cin, auxString);
									central->getListaEmpleados()->getPosicion(aux)->getEmpleado()->setApellidos(auxString);
									cout << "Apellidos modificados con exito" << endl;
									system("pause");
									break;
								case 3:
									cout << "Digite enter una vez" << endl;
									cin.ignore();
									system("cls");
									cout << "Digite la nueva fecha de nacimiento del empleado" << endl;
									getline(cin, auxString);
									central->getListaEmpleados()->getPosicion(aux)->getEmpleado()->setFechaNacimiento(auxString);
									cout << "Fecha de nacimiento modificado con exito" << endl;
									system("pause");
									break;
								case 4:
									cout << "Digite enter una vez" << endl;
									cin.ignore();
									system("cls");
									cout << "Digite la nueva direccion del empleado" << endl;
									getline(cin, auxString);
									central->getListaEmpleados()->getPosicion(aux)->getEmpleado()->setDireccion(auxString);
									cout << "Direccion modificada con exito" << endl;
									system("pause");
									break;
								case 5:
									cout << "Digite enter una vez" << endl;
									cin.ignore();
									system("cls");
									cout << "Digite el nuevo numero de telefono del empleado" << endl;
									getline(cin, auxString);
									central->getListaEmpleados()->getPosicion(aux)->getEmpleado()->setTelefono(auxString);
									cout << "Telefono modificado con exito" << endl;
									system("pause");
									break;
								}
							}
							catch (string j) {
								cout << "Exepcion producida: " << j << endl;
								system("pause");
							}
						}else {
							cout << "Empleado no existe" << endl;
							system("pause");
						}
					}
					else {
						cout << "No hay empleados para modificar o mantener" << endl;
						system("pause");
					}
					break;
				case 15:
					cout << "Digite enter una vez" << endl;
					cin.ignore();
					system("cls");
					cout << "Digite 1 para cambiar la direccion de la empresa" << endl;
					cout << "Digite 2 para cambiar el numero de telefono de la empresa" << endl;
					cin >> aux;
					if (aux == 1) {
						cout << "Digite enter una vez" << endl;
						cin.ignore();
						system("cls");
						cout << "Digite la nueva direccion de la empresa" << endl;
						getline(cin, auxString);
						central->setDireccion(auxString);
						cout << "Cambio de direccion de la empresa realizado con exito" << endl;
						cout << central->toString() << endl;
						system("pause");
					}
					else if (aux == 2) {

						cout << "Digite enter una vez" << endl;
						cin.ignore();
						system("cls");
						cout << "Digite el nuevo numero de telefono de la empresa" << endl;
						getline(cin, auxString);
						central->setTelefono(auxString);
						cout << "Cambio de numero de telefono de la empresa realizado con exito" << endl;
						cout << central->toString() << endl;
						system("pause");
					}
					else {
						cout << "Eleccion invalida" << endl;
						system("pause");
					}
					break;
				case 16:
					cout << "Digite enter una vez" << endl;
					cin.ignore();
					system("cls");
					if (central->getListaEmpleados()->listaVacia() == false) {
						cout << "Digite el numero de cedula del empleado a modificar porcentaje de ahorros" << endl;
						cin >> aux;
						if (central->getListaEmpleados()->existePosicion(aux)) {
							cout << "Digite enter una vez" << endl;
							cin.ignore();
							system("cls");
							if (central->getListaEmpleados()->getPosicion(aux)->esPlanilla() == true) {
								cout << "Digite 1 si desea modificar el ahorro escolar" << endl;
								cout << "Digite 2 si desea modificar el ahorro de navidad" << endl;
								cin >> aux2;
								if (aux2 == 1) {
									cout << "Digite enter una vez" << endl;
									cin.ignore();
									system("cls");
									cout << "Digite el porcentaje de ahorro que desea actualizar" << endl;
									cin >> aux3;
									if (aux3 >= 0) {
										central->getListaEmpleados()->getPosicion(aux)->setAhorroEscolar(aux3);
									}
									else {
										cout << "El porcentaje introducido es menor al permitido" << endl;
									}
								}
								else if (aux2 == 2) {
									cout << "Digite enter una vez" << endl;
									cin.ignore();
									system("cls");
									cout << "Digite el porcentaje de ahorro que desea actualizar" << endl;
									cin >> aux3;
									if (aux3 >= 0) {
										central->getListaEmpleados()->getPosicion(aux)->setAhorroNavidad(aux3);
									}
									else {
										cout << "El porcentaje introducido es menor al permitido" << endl;
									}
								}
								else {
									cout << "Eleccion invalida" << endl;
								}
							}
							else {
								cout << "El empleado que usted desea modificar no tiene contemplado ahorros en el contrato" << endl;
							}
						}
						else {
							cout << "El empleado ingresado no existe" << endl;
						}
					}
					else {
						cout << "No hay empleados para modificar" << endl;
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