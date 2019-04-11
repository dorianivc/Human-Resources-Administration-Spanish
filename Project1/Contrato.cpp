#include "Contrato.h"



Contrato::Contrato( Empleado* empl, Puesto* pues, Fecha* pFecha)
{
	this->fecha = pFecha;
	empleado = empl;
	puesto1 = pues;
	
	
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
	return puesto1;
}

void Contrato::setPuesto(Puesto * newPuesto)
{
	puesto1 = newPuesto;
}

string Contrato::getFechaToString()
{
	return fecha->toStringFecha();
}

Fecha * Contrato::getFecha()
{
	return fecha;
}



//const string Contrato::toString()
//{
//	stringstream p;
//
//	p << "Fecha Inicio de Contrato: " << fecha << endl;
//	p <<"Empleado: "<< empleado->toString() << endl;
//	p << "Puesto: " << puesto->toString() << endl;
//	return p.str();
//}



string Contrato::verColillaPago()
{
	stringstream p;
	double limite = 1200000;
	double kk = puesto1->getSalarioBase();
	p << "Cedula:  " << empleado->getCedula() << " " << "Nombre Completo: " << empleado->getNombre() << " " << empleado->getApellidos() << endl;
	p << "Codigo de Puesto: " <<puesto1->getCodigo() <<" -> "<< puesto1->getNombre() << endl;
	p << "Salario Base: " << (long)(kk) << endl;
	if (esPlanilla()) {
		//p << "Regalias: " << (long)(puesto->getSalarioBruto() - puesto->getSalarioBase()) << endl;
		p << "Deducciones: " << endl;
		p << "Carga Social  ---> " << (long)(puesto1->getSalarioBase()*-0.09) << endl;
		p << "Ahorro Oblgatorio ---> " << (long)(puesto1->getSalarioBase()*-0.02) << endl;
		
		if (puesto1->getSalarioBase() >= limite) {
			p << "Impuesto de la renta---> " << (long)((puesto1->getSalarioBase() - limite)*-0.20) << endl;
			
		}
		//p << "Ahorros: " << endl;
		//p << "Ahorro Navidad: " << (long)(puesto->getAhorroNavidad()) << endl;
		//p << "Ahorro Salario Escolar: " << (long)(puesto->getAhorroSalEscolar()) << endl;
		//p << "Total Ahorros: " << (long)(puesto->getAhorroNavidad() + puesto->getAhorroSalEscolar()) << endl;
		//p << "Salario Bruto: " << (long)puesto->getSalarioBruto() << endl;
		p << "Total de deducciones ---> " << (long)(puesto1->getDeducciones(puesto1->getSalarioBase())*-1) << endl;
		//p << "Salario Neto:" << (long)(k) << endl;
		
	}
		else {
	

		}
		

	
	return p.str();

}

const string Contrato::identificador()
{
	int p = empleado->getCedula();
	string chorizo = " " + p;
	return chorizo;
}



Contrato::~Contrato()
{
	
}
