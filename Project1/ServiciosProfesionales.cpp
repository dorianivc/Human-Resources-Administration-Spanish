#include "ServiciosProfesionales.h"



ServiciosProfesionales::ServiciosProfesionales(Fecha* fechaActual, Empleado* newEmpleado, Puesto* newPuesto, Fecha* fechaCesantia):Contrato( newEmpleado, newPuesto, fechaActual)
{
	this->fechaCesantia = fechaCesantia;
	activo = true;
}

const string ServiciosProfesionales::toString()
{
	stringstream p;
	p <<"CONTRATO POR SERVICIOS PROFESIONALES" << endl;
	p << "Fecha de Inicio Contrato: " << getFechaToString() << endl;
	p << "Fecha de Cesantia: " << fechaCesantia << endl;
	p << getEmpleado()->toString();
	p << getPuesto()->toString() << endl;
	p << "Empleado activo: "; if (activo) {
		p << "SI" << endl;

	}
	else {
		p << "NO" << endl;
	}
	return p.str();
	
}

const bool ServiciosProfesionales::esPlanilla()
{
	return false;
}

const bool ServiciosProfesionales::pagarAhorro()
{
	return false;
}

const string ServiciosProfesionales::pagarAguinaldo(Fecha * p1)
{
	stringstream p;
	p << "Fecha: " << p1->toStringFecha() << endl;
	p << "Empleado: " << getEmpleado()->getNombre() << " " << getEmpleado()->getApellidos() << " Cedula: " << getEmpleado()->getCedula() << endl;
	p << "Tipo de Contrato no contempla el pago de aguinaldo" << endl;
	return p.str();

}

const string ServiciosProfesionales::otorgarVacaciones(Fecha * p1)
{
	stringstream p;
	p << "Fecha: " << p1->toStringFecha() << endl;
	p << "Empleado: " << getEmpleado()->getNombre() << " " << getEmpleado()->getApellidos() << " Cedula: " << getEmpleado()->getCedula() << endl;
	p << "Tipo de Contrato no contempla el pago de Vacaciones" << endl;
	return p.str();
}

const int ServiciosProfesionales::calcularCesantia(Fecha * fechaACalcular)
{
	int dias = getFecha()->Distancia(getFecha(), fechaACalcular);
	if (dias > 0) {
		if (dias > 11) {
			int diasCesantia = (dias / 12);
			if (diasCesantia > 240) {
				diasCesantia = 240;
				return diasCesantia;
			}
			else if (diasCesantia <= 240 && diasCesantia > 0) {
				return diasCesantia;
			}
		}

	}
	else return 0;
}

const void ServiciosProfesionales::viajarEnElTiempo(Fecha * fechaAViajar)
{
	int dias = getFecha()->Distancia(getFecha(), fechaAViajar);
	if (dias >= getFecha()->Distancia(getFecha(), fechaCesantia)) {
		cout << cesarEmpleado(fechaAViajar) << endl;
	}
}

const string ServiciosProfesionales::cesarEmpleado(Fecha * fechaACesar)
{
	stringstream p;
	p << "Cesando empleado: " << endl;
	p << "Fecha de cesantia: " << fechaACesar->toStringFecha() << endl;
	p << toString() << endl;
	p << "Dias a pagar por cesantia (Garantia de Ley) : " << (calcularCesantia(fechaACesar)) << endl;
	p << "Monto a pagar por censantia: " << (long)((calcularCesantia(fechaACesar))*getPuesto()->getSalarioDiario());
	p << "Monto a cancelar de aguinaldo: " << (long)calculcarAguinaldo(fechaACesar) << endl;
	double suma = ((calcularCesantia(fechaACesar))*getPuesto()->getSalarioDiario()) + calculcarAguinaldo(fechaACesar);
	fechaCesantia = fechaACesar;
	activo = false;
	p << "Total a Cancelar por la empresa: " << (long)suma << endl;
	
	
	return p.str();
}

double ServiciosProfesionales::calculcarAguinaldo(Fecha * aCalcular)
{
	unsigned dias = getFecha()->Distancia(getFecha(), aCalcular);
	double aux = getPuesto()->getSalarioBase() / 360;
	double aguinaldo = (double)dias*  aux;
	return aguinaldo;
}



 const string ServiciosProfesionales::imprimirColillaDePago(Fecha* q, double p)
{
	return "REALIZAR COLILLA DE SERV PROFESIONALES";
}

 const string ServiciosProfesionales::retirarAhorros(Fecha * p1)
 {
	 stringstream p;
	 p << "Fecha: " << p1->toStringFecha() << endl;
	 p << "Empleado: " << getEmpleado()->getNombre() << " " << getEmpleado()->getApellidos() << " Cedula: " << getEmpleado()->getCedula() << endl;
	 p << "Tipo de Contrato no permite programarle ahorros" << endl;
	 return p.str();
 }

ServiciosProfesionales::~ServiciosProfesionales()
{
}
