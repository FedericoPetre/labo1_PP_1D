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
	printf("Ingresando fecha...\n");
	funcionesInputs_pedirYValidarEntero("Ingrese dia (1-31)", "Error, ingrese dia (1-31)", 1, 31, &fechaIngresada.dia);
	funcionesInputs_pedirYValidarEntero("Ingrese mes (1-12)", "Error, ingrese mes (1-12)", 1, 12, &fechaIngresada.mes);
	funcionesInputs_pedirYValidarEntero("Ingrese anio (2021-2030)", "Error, anio (2021-2030)", 2021, 2030, &fechaIngresada.anio);

	return fechaIngresada;
}

EstadiaDiaria estadiaDiaria_reservarEstadia(int id, char* nombreDuenio, int telefono, int idPerro, Fecha fecha, perro* perritos, int cantidadPerritos)
{
	EstadiaDiaria estadia;

	if(id>99999 && nombreDuenio != NULL)
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

int estadiaDiaria_registrarReserva(EstadiaDiaria* estadias, int cantidadEstadias, int idEstadia, perro* perritos, int cantidadPerritos)
{
	int retorno = -1;
	int estadiaDisponible;
	char nombreAux[30];
	int telefonoAux;
	int idPerroAux;
	int indicePerro;
	Fecha fechaAux;

	if(estadias != NULL && cantidadEstadias > 0)
	{
		estadiaDisponible = estadiaDiaria_encontrarEstadiaVacia(estadias, cantidadEstadias);

		if(estadiaDisponible != -1)
		{
			funcionesInputs_pedirYValidarCadena("Ingrese nombre del duenio (max 30 caracteres)\n", "Error, reingrese nombre del duenio (max 30 caracteres)\n", 30, nombreAux);
			funcionesInputs_pedirYValidarEntero("Ingrese telefono de contacto (celular)(1500000000 - 1600000000)\n ", "Error, reingrese telefono de contacto (celular)(1500000000 - 1600000000)\n ", 1500000000, 1600000000, &telefonoAux);
			perro_mostrarIdPerros(perritos, cantidadPerritos);
			funcionesInputs_pedirYValidarEnteroSinRango("\nIngrese el ID del perro a cuidar\n", "Error, reingrese el ID del perro a cuidar (numérico)\n", &idPerroAux);
			indicePerro = perro_encontrarPerroPorID(perritos, cantidadPerritos, idPerroAux);
			while(indicePerro == -1)
			{
				perro_mostrarIdPerros(perritos, cantidadPerritos);
				funcionesInputs_pedirYValidarEnteroSinRango("\nError ingrese el ID del perro a cuidar\n", "Error, reingrese el ID del perro a cuidar (numérico)\n", &idPerroAux);
				indicePerro = perro_encontrarPerroPorID(perritos, cantidadPerritos, idPerroAux);
			}
			fechaAux = estadiaDiaria_registrarFecha();

			estadias[estadiaDisponible] = estadiaDiaria_reservarEstadia(idEstadia, nombreAux, telefonoAux, idPerroAux, fechaAux, perritos, cantidadPerritos);
		}

		retorno = 0;
	}
	return retorno;
}


