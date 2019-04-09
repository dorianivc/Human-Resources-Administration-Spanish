#include "Fecha.h"



Fecha::Fecha(int d, int m, int a)
{
	this->d = d;
	this->m = m;
	this->a = a;
}

Fecha::Fecha(Fecha *p)
{
	d = p->getDia();
	m = p->getMes();
	a = p->getAno();
}

int Fecha::getDia()
{
	return d;
}

void Fecha::setDia(int dd)
{
	d = dd;
}

int Fecha::getMes()
{
	return m;
}

void Fecha::setMes(int mm)
{
	m = mm;
}

int Fecha::getAno()
{
	return a;
}

void Fecha::setAno(int aa)
{
	a = aa;

}

tm Fecha::FechaATm(Fecha const & fecha)
{
	{
		return { 0,0,0,fecha.d,fecha.m - 1,fecha.a - 1900 };
	}
}

int Fecha::Distancia(Fecha * f1, Fecha * f2)
{
	{
		int toReturn = 0;
		const Fecha f(f1->getDia(), f1->getMes(), f1->getAno());
		const Fecha f1(f2->getDia(), f2->getMes(), f2->getAno());
		std::tm tm1 = FechaATm(f);
		std::tm tm2 = FechaATm(f1);
		std::time_t x = std::mktime(&tm1);
		std::time_t y = std::mktime(&tm2);

		if (x != static_cast<std::time_t>(-1) && y != static_cast<std::time_t>(-1))
		{
			toReturn = static_cast<int>(std::difftime(y, x)) / (60 * 60 * 24);
		}

		return toReturn;
	}
}

string Fecha::toStringFecha()
{
	stringstream p;
	p << d << "/" << m << "/" << a;
	return p.str();
}


Fecha::~Fecha()
{
}
