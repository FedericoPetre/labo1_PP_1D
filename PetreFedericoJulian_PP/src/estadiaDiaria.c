/*
 * estadiaDiaria.c
 *
 *  Created on: 8 oct. 2021
 *      Author: Owner
 */

#include "estadiaDiaria.h"

int estadiaDiaria_inicializarEstadias(EstadiaDiaria* estadias, int cantidadEstadias)
{
	int retorno = -1;
	int i;

	if(estadias != NULL && cantidadEstadias > 0)
	{
		for(i=0; i<cantidadEstadias; i++)
		{
			estadias[i].estadoReserva = VACIO;
		}
		retorno = 0;
	}
	return retorno;
}

int estadiaDiaria_encontrarEstadiaVacia(EstadiaDiaria* estadias, int cantidadEstadias)
{
	int indiceEstadiaVacia=-1;
	int i;

	if(estadias != NULL && cantidadEstadias > 0)
	{
		for(i=0; i<cantidadEstadias; i++)
		{
			if(estadias[i].estadoReserva == VACIO)
			{
				indiceEstadiaVacia = i;
				break;
			}
		}
	}
	return indiceEstadiaVacia;
}

Fecha estadiaDiaria_registrarFecha(Fecha fechaIngresada)
{
	funcionesInputs_pedirYValidarEntero("Ingrese dia del mes (1-31)", "Error, ingrese dia del mes (1-31)", 1, 31, &fechaIngresada.dia);
	funcionesInputs_pedirYValidarEntero("Ingrese mes del anio (1-12)", "Error, ingrese mes del (1-12)", 1, 12, &fechaIngresada.mes);
	funcionesInputs_pedirYValidarEntero("Ingrese anio (2021-2030)", "Error, anio (2021-2030)", 2021, 2030, &fechaIngresada.anio);

	return fechaIngresada;
}

EstadiaDiaria estadiaDiaria_reservarEstadia(int id, char* nombreDuenio, int telefono, int idPerro, Fecha fecha, perro* perritos, int cantidadPerritos)
{
	EstadiaDiaria estadia;
	int indicePerro;

	indicePerro = perro_encontrarPerroPorID(perritos, cantidadPerritos, idPerro);

	if(id>99999 && nombreDuenio != NULL && indicePerro != -1)
	{
		estadia.id = id;
		strcpy(estadia.nombreDuenio, nombreDuenio);
		estadia.telefonoContacto = telefono;
		estadia.idPerro = idPerro;
		estadia.fecha = fecha;
		estadia.estadoReserva = OCUPADO;
	}
	return estadia;
}

int estadiaDiaria_registrarReserva(EstadiaDiaria* estadias, int cantidadEstadias, int idEstadia)
{
	int retorno = -1;
	int estadiaDisponible;
	char nombreAux[30];

	if(estadias != NULL && cantidadEstadias > 0)
	{
		estadiaDisponible = estadiaDiaria_encontrarEstadiaVacia(estadias, cantidadEstadias);

		if(estadiaDisponible != -1)
		{
			funcionesInputs_pedirYValidarCadena("Ingrese nombre del duenio (max 30 caracteres)", "Error, reingrese nombre del duenio (max 30 caracteres)", 30, nombreAux);

		}

		retorno = 0;
	}
	return retorno;
}


