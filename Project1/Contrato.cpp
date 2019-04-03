#include "Contrato.h"



Contrato::Contrato(string fecha, Empleado* empl, Puesto* pues)
{
	this->fecha = fecha;
	empleado = empl;
	puesto = pues;
	
	
}

Empleado * Contrato::getEmpleado()
{
	return empleado;
}

void Contrato::setEmpleado(Empleado * p)
{
	empleado = p;
}

Puesto * Contrato::getPuesto()
{
	return puesto;
}

void Contrato::setPuesto(Puesto * newPuesto)
{
	puesto = newPuesto;
}

string Contrato::getFecha()
{
	return fecha;
}

const string Contrato::toString()
{
	stringstream p;

	p << "Fecha Inicio de Contrato: " << fecha << endl;
	p <<"Empleado: "<< empleado->toString() << endl;
	p << "Puesto: " << puesto->toString() << endl;
	return p.str();
}

double Contrato::getSalarioNeto()
{
	if (esPlanilla()) {
		return (puesto->getSalarioBruto() - puesto->getDeducciones(puesto->getSalarioBase()));
	}
	else
		return puesto->getSalarioBruto();
	
}

string Contrato::verColillaPago()
{
	stringstream p;
	double limite = 1200000;
	double k = getSalarioNeto();
	double kk = puesto->getSalarioBase();
	p << "Cedula:  " << empleado->getCedula() << " " << "Nombre Completo: " << empleado->getNombre() << " " << empleado->getApellidos() << endl;
	p << "Codigo de Puesto: " <<puesto->getCodigo() <<" -> "<< puesto->getNombre() << endl;
	p << "Salario Base: " << (long)(kk) << endl;
	if (esPlanilla()) {
		p << "Regalias: " << (long)(puesto->getSalarioBruto() - puesto->getSalarioBase()) << endl;
		p << "Deducciones: " << endl;
		p << "Carga Social  ---> " << (long)(puesto->getSalarioBase()*-0.09) << endl;
		p << "Ahorro Oblgatorio ---> " << (long)(puesto->getSalarioBase()*-0.02) << endl;
		
		if (puesto->getSalarioBase() >= limite) {
			p << "Impuesto de la renta---> " << (long)((puesto->getSalarioBase() - limite)*-0.20) << endl;
			
		}
		p << "Ahorros: " << endl;
		p << "Ahorro Navidad: " << (long)(puesto->getAhorroNavidad()) << endl;
		p << "Ahorro Salario Escolar: " << (long)(puesto->getAhorroSalEscolar()) << endl;
		p << "Total Ahorros: " << (long)(puesto->getAhorroNavidad() + puesto->getAhorroSalEscolar()) << endl;
		p << "Salario Bruto: " << (long)puesto->getSalarioBruto() << endl;
		p << "Total de deducciones ---> " << (long)(puesto->getDeducciones(puesto->getSalarioBase())*-1) << endl;
		p << "Salario Neto:" << (long)(k) << endl;
		p << "-----------Fin----------" << endl;
	}
		else {
			p << "Salario Bruto: " << (long)puesto->getSalarioBruto() << endl;
			p << "Salario Neto:" << (long)(k) << endl;
			p << "-----------Fin----------" << endl;

		}
		

	
	return p.str();

}



Contrato::~Contrato()
{
	
}
