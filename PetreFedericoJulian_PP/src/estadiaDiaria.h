/*
 * estadiaDiaria.h
 *
 *  Created on: 8 oct. 2021
 *      Author: Federico Petre
 */

#ifndef ESTADIADIARIA_H_
#define ESTADIADIARIA_H_

#include "funcionesInputs.h"
#include "perro.h"
#include "Duenio.h"

#define OCUPADA 1
#define DISPONIBLE 0
#define CANTESTADIAS 10

typedef struct{
	int dia;
	int mes;
	int anio;
} Fecha;

typedef struct{
	int id;
	Duenio Duenio;
	int idPerro;
	Fecha fecha;
	int estadoReserva;

} EstadiaDiaria;

int estadiaDiaria_inicializarEstadias(EstadiaDiaria* estadias, int cantidadEstadias);
int estadiaDiaria_encontrarEstadiaVacia(EstadiaDiaria* estadias, int cantidadEstadias);
Fecha estadiaDiaria_registrarFecha(void);
int estadiaDiaria_mostrarEstadia(EstadiaDiaria estadia);
int estadiaDiaria_listarEstadias(EstadiaDiaria* estadias, int cantidadEstadias);
int estadiaDiaria_encontrarEstadiaPorID(EstadiaDiaria* estadias, int cantidadEstadias, int id);
int estadiaDiaria_mostrarIDS(EstadiaDiaria* estadias, int cantidadEstadias);
int estadiaDiaria_bajaEstadia(EstadiaDiaria* estadias, int cantidadEstadias);
int estadiaDiaria_compararFechas(Fecha fecha1, Fecha fecha2);
int estadiaDiaria_ordenarEstadiasPorFecha(EstadiaDiaria* estadias, int cantidadEstadias);
int estadiaDiaria_encontrarPerroPorIDEnEstadia(EstadiaDiaria* estadias, int cantidadEstadias, int idPerro);





#endif /* ESTADIADIARIA_H_ */
