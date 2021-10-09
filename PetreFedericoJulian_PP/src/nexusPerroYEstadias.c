/*
 * nexusPerroYEstadias.c
 *
 *  Created on: 9 oct. 2021
 *      Author: Owner
 */

#include "nexusPerroYEstadias.h"

EstadiaDiaria nexusPerroYEstadias_reservarEstadia(int id, char* nombreDuenio, int telefono, int idPerro, Fecha fecha, perro* perritos, int cantidadPerritos)
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

int nexusPerroYEstadias_registrarReserva(EstadiaDiaria* estadias, int cantidadEstadias, int idEstadia, perro* perritos, int cantidadPerritos)
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

			estadias[estadiaDisponible] = nexusPerroYEstadias_reservarEstadia(idEstadia, nombreAux, telefonoAux, idPerroAux, fechaAux, perritos, cantidadPerritos);
			printf("%-20s %-20s %-25s %-15s %-25s\n", "ID RESERVA", "NOMBRE DUENIO", "TELEFONO DE CONTACTO", "ID PERRO", "FECHA DE RESERVA");
			estadiaDiaria_mostrarEstadia(estadias[estadiaDisponible]);
			funcionesInputs_pedirYValidarCaracter("Esta estadia se ingresara en el sistema\nEsta de acuerdo? (s/n)\n", "Error, esta estadia se ingresara en el sistema\nEsta de acuerdo? (s:si/n:no)(Ingrese caracter\n)", &respuesta);

			if(respuesta == 's')
			{
				printf("Estadia reservada con exito\n");
				retorno = 0;
			}
			else
			{
				printf("Se ha cancelado la reserva de estadia\n");
				retorno = -1;
			}
		}

	}
	return retorno;
}

int nexusPerroYEstadias_modificarEstadia(EstadiaDiaria* estadias, int cantidadEstadias, perro* perritos, int cantidadPerritos)
{
	int retorno = -1;
	int idEstadiaAux;
	int indiceEstadiaAux;
	int opcion;
	int telefonoAux;

	if(estadias != NULL && cantidadEstadias > 0 && perritos != NULL && cantidadPerritos > 0)
	{
		printf("Mostrando IDS de estadias\n");
		estadiaDiaria_mostrarIDS(estadias, cantidadEstadias);
		funcionesInputs_pedirYValidarEntero("\nIngrese ID de la estadia a modificar\n", "Error, reingrese ID de la estadia a modificar\n", 100000, 150000, &idEstadiaAux);

		indiceEstadiaAux = estadiaDiaria_encontrarEstadiaPorID(estadias, cantidadEstadias, idEstadiaAux);

		if(indiceEstadiaAux != -1)
		{
			funcionesInputs_pedirYValidarEntero("Ingrese opcion:\n1- Modificar telefono de contacto\n2- Modificar datos del perro\n", "Error, reingrese opcion: (1 o 2)\n1- Modificar telefono de contacto\n2- Modificar datos del perro\n", 1, 2, &opcion);

			switch(opcion)
			{
				case 1:
					printf("Has elejido la opcion 1- Modificar telefono de contacto\n");
					funcionesInputs_pedirYValidarEntero("Ingrese nuevo telefono de contacto (celular)(1500000000 - 1600000000)\n ", "Error, reingrese nuevo telefono de contacto (celular)(1500000000 - 1600000000)\n ", 1500000000, 1600000000, &telefonoAux);
					estadias[indiceEstadiaAux].telefonoContacto = telefonoAux;
					printf("Telefono de contacto modificado exitosamente\n");
					break;
				case 2:
					printf("Has elejido la opcion 2- Modificar datos del perro\n");
					perro_modificarPerro(perritos, cantidadPerritos, estadias[indiceEstadiaAux].idPerro);
					printf("Datos del perro modificados con exito\n");
					break;
			}
		}
		else
		{
			printf("Error, no se encontro la estadia\n");
		}
	}
	return retorno;
}

