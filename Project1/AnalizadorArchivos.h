#pragma once

#include"ListaContrato.h"
#include "Planilla.h"
#include "ServiciosProfesionales.h"
#include "Contrato.h"
#include"ListaPuestos.h"
#include <stdlib.h>
using namespace std;
class AnalizadorArchivos
{
public:
	static void ingresarPuestos(ListaPuestos*);
	static void ingresarEmpleados(ListaContratos*, ListaPuestos*);
};
