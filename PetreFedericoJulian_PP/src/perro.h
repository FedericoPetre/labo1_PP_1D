/*
 * perro.h
 *
 *  Created on: 8 oct. 2021
 *      Author: Federico Petre
 */

#ifndef PERRO_H_
#define PERRO_H_

#define VACIO 0
#define OCUPADO 1

#include "funcionesInputs.h"

typedef struct {
	int id;
	char nombre[21];
	char raza[21];
	int edad;
	int banderaPerro;
} perro;

perro perro_cargarPerro(int id, char* nombre, char* raza, int edad);
int perro_mostrarPerros(perro* perritos, int cantidadPerritos);
int perro_encontrarPerroPorID(perro* perritos, int cantidadPerritos, int id);
int perro_mostrarIdPerros(perro* perritos, int cantidadPerritos);
int perro_modificarPerro(perro* perritos, int cantidadPerritos, int idPerro);

#endif /* PERRO_H_ */
