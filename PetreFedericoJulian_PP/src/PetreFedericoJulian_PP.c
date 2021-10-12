/*
 ============================================================================
 Name        : PetreFedericoJulian_PP.c
 Author      : Federico Petre
 Version     :
 Copyright   : Y
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funcionesInputs.h"
#include "nexusPerroYEstadias.h"


int main(void) {
	setbuf(stdout, NULL);
	int opcion = -1;
	int contadorEstadias = 0;
	int idEstadia = 100000;
	int confirmacionReservaAltaCancelacion;

	EstadiaDiaria estadias[30];

	perro perros[CANTPERROS];

	perro_inicializarPerros(perros, CANTPERROS);
	perro_hardCodearPerros(perros, CANTPERROS);

	printf("Bienvenido a la guardería de perros\n");

	while(opcion != 7)
	{
		 funcionesInputs_pedirYValidarEntero("Elija una opcion (1-7):\n1- RESERVAR ESTADIA\n2- MODIFICAR ESTADIA\n3- CANCELAR ESTADIA\n4- LISTAR ESTADIAS\n5- LISTAR PERROS\n6- Promedio de edad de los perros\n7- SALIR\n", "Error, elija una opcion (1-7):\n1- RESERVAR ESTADIA\n2- MODIFICAR ESTADIA\n3- CANCELAR ESTADIA\n4- LISTAR ESTADIAS\n5- LISTAR PERROS\n6- Promedio de edad de los perros\n7- SALIR\n", 1, 7, &opcion);

		 switch(opcion)
		 {
			 case 1:
				 printf("Ha elejido la opcion 1- RESERVAR ESTADIA\n");
				 confirmacionReservaAltaCancelacion = nexusPerroYEstadias_AltaEstadia(estadias, CANTESTADIAS, idEstadia , perros, CANTPERROS);
				 contadorEstadias++;
				 idEstadia++;
				 if(confirmacionReservaAltaCancelacion == -1)
				 {
					 contadorEstadias--;
					 idEstadia--;
				 }
				 break;
			 case 2:
				 printf("Ha elejido la opcion 2- MODIFICAR ESTADIA\n");
				 if(contadorEstadias == 0)
				 {
					 printf("Error, primero hay que reservar una estadia\n");
				 }
				 else
				 {
					 nexusPerroYEstadias_modificarEstadia(estadias, CANTESTADIAS, perros, CANTPERROS);
				 }

				 break;
			 case 3:
				 printf("Ha elejido la opcion 3- CANCELAR ESTADIA\n");
				 if(contadorEstadias == 0)
				 {
					 printf("Error, primero hay que reservar una estadia\n");
				 }
				 else
				 {
					 confirmacionReservaAltaCancelacion = estadiaDiaria_bajaEstadia(estadias, CANTESTADIAS);
					 if(confirmacionReservaAltaCancelacion == 0)
					 {
						 contadorEstadias--;
					 }
				 }

				 break;
			 case 4:
				 printf("Ha elejido la opcion 4- LISTAR ESTADIAS\n");
				 if(contadorEstadias == 0)
				 {
					 printf("Error, primero hay que reservar una estadia\n");
				 }
				 else
				 {
					 estadiaDiaria_ordenarEstadiasPorFecha(estadias,CANTESTADIAS);
					 estadiaDiaria_listarEstadias(estadias,CANTESTADIAS);
				 }

				 break;
			 case 5:
				 printf("Ha elejido la opcion 5- LISTAR PERROS\n");
				 if(contadorEstadias == 0)
				 {
					 printf("Error, primero hay que reservar una estadia\n");
				 }
				 else
				 {
					 perro_listarPerros(perros, CANTPERROS);
				 }

				 break;
			 case 6:
				 printf("Ha elejido la opcion 6- Promedio de edad de los perros\n");
				 if(contadorEstadias == 0)
				 {
					 printf("Error, primero hay que reservar una estadia\n");
				 }
				 else
				 {
					 perro_mostrarPromedioDeEdad(perros, CANTPERROS);
				 }

				 break;
			 case 7:
				 printf("Ha elejido la opcion 7- SALIR\nSaliendo del sistema....\nHas salido del sistema\n");
				 break;
		 }

		 if(opcion != 7)
		 {
			 system("pause");
		 }

	}
	return EXIT_SUCCESS;
}
