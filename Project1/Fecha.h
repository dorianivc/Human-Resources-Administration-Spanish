#pragma once
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
using namespace std;

class Fecha
{private:
	int d, m, a;
public:
	Fecha(int, int, int);
	Fecha(Fecha*);
	int getDia();
	void setDia(int);
	int getMes();
	void setMes(int);
	int getAno();
	void setAno(int);
	tm FechaATm(Fecha const& );
	
	int Distancia(Fecha * f1, Fecha* f2);
	string toStringFecha();


	~Fecha();
};

