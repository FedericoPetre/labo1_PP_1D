/*
 * nexusPerroYEstadias.h
 *
 *  Created on: 9 oct. 2021
 *      Author: Owner
 */

#ifndef NEXUSPERROYESTADIAS_H_
#define NEXUSPERROYESTADIAS_H_

#include "estadiaDiaria.h"
#include "perro.h"

EstadiaDiaria nexusPerroYEstadias_reservarEstadia(int id, char* nombreDuenio, int telefono, int idPerro, Fecha fecha, perro* perritos, int cantidadPerritos);
int nexusPerroYEstadias_registrarReserva(EstadiaDiaria* estadias, int cantidadEstadias, int idEstadia, perro* perritos, int cantidadPerritos);
int nexusPerroYEstadias_modificarEstadia(EstadiaDiaria* estadias, int cantidadEstadias, perro* perritos, int cantidadPerritos);



#endif /* NEXUSPERROYESTADIAS_H_ */
