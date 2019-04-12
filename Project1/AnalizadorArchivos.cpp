#include "AnalizadorArchivos.h"





void AnalizadorArchivos::ingresarPuestos(ListaPuestos * lista)
{
	ifstream puestos;
	puestos.open("Puestos.txt");
	if (!puestos.bad()&&!puestos.fail()) {
		while (!puestos.eof()) {
			string nombre, codigo, descripcion, salarioBase;;
			double conversionSalarioBase = 0;
			int conversionCodigo = 0;
			getline(puestos, nombre, ',');
			getline(puestos, codigo, ',');
			conversionCodigo = atoi(codigo.c_str());
			getline(puestos, descripcion, ',');
			getline(puestos, salarioBase, ';');
			conversionSalarioBase = atof(salarioBase.c_str());
			if (codigo.length() > 1&& lista->existePosicion(conversionCodigo)!=true) {
				lista->insertarSinRegistrar(new Puesto(nombre, conversionCodigo, descripcion, conversionSalarioBase));
			}
			else if(lista->existePosicion(conversionCodigo) ==true) {
				cout << "Puesto Codigo: " << conversionCodigo << " YA EXISTE esta asignando a --->" << endl<< lista->getPosicion(conversionCodigo)->toString() << endl;
				
			}
			
		}
		
	}
	else {
		cout << "No hay registro de Empleados" << endl;
		
	}

	puestos.close();
	system("pause");
}

void AnalizadorArchivos::ingresarEmpleados(ListaContratos * lista, ListaPuestos* puestos)
{
	ifstream planilla;
	planilla.open("ListaEmpleadosPlanilla.txt");
	if (!planilla.bad() && !planilla.fail()) {
		while (!planilla.eof()) {
			string dia, mes, ano, cedula, nombre, apellidos, fechaNacimiento, direccion, telefono, temporalidad, codigoPuesto;
			int DIA, MES, ANO, CEDULA, TEMPORALIDAD, CODIGOPUESTO;
			bool temp;
			getline(planilla, dia, ',');
			getline(planilla, mes, ',');
			getline(planilla, ano, ',');
			getline(planilla, cedula, ',');
			DIA = atoi(dia.c_str());
			MES = atoi(mes.c_str());
			ANO = atoi(ano.c_str());
			CEDULA = atoi(cedula.c_str());
			getline(planilla, nombre, ',');
			getline(planilla, apellidos, ',');
			getline(planilla, fechaNacimiento, ',');
			getline(planilla, direccion, ',');
			getline(planilla, telefono, ',');
			getline(planilla, temporalidad, ',');
			TEMPORALIDAD = atoi(temporalidad.c_str());
			getline(planilla, codigoPuesto, ';');
			CODIGOPUESTO = atoi(codigoPuesto.c_str());
			if (TEMPORALIDAD == 0) {
				temp = false;
			}
			else {
				temp = true;
			}
			if (DIA > 0) {
				if (puestos->existePosicion(CODIGOPUESTO) == true) {
					if (lista->existePosicion(CEDULA) == false) {
						lista->insertarSinRegistrar(new Planilla(new Fecha(DIA, MES, ANO), new Empleado(CEDULA, nombre, apellidos, fechaNacimiento, direccion, telefono), puestos->getPosicion(CODIGOPUESTO), temp));
					}
					else {
						cout << "Ya existe otro empleado asociado a el numero de cedula: " << CEDULA << endl;
						cout << "Corresponde a: " << lista->getPosicion(CEDULA)->toString() << endl;
						
					}
				}
				else {
					cout << "NO EXISTE UN PUESTO PARA ASOCIAR AL EMPLEADO: " << nombre << " " << apellidos << " Cedula: " << cedula << endl;
					
				}
			}
		}
	}
	else {
		cout << "ERROR AL CARGAR EL ARCHIVO ListaEmpleadosPlanilla.txt: ARCHIVO NO EXISTE O EN MAL ESTADO "<< endl;
		
	}
	
	
	//----------------------------SERVICIOS PROFESIONALES------------------------------------------//

	ifstream profesionales; 
	profesionales.open("ListaEmpleadosServiciosProfesionales.txt");
	if (!profesionales.fail() && !profesionales.bad()) {

		while (!profesionales.eof()) {
			string dia, mes, ano, cedula, nombre, apellidos, fechaNacimiento, direccion, telefono, codigoPuesto, diaC, mesC, anoC;
			int DIA, MES, ANO, CEDULA, CODIGOPUESTO, DIAC, MESC, ANOC;
			bool temp;
			getline(profesionales, dia, ',');
			getline(profesionales, mes, ',');
			getline(profesionales, ano, ',');
			getline(profesionales, cedula, ',');
			DIA = atoi(dia.c_str());
			MES = atoi(mes.c_str());
			ANO = atoi(ano.c_str());
			CEDULA = atoi(cedula.c_str());
			getline(profesionales, nombre, ',');
			getline(profesionales, apellidos, ',');
			getline(profesionales, fechaNacimiento, ',');
			getline(profesionales, direccion, ',');
			getline(profesionales, telefono, ',');
			getline(profesionales, codigoPuesto, ',');
			getline(profesionales, diaC, ',');
			getline(profesionales, mesC, ',');
			getline(profesionales, anoC, ';');
			CODIGOPUESTO = atoi(codigoPuesto.c_str());
			DIAC = atoi(diaC.c_str());
			MESC = atoi(mesC.c_str());
			ANOC = atoi(anoC.c_str());
			
			if (DIA !=0 &&CEDULA!=0&&nombre.length()!=0&&CODIGOPUESTO!=0) {
				if (puestos->existePosicion(CODIGOPUESTO) == true) {
					if (lista->existePosicion(CEDULA) == false) {
						
						lista->insertarSinRegistrar(new ServiciosProfesionales(new Fecha(DIA, MES, ANO), new Empleado(CEDULA, nombre, apellidos, fechaNacimiento, direccion, telefono), puestos->getPosicion(CODIGOPUESTO), new Fecha(DIAC, MESC,ANOC)));
					}
					else {
						cout << "Ya existe otro empleado asociado a el numero de cedula: " << CEDULA << endl;
						cout << "Corresponde a: " << lista->getPosicion(CEDULA)->toString() << endl;
						
					}
				}
				else {
					cout << "NO EXISTE UN PUESTO PARA ASOCIAR AL EMPLEADO: " << nombre << " " << apellidos << " Cedula: " << cedula << endl;
					
				}
			}
		}
		
		
	}
	else {
		cout << "Error al abrir el archivo: ListaEmpleadosServiciosProfesionales.txt : NO EXISTE O EN MAL ESTADO" << endl;
	}

	profesionales.close();
	planilla.close();
	system("pause");
}


