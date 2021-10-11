/*
 * nexusPerroYEstadias.c
 *
 *  Created on: 9 oct. 2021
 *      Author: Owner
 */

#include "nexusPerroYEstadias.h"

/**
 * @fn EstadiaDiaria nexusPerroYEstadias_reservarEstadia(int, char*, int, int, Fecha)
 * @brief Reservar una estadia en la guarderia de perros
 *
 * @param id ID de la estadia
 * @param nombreDuenio Nombre del duenio del perro
 * @param telefono telefono de contacto del duenio
 * @param idPerro ID del perro a ser cuidado
 * @param fecha Fecha de la estadia
 * @return Retorna una estadia reservada con los datos anteriores
 */
EstadiaDiaria nexusPerroYEstadias_reservarEstadia(int id, char* nombreDuenio, int telefono, int idPerro, Fecha fecha)
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

/**
 * @fn int nexusPerroYEstadias_AltaEstadia(EstadiaDiaria*, int, int, perro*, int)
 * @brief Para dar de alta una estadia (reservarla), pidiendo todos los datos al usuario
 *
 * @param estadias listado de estadias, donde se registrara la nueva estadia
 * @param cantidadEstadias longitud de la lista
 * @param idEstadia ID de la estadia a ser reservada
 * @param perritos listado de perritos, se mostrara los IDS de los perritos a cuidar
 * @param cantidadPerritos longitud del listadod de perritos
 * @return Retorna 0 si se logro registrar la estadia exitosamente. -1 si los parametros son invalidos o el usuario decide no registrar la estadia
 */
int nexusPerroYEstadias_AltaEstadia(EstadiaDiaria* estadias, int cantidadEstadias, int idEstadia, perro* perritos, int cantidadPerritos)
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
			funcionesInputs_pedirYValidarEntero("Ingrese telefono de contacto (celular)(min: 1500000000 - max: 1600000000)\n ", "Error, reingrese telefono de contacto (celular)(min: 1500000000 - max: 1600000000)\n ", 1500000000, 1600000000, &telefonoAux);
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

			estadias[estadiaDisponible] = nexusPerroYEstadias_reservarEstadia(idEstadia, nombreAux, telefonoAux, idPerroAux, fechaAux);
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
				estadias[estadiaDisponible].estadoReserva = VACIO;
				printf("Se ha cancelado la reserva de estadia\n");
				retorno = -1;
			}
		}

	}
	return retorno;
}

/**
 * @fn int nexusPerroYEstadias_modificarEstadia(EstadiaDiaria*, int, perro*, int)
 * @brief Para modificar los datos de una estadia
 *
 * @param estadias listado de las estadias (Se busca la estadia a modificar por ID)
 * @param cantidadEstadias longitud de la lista
 * @param perritos listado de los perritos (se podra modificar uno de estos perritos si el usuario lo decide)
 * @param cantidadPerritos longitud de la lista
 * @return Retorna -1 en caso de parametros invalidos o el usuario decidio no modificar la estadia. 0 en caso de modificarla con exito
 */
int nexusPerroYEstadias_modificarEstadia(EstadiaDiaria* estadias, int cantidadEstadias, perro* perritos, int cantidadPerritos)
{
	int retorno = -1;
	int idEstadiaAux;
	int indiceEstadiaAux;
	int opcion;
	int telefonoAux;
	int idPerroAux;
	int indicePerroAux;
	char respuesta;

	if(estadias != NULL && cantidadEstadias > 0 && perritos != NULL && cantidadPerritos > 0)
	{
		printf("Mostrando IDS de estadias\n");
		estadiaDiaria_mostrarIDS(estadias, cantidadEstadias);
		funcionesInputs_pedirYValidarEntero("\nIngrese ID de la estadia a modificar\n", "Error, reingrese ID de la estadia a modificar\n", 100000, 150000, &idEstadiaAux);

		indiceEstadiaAux = estadiaDiaria_encontrarEstadiaPorID(estadias, cantidadEstadias, idEstadiaAux);

		if(indiceEstadiaAux != -1)
		{
			funcionesInputs_pedirYValidarEntero("Ingrese opcion:\n1- Modificar telefono de contacto\n2- Modificar perro\n", "Error, reingrese opcion: (1 o 2)\n1- Modificar telefono de contacto\n2- Modificar perro\n", 1, 2, &opcion);

			switch(opcion)
			{
				case 1:
					printf("Has elejido la opcion 1- Modificar telefono de contacto\n");
					funcionesInputs_pedirYValidarEntero("Ingrese nuevo telefono de contacto (celular)(1500000000 - 1600000000)\n ", "Error, reingrese nuevo telefono de contacto (celular)(1500000000 - 1600000000)\n ", 1500000000, 1600000000, &telefonoAux);
					funcionesInputs_pedirYValidarCaracter("Esta seguro que desea modificar el telefono de contacto?(s/n)\n", "Error, esta seguro que desea modificar el telefono de contacto?(s/n)\n", &respuesta);
					if(respuesta == 's')
					{
						estadias[indiceEstadiaAux].telefonoContacto = telefonoAux;
						printf("Telefono de contacto modificado exitosamente\n");
					}
					else
					{
						printf("se ha cancelado la modifcacion de datos\n");
					}
					break;
				case 2:
					printf("Has elejido la opcion 2- Modificar perro\n");
					perro_mostrarIdPerros(perritos, cantidadPerritos);
					funcionesInputs_pedirYValidarEnteroSinRango("\nIngrese el ID del nuevo perro a cuidar\n", "Error, reingrese el ID del nuevo perro a cuidar (numérico)\n", &idPerroAux);
					indicePerroAux = perro_encontrarPerroPorID(perritos, cantidadPerritos, idPerroAux);
					while(indicePerroAux == -1)
					{
						perro_mostrarIdPerros(perritos, cantidadPerritos);
						funcionesInputs_pedirYValidarEnteroSinRango("\nError ingrese el ID del perro a cuidar\n", "Error, reingrese el ID del perro a cuidar (numérico)\n", &idPerroAux);
						indicePerroAux = perro_encontrarPerroPorID(perritos, cantidadPerritos, idPerroAux);
					}

					funcionesInputs_pedirYValidarCaracter("Esta seguro que desea modificar el perro?(s/n)\n", "Error, esta seguro que desea modificar el perro?(s/n)\n", &respuesta);
					if(respuesta == 's')
					{
						estadias[indiceEstadiaAux].idPerro = idPerroAux;
						printf("Perro modificado exitosamente\n");
					}
					else
					{
						printf("se ha cancelado la modifcacion del perro\n");
					}
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



