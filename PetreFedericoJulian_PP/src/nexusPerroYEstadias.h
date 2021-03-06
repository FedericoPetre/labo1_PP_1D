/*
 * nexusPerroYEstadias.h
 *
 *  Created on: 9 oct. 2021
 *      Author: Federico Petre
 */

#ifndef NEXUSPERROYESTADIAS_H_
#define NEXUSPERROYESTADIAS_H_

#include "estadiaDiaria.h"
#include "perro.h"
#include "Duenio.h"

EstadiaDiaria nexusPerroYEstadias_reservarEstadia(int id, char* nombreDuenio, int telefono, int idPerro, Fecha fecha);
int nexusPerroYEstadias_AltaEstadia(EstadiaDiaria* estadias, int cantidadEstadias, int idEstadia, perro* perritos, int cantidadPerritos, Duenio* duenios, int cantidadDuenios);
int nexusPerroYEstadias_modificarEstadia(EstadiaDiaria* estadias, int cantidadEstadias, perro* perritos, int cantidadPerritos);
int nexusPerroYEstadias_contarEstadiasPerro(EstadiaDiaria* estadias, int cantidadEstadias, perro perrito);
int nexusPerroYEstadias_encontrarYMostrarPerroConMasEstadias(EstadiaDiaria* estadias, int cantidadEstadias, perro* perritos, int cantidadPerritos);
int nexusPerroYEstadias_mostrarEstadiaPorIDPerro(EstadiaDiaria* estadias, int cantidadEstadias, int idPerro);
int nexusPerroYEstadias_listarEstadiasPerros(EstadiaDiaria* estadias, int cantidadEstadias, perro* perritos, int cantidadPerritos);



#endif /* NEXUSPERROYESTADIAS_H_ */
