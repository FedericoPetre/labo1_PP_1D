/*
 * perro.c
 *
 *  Created on: 8 oct. 2021
 *      Author: Federico Petre
 */

#include "perro.h"

perro perro_hardcodearPerro(int id, char* nombre, char* raza, int edad)
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

int perro_encontrarPerroPorID(perro* perritos, int cantidadPerritos, int id)
{
	int indiceEncontrado = -1;
	int i;

	if(perritos != NULL && cantidadPerritos > 0)
	{
		for(i=0; i<cantidadPerritos; i++)
		{
			if(perritos[i].id == id)
			{
				indiceEncontrado = i;
				break;
			}
		}

	}
	return indiceEncontrado;
}

