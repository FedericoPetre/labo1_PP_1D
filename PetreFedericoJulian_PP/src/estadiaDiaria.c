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
	char respuesta;

	if(estadias != NULL && cantidadEstadias > 0)
	{
		estadiaDisponible = estadiaDiaria_encontrarEstadiaVacia(estadias, cantidadEstadias);

		if(estadiaDisponible != -1)
		{
			funcionesInputs_pedirYValidarCadena("Ingrese nombre del duenio (max 30 caracteres sin espacios)\n", "Error, reingrese nombre del duenio (max 30 caracteres sin espacios)\n", 30, nombreAux);
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
			printf("%-20s %-20s %-25s %-15s %-25s\n", "ID RESERVA", "NOMBRE DUENIO", "TELEFONO DE CONTACTO", "ID PERRO", "FECHA DE RESERVA");
			estadiaDiaria_mostrarEstadia(estadias[estadiaDisponible]);
			funcionesInputs_pedirYValidarCaracter("Esta estadia se ingresara en el sistema\nEsta de acuerdo? (s/n)\n", "Error, esta estadia se ingresara en el sistema\nEsta de acuerdo? (s:si/n:no)(Ingrese caracter\n)", &respuesta);

			if(respuesta == 's')
			{
				retorno = 0;
			}
			else
			{
				retorno = -1;
			}
		}

	}
	return retorno;
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


