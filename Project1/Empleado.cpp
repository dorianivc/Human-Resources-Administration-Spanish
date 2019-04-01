#include "Empleado.h"



Empleado::Empleado(string ced, string nom, string apell, string fNac, string dir, string numTel)
{
	this->cedula = ced;
	this->nombre=nom;
	this->apellidos = apell;
	this->fechaNacimiento = fNac;
	this->direccion = dir;
	this->numeroTelefono = numTel;
	
}

string Empleado::getNombre()
{
	return nombre;
}

void Empleado::setNombre(string newNombre)
{
	nombre = newNombre;
}

string Empleado::getCedula()
{
	return cedula;
}

void Empleado::setCedula(string newCedula)
{
	cedula = newCedula;
}

string Empleado::getApellidos()
{
	return apellidos;
}

void Empleado::setApellidos(string newApellido)
{
	apellidos = newApellido;
}

string Empleado::getFechaNacimiento()
{
	return fechaNacimiento;
}

void Empleado::setFechaNacimiento(string newFecha)
{
	fechaNacimiento = newFecha;
}

string Empleado::getDireccion()
{
	return direccion;
}

void Empleado::setDireccion(string dir)
{
	direccion = dir;
}

string Empleado::getTelefono()
{
	return numeroTelefono;
}

void Empleado::setTelefono(string newPhone)
{
	numeroTelefono = newPhone;
}

string Empleado::toString()
{
	stringstream p;
	p << "Cedula: " << cedula << "           " << " Nombre:  " << nombre << "    " << " Apellidos: " << apellidos << endl;
	p << "Fecha de Nacimiento: " << fechaNacimiento << " Direccion: " << direccion << " Numero de Telefono: " << numeroTelefono << endl;
	p << endl;
	return p.str();
}



Empleado::~Empleado()
{
}
