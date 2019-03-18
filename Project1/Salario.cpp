#include "Salario.h"



Salario::Salario(double SALARIO)
{
	salarioBase = SALARIO;
	salarioMensual = false;
	ahorroEscolarxQuin = 0;
	ahorroNavidadxQuin = 0;
}

double Salario::getSalarioBase()
{
	return salarioBase;
}

double Salario::getAhorroEscolarxQuin()
{
	return ahorroEscolarxQuin;
}

double Salario::getAhorroNavidadxQuin()
{
	return ahorroNavidadxQuin;
}

void Salario::setSalarioBase(double salab)
{
	salarioBase = salab;
}

void Salario::setAhorroEscolar(double ahorroEs)
{
	ahorroEscolarxQuin = ahorroEs;
}

void Salario::setAhorroNavidad(double ahorroNav)
{
	ahorroNavidadxQuin = ahorroNav;
}

int Salario::getSalarioNeto()
{
	double total = getSalarioBruto();
	total = total - getDeducciones();
	return (int)total;
	
	
}


double Salario::getDeducciones()
{
	double limite = 1200000;
	if (getSalarioBruto() > limite) {
		double total = getSalarioBruto(), diferenciaRenta, cargaSocial, ahorro, renta, deduccion;
		cargaSocial =  (total*0.09);//Cargas Sociales
		ahorro =  (total*0.02);
		diferenciaRenta = ( total- limite);
		renta =  (diferenciaRenta*0.20);
		deduccion = (cargaSocial + ahorro + renta);
		return deduccion;
	}
	else
	{
		double total = getSalarioBruto(), cargaSocial, ahorro, deduccion = 0;
		cargaSocial = (total*0.09);//Cargas Sociales
		ahorro = (total*0.02);
		deduccion = cargaSocial + ahorro ;
		return deduccion;
	}
}

double Salario::getSalarioBruto(double adic)
{
	return(salarioBase + adic);
}

string Salario::proximaFechaPago()
{
	string fecha = Herramientas::obtenerFecha();
	string anno, mes, dia;
	for (int i = 0; i < 10; i++) {
		if (i < 4) {
			anno = anno + fecha[i];

		}
		else if(i==5||i==6){
			mes = mes + fecha[i];
		}
		else
			if (i == 8 || i == 9) {
				dia = dia + fecha[i];
			 }
	}

	int anno2, mes2, dia2;
	anno2 = Herramientas::convertirInt(anno);
	mes2 = Herramientas::convertirInt(mes);
	dia2 = Herramientas::convertirInt(dia);
	if (salarioMensual == true) {
		if (mes2 == 12) {
			mes2 = 01;
			anno2++;
		}
		else
			mes2++;
	}
	else
	{
		if (dia2 < 15||dia2==31) {
			dia2 = 15;
		}
		else if (dia2 > 15 && dia2<30) {
			dia = 30;
		}

		if (mes2 == 12) {
			mes2 = 01;
			anno2++;
		}
		else
			mes2++;
	}
	string fechaPago = anno2 + "-" + mes2+ '-' + dia2;
	return fechaPago;
}

Salario::~Salario()
{
}
