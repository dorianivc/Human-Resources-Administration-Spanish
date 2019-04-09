#include "Planilla.h"



Planilla::Planilla(Fecha* fechaIncio, Empleado* newEmpleado, Puesto* newPuesto,bool temp):Contrato( newEmpleado, newPuesto, fechaIncio)
{
	esTemporal = temp;
	ahorroEscolar = 0;
	ahorroNavidad = 0;
	activo = true;
	aguinaldo = 0;
	fechaUltimasVacaciones = new Fecha (getFecha());
	ultimoPagoAguinaldo = new Fecha	(getFecha());
	diasvacacionesAcumuladas = 0;
	porcentajeAhorroEscol = 0;
	porcentajeAhorroNav = 0;

}

int Planilla::vacacionesAcumuladas()
{
	unsigned dias = getFecha()->Distancia(getFecha(), fechaUltimasVacaciones);
	//Calculo de Vacaciones
	if (dias < 24) {
		return 0;
	}
	else
	{
		int vacaciones = (dias / 24);
		return vacaciones;
	}
}

int Planilla::getPorcentajeAhorroNavidad()
{
	return porcentajeAhorroNav;
}

int Planilla::getPorcentajeAhorroEscolar()
{
	return this->porcentajeAhorroEscol;
}

void Planilla::setPorcentajeAhorroEscolar(int newPorcentaje)
{
	porcentajeAhorroEscol = newPorcentaje;
}

void Planilla::setPorcentajeAhorroNavidad(int newPorcentaje)
{
	porcentajeAhorroNav = newPorcentaje;
}

void Planilla::addAhorroNavidad()
{
	ahorroNavidad = ahorroNavidad + (double)((getSalarioBruto()* porcentajeAhorroNav) / 100);
}

void Planilla::addAhorroEscolar()
{
	ahorroEscolar = ahorroEscolar + (double)(getSalarioBruto()*porcentajeAhorroEscol / 100);
}

double Planilla::calculcarAguinaldo(Fecha* aCalcular)
{//CORREGIR;
	unsigned dias = getFecha()->Distancia(ultimoPagoAguinaldo, aCalcular);
	double aux = getPuesto()->getSalarioBase() / 360;
	double aguinaldo = (double)dias*  aux;
	return aguinaldo;
	
}

void Planilla::setFechaUltimaVacaciones(Fecha * p)
{
	delete fechaUltimasVacaciones;
	fechaUltimasVacaciones = new Fecha(p);

}

void Planilla::setUltimoPagoAguinaldo(Fecha * p)
{
	delete ultimoPagoAguinaldo;
	ultimoPagoAguinaldo = new Fecha(p);
}

double Planilla::getDeducciones(double p)
{
	double limite = 1200000;
	if (p > limite) {
		double total = p, diferenciaRenta, cargaSocial, ahorro, renta, deduccion;
		cargaSocial = (total*0.09);//Cargas Sociales
		ahorro = (total*0.02);
		diferenciaRenta = (total - limite);
		renta = (diferenciaRenta*0.20);
		int ahorroNav = total * porcentajeAhorroNav/100;
		int ahorroEsco = total * porcentajeAhorroEscol/100;
		deduccion = (cargaSocial + ahorro + renta+ ahorroEsco+ ahorroNav);
		return deduccion;
	}
	else
	{
		double total = p, cargaSocial, ahorro, deduccion = 0;
		cargaSocial = (total*0.09);//Cargas Sociales
		ahorro = (total*0.02);
		deduccion = cargaSocial + ahorro;
		int ahorroNav = total * porcentajeAhorroNav;
		int ahorroEsco = total * porcentajeAhorroEscol;
		deduccion = (cargaSocial + ahorro  + ahorroEsco + ahorroNav);
		return deduccion;
	}
}

string Planilla::imprimirColillaDePago(Fecha * fechaPago, double p1)
{
	int limite = 1200000;
	stringstream p;
	p << "Colilla de Pago" << "     " << "Fecha: " << fechaPago->toStringFecha() << "    " << "Pago Correspondiente al Mes: " << fechaPago->getMes() << endl;
	p << "Cedula: " << getEmpleado()->getCedula() << " " << "Nombre : " << getEmpleado()->getNombre() << " " << getEmpleado()->getApellidos() << endl;
	p << "Codigo de Puesto: " << getPuesto()->getCodigo() << "-->" << getPuesto()->getNombre() << endl;
	p << "Salario Bruto--> " <<(long) getSalarioBruto(p1) << endl;
	p << "Deducciones: " << endl;
	p << "Carga Social (9%) ---> " << (long)(getSalarioBruto(p1)*-9/100) << endl;
	p << "Ahorro Obligatorio (2%) ---> " << (long)(getSalarioBruto(p1)*-9/100) << endl;
	if (getSalarioBruto(p1) > limite) {
		int aCobrar = getSalarioBruto(p1) - limite;
		p << "Impuesto de la Renta(20%) ---> " << (long)(aCobrar*-20/100) << endl;
	}
	p << "Ahorro Navidad: "<< (long)((getSalarioBruto(p1)*porcentajeAhorroNav)/100) << " Porcentaje de ahorro ---> " << porcentajeAhorroNav << endl;
	p << "Ahorro Escolar: " << (long)((getSalarioBruto(p1)*porcentajeAhorroEscol) / 100) << " Porcentaje de ahorro ----> " << porcentajeAhorroEscol << endl;
	p << "Total de Deducciones: " << (long)getDeducciones(getSalarioBruto(p1))*-1 << endl;
	p << "Salario Neto: " << (long)getSalarioNeto(getSalarioBruto(p1)) << endl;
	p << "Ahorros:" << endl;
	p << "Ahorro Navidad: " << ahorroNavidad << endl;
	p << "Ahorro Escolar: " << ahorroEscolar << endl;
	p << "aguinaldo::::" << (long)calculcarAguinaldo(fechaPago) << endl;
	p << "-----------FIN-----------" << endl;
	return p.str();


}

double Planilla::getSalarioBruto(double regalia)
{
	return (getPuesto()->getSalarioBase() + regalia);
}

double Planilla::getSalarioNeto(double p)
{
	return( p - getDeducciones(p));
}



const bool Planilla::esPlanilla()
{
	return true;
}

const string Planilla::toString()
{
	stringstream p;
	p << "CONTRATO A PLANILLA";
	if (esTemporal) {
		p << " TEMPORAL" << endl;
	}
	else {
		p << " POR TIEMPO INDEFINIDO" << endl;
	}
	p << "Fecha de Inicio Contrato: " << getFechaToString() << endl;
	p << getEmpleado()->toString();
	if (esTemporal) {
		
		p <<"Tipo de Empleado: " << "EMPLEADO TEMPORAL" << endl;

	}
	else {
		p << "Tipo de Empleado: " << "EMPLEADO EN PROPIEDAD" << endl;
	}
	p << getPuesto()->toString() << endl;

	return p.str();
}


Planilla::~Planilla()
{
}
