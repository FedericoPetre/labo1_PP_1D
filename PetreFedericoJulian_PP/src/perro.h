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


#endif /* PERRO_H_ */
