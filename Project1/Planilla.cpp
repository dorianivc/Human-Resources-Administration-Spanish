#include "Planilla.h"



Planilla::Planilla(Fecha* fechaIncio, Empleado* newEmpleado, Puesto* newPuesto,bool temp):Contrato( newEmpleado, newPuesto, fechaIncio)
{
	esTemporal = temp;
	ahorroEscolar = 0;
	ahorroNavidad = 0;
	activo = true;
	
	fechaUltimasVacaciones = new Fecha (getFecha());
	ultimoPagoAguinaldo = new Fecha	(getFecha());
	porcentajeAhorroEscol = 0;
	porcentajeAhorroNav = 0;

}

int Planilla::vacacionesAcumuladas(Fecha*p)
{
	unsigned dias = getFecha()->Distancia(getFecha(), p);
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

const string Planilla::pagarAguinaldo(Fecha * p)
{
	stringstream k;
	k <<  "Pago de Aguinaldo a la fecha: " << p->toStringFecha() << "correspondiente al empleado" << getEmpleado()->getNombre() << " " << getEmpleado()->getApellidos() << " Cedula: " << getEmpleado()->getCedula() << endl;
	k << "Monto acumulado: " << calculcarAguinaldo(p)<< endl;
	ultimoPagoAguinaldo = new Fecha(p);
	k << "-------- Pago de aguinaldo realizado con exito-----------" << endl;
	return k.str();

}



const string Planilla:: otorgarVacaciones(Fecha * p)
{
	stringstream k;
	if (vacacionesAcumuladas(p) > 0) {
		k << "Otorgando "<< vacacionesAcumuladas(p) << " Dias de Vacaciones" << " correspondiente al empleado" << getEmpleado()->getNombre() << " " << getEmpleado()->getApellidos() << " Cedula: " << getEmpleado()->getCedula() << endl;
		fechaUltimasVacaciones = p;
	}
	else {
		k<< "No posee dias de vacaciones" << endl;
	}
	return k.str();
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


const bool Planilla::pagarAhorro()
{
	addAhorroEscolar();
	addAhorroNavidad();
	return true;
}

double Planilla::calculcarAguinaldo(Fecha* aCalcular)
{
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

const void Planilla::viajarEnElTiempo(Fecha * fechaAViajar)
{
	int dias=getFecha()->Distancia(getFecha(), fechaAViajar);
	if (dias > 29) {
		int veces = dias / 30;
		for (int i = 0; i < veces; i++) {
			pagarAhorro();
		}
		if (esTemporal == true && dias >= 90) {
			esTemporal = false;
		}
	}
}

void Planilla::setUltimoPagoAguinaldo(Fecha * p)
{
	delete ultimoPagoAguinaldo;
	ultimoPagoAguinaldo = new Fecha(p);
}

const string Planilla::retirarAhorros(Fecha* p)
{
	stringstream k;
	k<< "Retiro de Ahorro de " << getEmpleado()->getNombre() << " " << getEmpleado()->getApellidos() << "  Cedula: " << getEmpleado()->getCedula() << endl;
	k << "Montos ahorrados a la fecha: " << p->toStringFecha() << endl;
	k << "Ahorro de Navidad: " <<(long) ahorroNavidad << endl;
	k << "Ahorro Escolar: " << (long)ahorroEscolar << endl;
	k << "Total de ahorro: " << (long)(ahorroEscolar + ahorroNavidad) << endl;
	ahorroEscolar = 0;
	ahorroNavidad = 0;
	k << "-------- Ahorros retirados con exito -----------" << endl;
	return k.str();


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

 const string  Planilla::imprimirColillaDePago(Fecha*  fechaPago, double p1)
{
	int limite = 1200000;
	stringstream p;
	p << "Colilla de Pago" << "     " << "Fecha: " << fechaPago->toStringFecha() << "    " << "Pago Correspondiente al Mes: " << fechaPago->getMes()  << endl;
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
	p << "Dias de Vacaciones::: " << vacacionesAcumuladas(fechaPago) << endl;
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

const int Planilla::calcularCesantia(Fecha * fechaACalcular)
{
	int dias = getFecha()->Distancia(getFecha(), fechaACalcular);
	if (dias > 0) {
		if (dias > 11) {
			int diasCesantia = (dias / 12);
			if (diasCesantia > 240) {
				diasCesantia = 240;
				return diasCesantia;
			}
			else if(diasCesantia<=240&&diasCesantia>0) {
				return diasCesantia;
			}
		}

	}
	else return 0;
}

const string Planilla::cesarEmpleado(Fecha * fechaACesar)
{
	stringstream p;
	p << "Cesando empleado: " << endl;
	p << toString() << endl;
	p << "Dias de vacaciones acumuladas a pagar : " << vacacionesAcumuladas(fechaACesar) << endl;
	p << "Monto a cancelar por vacaciones: " << (long)((vacacionesAcumuladas(fechaACesar))*getPuesto()->getSalarioDiario()) << endl;
	p << "Dias a pagar por cesantia (Garantia de Ley) : " << (calcularCesantia(fechaACesar)) << endl;
	p << "Monto a pagar por censantia: " << (int)((calcularCesantia(fechaACesar))*getPuesto()->getSalarioDiario());
	p << "Monto a cancelar de aguinaldo: " << (long)calculcarAguinaldo(fechaACesar) << endl;
	p << "Monto a cancelar por ahorro escolar: " << (long)ahorroEscolar << endl;
	p << "Monto a cancear por ahorro navidad: " << (long)ahorroNavidad << endl;
	double suma = (vacacionesAcumuladas(fechaACesar)) + (((vacacionesAcumuladas(fechaACesar))*getPuesto()->getSalarioDiario())) + (((calcularCesantia(fechaACesar))*getPuesto()->getSalarioDiario()) + (calculcarAguinaldo(fechaACesar)))+ ahorroEscolar+ahorroNavidad;
	p << "Total a Cancelar por la empresa: " << (long)suma << endl;
	ultimoPagoAguinaldo = fechaACesar;
	fechaUltimasVacaciones = fechaACesar;
	porcentajeAhorroEscol = 0;
	porcentajeAhorroNav = 0;
	activo = false;
	return p.str();
	
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
	p << puesto1->toString() << endl;
	if (esTemporal) {
		
		p <<"Tipo de Empleado: " << "EMPLEADO TEMPORAL" << endl;

	}
	else {
		p << "Tipo de Empleado: " << "EMPLEADO EN PROPIEDAD" << endl;
	}
	
	return p.str();
}


Planilla::~Planilla()
{
}
