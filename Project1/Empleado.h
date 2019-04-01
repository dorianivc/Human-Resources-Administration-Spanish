#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include  "Contrato.h"
using namespace std;
class Empleado
{private:
	string cedula;
	string nombre;
	string apellidos;
	string fechaNacimiento;
	string direccion;
	string numeroTelefono;
public:
	Empleado(string, string, string, string,string, string);
	string getNombre();
	void setNombre(string);
	string getCedula();
	void setCedula(string);
	string getApellidos();
	void setApellidos(string);
	string getFechaNacimiento();
	void setFechaNacimiento(string);
	string getDireccion();
	void setDireccion(string);
	string getTelefono();
	void setTelefono(string);
	string toString();
	~Empleado();
};

