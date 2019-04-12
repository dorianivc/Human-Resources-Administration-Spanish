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
	p << "Fecha de Cesantia: " << fechaCesantia->toStringFecha() << endl;
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

const string ServiciosProfesionales::getSerializacion()
{
	stringstream p;
	p << getFecha()->getDia() << "," << getFecha()->getMes() << "," << getFecha()->getAno() << "," << getEmpleado()->getCedula() << "," << getEmpleado()->getNombre() << "," << getEmpleado()->getApellidos() << "," << getEmpleado()->getFechaNacimiento() << "," << getEmpleado()->getDireccion() << "," << getEmpleado()->getTelefono() <<"," << getPuesto()->getCodigo() << ","<<fechaCesantia->getDia()<<","<<fechaCesantia->getMes()<<","<<fechaCesantia->getAno()<<";";
	return p.str();
}

double ServiciosProfesionales::getSalarioBruto(double p)
{
	return (getPuesto()->getSalarioBase() + p);
}

const void ServiciosProfesionales::setAhorroEscolar(int)
{
	
}

const void ServiciosProfesionales::setAhorroNavidad(int)
{
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
		system("pause");
	}
}

const string ServiciosProfesionales::cesarEmpleado(Fecha * fechaACesar)
{
	stringstream p;
	p << "Cesando empleado: " << endl;
	p << "Fecha de cesantia aplicada: " << fechaACesar->toStringFecha() << endl;
	p << toString() << endl;
	p << "Dias a pagar por cesantia (Garantia de Ley) : " << (calcularCesantia(fechaACesar)) << endl;
	p << "Monto a pagar por censantia: " << (long)((calcularCesantia(fechaACesar))*getPuesto()->getSalarioDiario()) << endl;
	p << "Monto a cancelar de aguinaldo: " << (long)calculcarAguinaldo(fechaACesar) << endl;
	double suma = ((calcularCesantia(fechaACesar))*getPuesto()->getSalarioDiario()) + calculcarAguinaldo(fechaACesar);
	fechaCesantia = fechaACesar;
	activo = false;
	p << "Total a Cancelar por la empresa: " << (long)suma << endl;
	activo = false;
	ofstream registroCese;
	registroCese.open("ListaExEmpleados.txt", ios::app);
	if (!registroCese.fail()) {
		registroCese << p.str() << endl;
	}
	else {
		cout << "Error al abrir el archivo ListaExEmpleados.txt " << endl;
	}
	registroCese.close();
	return p.str();
}

double ServiciosProfesionales::calculcarAguinaldo(Fecha * aCalcular)
{
	unsigned dias = getFecha()->Distancia(getFecha(), aCalcular);
	double aux = getPuesto()->getSalarioBase() / 360;
	double aguinaldo = (double)dias*  aux;
	return aguinaldo;
}



 const string ServiciosProfesionales::imprimirColillaDePago(Fecha* fechaPago, double p1)
{
	 int limite = 1200000;
	 stringstream p;
	 p << "Colilla de Pago POR SERVICIOS PROFESIONALES" << "     " << "Fecha: " << fechaPago->toStringFecha() << "    " << "Pago Correspondiente al Mes: " << fechaPago->getMes() << endl;
	 p << "Cedula: " << getEmpleado()->getCedula() << " " << "Nombre : " << getEmpleado()->getNombre() << " " << getEmpleado()->getApellidos() << endl;
	 p << "Codigo de Puesto: " << getPuesto()->getCodigo() << "-->" << getPuesto()->getNombre() << endl;
	 p << "Salario Bruto--> " << (long)getSalarioBruto(p1) << endl;
	 p << "Dias de cesantia acumuladas: " << calcularCesantia(fechaPago) << endl;
	 p << "-----------FIN-----------" << endl;
	 return p.str();


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
	delete empleado;
}
