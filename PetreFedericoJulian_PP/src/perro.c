/*
 * perro.c
 *
 *  Created on: 8 oct. 2021
 *      Author: Federico Petre
 */

#include "perro.h"
/**
 * @fn perro perro_cargarPerro(int, char*, char*, int)
 * @brief Para cargar un perrito
 *
 * @param id Id del perrito a cargar
 * @param nombre Nombre del perrito
 * @param raza Raza del perrito
 * @param edad Edad del perrito
 * @return Retorna el perrito cargado con los parámetros anteriores
 */
perro perro_cargarPerro(int id, char* nombre, char* raza, int edad)
{
	perro perroAux;

	if(nombre != NULL && raza != NULL)
	{
		perroAux.id = id;
		strcpy(perroAux.nombre, nombre);
		strcpy(perroAux.raza, raza);
		perroAux.edad = edad;
		perroAux.banderaPerro = OCUPADO;
	}

	return perroAux;
}

/**
 * @fn int perro_mostrarPerros(perro*, int)
 * @brief Muestra todos los perritos cargados de una lista
 *
 * @param perritos lista de perritos
 * @param cantidadPerritos cantidad de perritos de la lista (incluye todos, cargados y no cargados)
 * @return Retorna -1 si la lista esta vacia o la cantidad de perritos es no valida. En caso de poder mostrarlos retorna 0
 */
int perro_mostrarPerros(perro* perritos, int cantidadPerritos)
{
	int retorno = -1;
	int i;

	if(perritos != NULL && cantidadPerritos >0)
	{
		printf("%-22s %-22s %-22s %-22s\n", "ID", "NOMBRE", "RAZA", "EDAD");
		for(i=0; i<cantidadPerritos; i++)
		{
			if(perritos[i].banderaPerro == OCUPADO)
			{
				printf("%-22d %-22s %-22s %-22d\n", perritos[i].id, perritos[i].nombre, perritos[i].raza, perritos[i].edad);
				retorno = 0;
			}

		}

	}
	return retorno;
}

/**
 * @fn int perro_encontrarPerroPorID(perro*, int, int)
 * @brief Para encontrar la posicion de la lista en donde se encuentra el perrito buscado por ID
 *
 * @param perritos Lista de todos los perritos
 * @param cantidadPerritos Longitud de la lista
 * @param id ID del perrito que esta siendo buscado
 * @return Retorna -1 en caso de no encontrar el perrito o parametros ingresados son inválidos. En caso de encontrarlo retorna la posicion de la lista en la que se encuentra el perrito.
 */
int perro_encontrarPerroPorID(perro* perritos, int cantidadPerritos, int id)
{
	int indiceEncontrado = -1;
	int i;

	if(perritos != NULL && cantidadPerritos > 0)
	{
		for(i=0; i<cantidadPerritos; i++)
		{
			if(perritos[i].id == id && perritos[i].banderaPerro == OCUPADO)
			{
				indiceEncontrado = i;
				break;
			}
		}

	}
	return indiceEncontrado;
}

/**
 * @fn int perro_mostrarIdPerros(perro*, int)
 * @brief Para mostar los ids de los perritos en una linea.
 *
 * @param perritos lista de los perritos
 * @param cantidadPerritos Longitud de la lista.
 * @return Retorna -1 en caso de que el ingreso de los parametros es inválido. En caso de que pueda mostrarlos retorna 0.
 */
int perro_mostrarIdPerros(perro* perritos, int cantidadPerritos)
{
	int retorno = -1;
	int i;

	if(perritos != NULL && cantidadPerritos > 0)
	{
		printf("Mostrando IDS de los Perros...\n");
		for(i=0; i<cantidadPerritos; i++)
		{
			if(perritos[i].banderaPerro == OCUPADO)
			{
				printf("%d- ", perritos[i].id);
				retorno = 0;
			}
		}
	}
	return retorno;
}

/**
 * @fn int perro_modificarPerro(perro*, int, int)
 * @brief Para modificar los datos de un perrito ya cargado
 *
 * @param perritos Listado de perritos, se busca el perrito a ser modificado por ID.
 * @param cantidadPerritos Longitud de la lista de perritos.
 * @param idPerro ID del perrito a ser modificado (si es que se encuentra en la lista).
 * @return Retorna -1 en caso de que los parametros ingresados son invalidos o que el perrito no se encontro para modificar. Retorna 0 en caso contrario.
 */
int perro_modificarPerro(perro* perritos, int cantidadPerritos, int idPerro)
{
	int retorno = -1;
	int indicePerro;
	char nombrePerroAux[21];
	char razaPerroAux[21];
	int edadPerroAux;

	if(perritos != NULL && cantidadPerritos > 0)
	{
		indicePerro = perro_encontrarPerroPorID(perritos, cantidadPerritos, idPerro);

		if(indicePerro != -1)
		{
			printf("Ingresando a la modificacion del perro...\n");

			funcionesInputs_pedirYValidarCadena("Ingrese nuevo nombre del perro (max 21 caracteres)\n", "Error, reingrese nuevo nombre del perro (max 21 caracteres)\n", 21, nombrePerroAux);
			funcionesInputs_pedirYValidarCadena("Ingrese nueva raza del perro (max 21 caracteres)\n", "Error, reingrese nueva raza del perro (max 21 caracteres)\n", 21, razaPerroAux);
			funcionesInputs_pedirYValidarEntero("Ingrese nueva edad del perro (min: 0, max: 20)\n", "Error, reingrese nueva edad del perro (min: 0, max: 20)\n", 0, 20, &edadPerroAux);
			perritos[indicePerro] = perro_cargarPerro(idPerro, nombrePerroAux, razaPerroAux, edadPerroAux);
			retorno = 0;

		}
		else
		{
			retorno = -1;
		}
	}
	return retorno;
}

