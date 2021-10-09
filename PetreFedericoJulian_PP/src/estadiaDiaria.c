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

Fecha estadiaDiaria_registrarFecha(void)
{
	Fecha fechaIngresada;
	printf("Ingrese fecha a reservar estadia...\n");
	funcionesInputs_pedirYValidarEntero("Ingrese dia (1-31)", "Error, ingrese dia (1-31)", 1, 31, &fechaIngresada.dia);
	funcionesInputs_pedirYValidarEntero("Ingrese mes (1-12)", "Error, ingrese mes (1-12)", 1, 12, &fechaIngresada.mes);
	funcionesInputs_pedirYValidarEntero("Ingrese anio (2021-2030)", "Error, anio (2021-2030)", 2021, 2030, &fechaIngresada.anio);

	return fechaIngresada;
}

int estadiaDiaria_mostrarEstadia(EstadiaDiaria estadia)
{
	int retorno = -1;
	if(estadia.estadoReserva == OCUPADO)
	{
		printf("%-20d %-20s %-25d %-15d %-2d/%-2d/%-5d\n", estadia.id, estadia.nombreDuenio, estadia.telefonoContacto, estadia.idPerro, estadia.fecha.dia, estadia.fecha.mes, estadia.fecha.anio);
		retorno = 0;
	}
	return retorno;
}

int estadiaDiaria_mostrarEstadias(EstadiaDiaria* estadias, int cantidadEstadias)
{
	int retorno = -1;
	int i;

	if(estadias != NULL && cantidadEstadias > 0)
	{
		for(i=0; i<cantidadEstadias; i++)
		{
			if(i==0)
			{
				printf("%-20s %-20s %-25s %-15s %-25s\n", "ID RESERVA", "NOMBRE DUENIO", "TELEFONO DE CONTACTO", "ID PERRO", "FECHA DE RESERVA");
			}
			retorno = estadiaDiaria_mostrarEstadia(estadias[i]);

		}
	}
	else
	{
		printf("Error al mostrar las estadias\n");
	}
	return retorno;
}

/**
 * @fn int estadiaDiaria_encontrarEstadiaPorID(EstadiaDiaria*, int, int)
 * @brief Busca la estadia que tenga el mismo id que se ingresa
 *
 * @param estadias Listado de todas las estadias registradas
 * @param cantidadEstadias cantidad maxima de estadias que pueden registrarse
 * @param id ID de la estadia buscada
 * @return Retorna -1 en caso de no encontrar la estadia. Si la encuentra retorna la posicion en que se encuentra la estadia en la lista
 */
int estadiaDiaria_encontrarEstadiaPorID(EstadiaDiaria* estadias, int cantidadEstadias, int id)
{
	int indiceEncontrado = -1;
	int i;

	if(estadias != NULL && cantidadEstadias > 0)
	{
		for(i=0; i<cantidadEstadias; i++)
		{
			if(estadias[i].estadoReserva == OCUPADO && estadias[i].id == id)
			{
				indiceEncontrado = i;
				break;
			}
		}
	}
	return indiceEncontrado;
}

int estadiaDiaria_mostrarIDS(EstadiaDiaria* estadias, int cantidadEstadias)
{
	int retorno = -1;
	int i;
	if(estadias != NULL && cantidadEstadias > 0)
	{
		for(i=0; i<cantidadEstadias; i++)
		{
			if(estadias[i].estadoReserva == OCUPADO)
			{
				printf("%d -", estadias[i].id);
				retorno = 0;
			}
		}
	}
	return retorno;
}

int estadiaDiaria_cancelarEstadia(EstadiaDiaria* estadias, int cantidadEstadias)
{
	int retorno = -1;
	int idEstadiaAux;
	int indiceEstadiaAux;

	if(estadias != NULL && cantidadEstadias > 0)
	{
		printf("Mostrando IDS de estadias\n");
		estadiaDiaria_mostrarIDS(estadias, cantidadEstadias);
		funcionesInputs_pedirYValidarEntero("\nIngrese ID de la estadia a cancelar\n", "Error, reingrese ID de la estadia a cancelar\n", 100000, 150000, &idEstadiaAux);

		indiceEstadiaAux = estadiaDiaria_encontrarEstadiaPorID(estadias, cantidadEstadias, idEstadiaAux);

		if(indiceEstadiaAux != -1)
		{
			estadias[indiceEstadiaAux].estadoReserva = VACIO;
			retorno = 0;
			printf("La estadia ha sido cancelada con exito\n");

		}
		else
		{
			printf("Error, no se encontro la estadia\n");
		}
	}
	return retorno;
}






