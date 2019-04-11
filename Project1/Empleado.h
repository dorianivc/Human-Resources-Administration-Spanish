#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
using namespace std;
class Empleado
{private:
	int cedula;
	string nombre;
	string apellidos;
	string fechaNacimiento;
	string direccion;
	string numeroTelefono;
public:
	Empleado(int, string, string, string,string, string);
	string getNombre();
	void setNombre(string);
	int getCedula();
	void setCedula(int);
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

