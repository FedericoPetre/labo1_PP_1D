/*
 * estadiaDiaria.h
 *
 *  Created on: 8 oct. 2021
 *      Author: Federico Petre
 */

#ifndef ESTADIADIARIA_H_
#define ESTADIADIARIA_H_

#include "funcionesInputs.h"

#define OCUPADA 1
#define DISPONIBLE 0

typedef struct{
	int dia;
	int mes;
	int anio;
} Fecha;

typedef struct{
	int id;
	char nombreDuenio[51];
	int telefonoContacto;
	int idPerro;
	Fecha fecha;
	int estadoReserva;

} EstadiaDiaria;



#endif /* ESTADIADIARIA_H_ */
